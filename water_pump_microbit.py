def on_forever():
    while input.temperature() <= 32 and input.temperature() >= 4:
        if cakLandSoil.if_moisture(cakLandSoil.SoilPin.P0, cakLandSoil.Mlevel.VERY_WET):
            basic.show_icon(IconNames.HAPPY)
        else:
            basic.show_icon(IconNames.UMBRELLA)
            cakLandPump.start_duration(cakLand.BoardSide.RIGHT, 100, 4)
            basic.clear_screen()
basic.forever(on_forever)
