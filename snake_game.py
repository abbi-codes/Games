__author__ = 'Abbigail Tang'

"""
Date: January 19, 2024
File name: snake_game
Description: 
The Snake Game uses left, right, up, down arrows
to control the snake. Your objective is to eat as many apples
as possible! Please be aware that this is used through PyCharm.
"""
import pygame
from pygame.locals import *
from random import randrange

SCREEN_SIZE = 600
UNIT = 30
the_range = (UNIT //2, SCREEN_SIZE - UNIT // 2, UNIT)
get_random_position = lambda:[randrange(*the_range), randrange(*the_range)]
snake = pygame.rect.Rect([0, 0, UNIT - 2, UNIT - 2])
snake.center = get_random_position()
length = 1
segments = [snake.copy()]
snake_direction = (0, 0)
time, time_step = 0, 110
apple = snake.copy()
apple.center = get_random_position()
clock = pygame.time.Clock()
directions = {pygame.K_UP: 1, pygame.K_DOWN: 1, pygame.K_LEFT: 1, pygame.K_RIGHT: 1}
top_score = 0
score = 0

# Colours
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
PURPLE = (204, 153, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)
PINK = (255, 51, 153)
YELLOW = (255, 255, 0)
CYAN = (0, 255, 255)
MAGENTA = (255, 0, 255)

def choose_colour(colour_num):
    """
    Determines the colour of the snake opted by user
    :param colour_num: a string
    :returns: colour that user chose
    """
    if colour_num == '1':
        return WHITE
    elif colour_num == '2':
        return PURPLE
    elif colour_num == '3':
        return GREEN
    elif colour_num == '4':
        return BLUE
    elif colour_num == '5':
        return PINK
    elif colour_num == '6':
        return YELLOW
    elif colour_num == '7':
        return CYAN
    else:
        return MAGENTA

print('Colours of snake you can choose: ')
print("1. White")
print("2. Purple")
print("3. Green")
print("4. Blue")
print("5. Pink")
print("6. Yellow")
print("7. Cyan")
print("8. Magenta")

chosen_colour = input('Enter the snake colour number: ')
snake_colour = choose_colour(chosen_colour)
screen = pygame.display.set_mode([SCREEN_SIZE] * 2)

while True:
    pygame.display.set_caption("Snake Game")
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP and directions[pygame.K_UP]:
                snake_direction = (0, -UNIT)
                directions = {pygame.K_UP: 1, pygame.K_DOWN: 0, pygame.K_LEFT: 1, pygame.K_RIGHT: 1}
            if event.key == pygame.K_DOWN and directions[pygame.K_DOWN]:
                snake_direction = (0, UNIT)
                directions = {pygame.K_UP: 0, pygame.K_DOWN: 1, pygame.K_LEFT: 1, pygame.K_RIGHT: 1}
            if event.key == pygame.K_LEFT and directions[pygame.K_LEFT]:
                snake_direction = (-UNIT, 0)
                directions = {pygame.K_UP: 1, pygame.K_DOWN: 1, pygame.K_LEFT: 1, pygame.K_RIGHT: 0}
            if event.key == pygame.K_RIGHT and directions[pygame.K_RIGHT]:
                snake_direction = (UNIT, 0)
                directions = {pygame.K_UP: 1, pygame.K_DOWN: 1, pygame.K_LEFT: 0, pygame.K_RIGHT: 1}
    screen.fill(BLACK)
    # Checks if snake hits the borders or selfcollides
    selfcollide = pygame.Rect.collidelist(snake, segments[:-1]) != -1
    if snake.left < 0 or snake.right > SCREEN_SIZE or snake.top < 0 or snake.bottom > SCREEN_SIZE or selfcollide:
        # Displays score
        if length - 1 > top_score:
            top_score = length - 1
        pygame.init()
        sysfont = pygame.font.get_default_font()
        font1 = pygame.font.SysFont(f'Score = {length - 1}, Top score = {top_score}', 50)
        img1 = font1.render(f'Score = {length - 1}, Top score = {top_score}', True, WHITE)
        screen.blit(img1, (120, 160))
        pygame.display.flip()
        pygame.time.delay(2 * 1000)
        snake.center, apple.center = get_random_position(), get_random_position()
        length, snake_direction = 1, (0, 0)
        segments = [snake.copy()]
    # Check if apple is eaten
    if snake.center == apple.center:
        apple.center = get_random_position()
        length += 1
    # Draws apple
    pygame.draw.rect(screen, RED, apple)
    # Draws snake
    [pygame.draw.rect(screen, snake_colour, segment) for segment in segments]
    score += 1
    # Moves snake
    time_now = pygame.time.get_ticks()
    if time_now - time > time_step:
        time = time_now
        snake.move_ip(snake_direction)
        segments.append(snake.copy())
        segments = segments[-length:]
    pygame.display.flip()
    clock.tick(60)