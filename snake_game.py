__author__ = 'Abbigail Tang'
__contributor__ = 'Peter Bui'

"""
Date: January 19, 2024
File name: snake_game
Description: 
The Snake Game uses left, right, up, down arrows
to control the snake. Your objective is to eat as many apples
as possible! Please be aware that this is used through PyCharm.
"""
import pygame, pygame_menu, sys
from random import randrange

pygame.init()

SCREEN_SIZE = 600
UNIT = 30
screen = pygame.display.set_mode((SCREEN_SIZE, SCREEN_SIZE))
clock = pygame.time.Clock()

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
BLUE = (0, 0, 255)

snake_colour = WHITE  # Default color

the_range = (UNIT // 2, SCREEN_SIZE - UNIT // 2, UNIT)
get_random_position = lambda: [randrange(*the_range), randrange(*the_range)]

snake = pygame.Rect(0, 0, UNIT - 2, UNIT - 2)
snake.center = get_random_position()

apple = snake.copy()
apple.center = get_random_position()

segments = [snake.copy()]
length = 1
snake_direction = (0, 0)
time = 0
time_step = 110
top_score = 0


def choose_colour(_, color):
    global snake_colour
    snake_colour = color

def game_exit():
    pygame.quit()
    sys.exit()


def display_score():
    global length, segments, snake_direction, top_score

    top_score = max(top_score, length - 1)

    font = pygame.font.SysFont(None, 50)
    text = font.render(
        f'Score = {length - 1}  Top score = {top_score}',
        True,
        BLUE
    )

    screen.fill(BLACK)
    screen.blit(text, (80, 250))
    pygame.display.flip()
    pygame.time.delay(2000)

    snake.center = get_random_position()
    apple.center = get_random_position()
    length = 1
    segments = [snake.copy()]
    snake_direction = (0, 0)


def main_gameloop():
    global length, segments, snake_direction, time

    directions = {pygame.K_UP: 1, pygame.K_DOWN: 1,
                  pygame.K_LEFT: 1, pygame.K_RIGHT: 1}

    running = True
    while running:
        screen.fill(BLACK)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP and directions[pygame.K_UP]:
                    snake_direction = (0, -UNIT)
                    directions = {pygame.K_UP: 1, pygame.K_DOWN: 0,
                                  pygame.K_LEFT: 1, pygame.K_RIGHT: 1}
                if event.key == pygame.K_DOWN and directions[pygame.K_DOWN]:
                    snake_direction = (0, UNIT)
                    directions = {pygame.K_UP: 0, pygame.K_DOWN: 1,
                                  pygame.K_LEFT: 1, pygame.K_RIGHT: 1}
                if event.key == pygame.K_LEFT and directions[pygame.K_LEFT]:
                    snake_direction = (-UNIT, 0)
                    directions = {pygame.K_UP: 1, pygame.K_DOWN: 1,
                                  pygame.K_LEFT: 1, pygame.K_RIGHT: 0}
                if event.key == pygame.K_RIGHT and directions[pygame.K_RIGHT]:
                    snake_direction = (UNIT, 0)
                    directions = {pygame.K_UP: 1, pygame.K_DOWN: 1,
                                  pygame.K_LEFT: 0, pygame.K_RIGHT: 1}

        # Border or self collision
        if (snake.left < 0 or snake.right > SCREEN_SIZE or
                snake.top < 0 or snake.bottom > SCREEN_SIZE or
                snake.collidelist(segments[:-1]) != -1):
            display_score()

        # Apple eaten
        if snake.center == apple.center:
            # generate apple not on snake
            while True:
                apple.center = get_random_position()
                if apple.collidelist(segments) == -1:
                    break
            length += 1
        pygame.draw.rect(screen, RED, apple)

        for segment in segments:
            pygame.draw.rect(screen, snake_colour, segment)

        time_now = pygame.time.get_ticks()
        if time_now - time > time_step:
            time = time_now
            snake.move_ip(snake_direction)
            segments.append(snake.copy())
            segments = segments[-length:]

        pygame.display.flip()
        clock.tick(60)


# -------- MENU -------- #

menu = pygame_menu.Menu('Snake Game', SCREEN_SIZE, SCREEN_SIZE,
                        theme=pygame_menu.themes.THEME_DARK)

menu.add.selector(
    'Color :',
    [('White', WHITE),
    ('Purple', (204, 153, 255)),
    ('Green', (0, 255, 0)),
    ('Blue', BLUE),
    ('Pink', (255, 51, 153)),
    ('Yellow', (255, 255, 0)),
    ('Cyan', (0, 255, 255)),
    ('Magenta', (255, 0, 255))],
    onchange=choose_colour
)

menu.add.button('Play', main_gameloop)
menu.add.button('Exit', game_exit)

if __name__ == "__main__":
    menu.mainloop(screen)