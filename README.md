# Langton's Ant

This program will ONLY work in windows, due to the use of system("CLS")  and the use of Sleep()
Additionally, the program will NOT work in Eclipse, due to the use of system("CLS").

At a white tile, the ant turns right, changes the tile to black, and moves forward.
At a black tile, the and turns left, changes the tile to white, and moves forward.

A highway refers to a pattern that repeats infinitely. In my program, the ant will stop if it attempts to go off of the screen.
The variables SCREEN_WIDTH and SCREEN_HEIGHT must be set to at least 62 and 48 respectively in order for the highway to appear.

The console will have a flickering effect if MILLISECONDS_PER_REFRESH is set to be too low.
Larger values for SCREEN_WIDTH and SCREEN_HEIGHT, and smaller values for MILLISECONDS_PER_REFRESH, will increase the chance of a flicker.
Values lower than 10 will cause a very rapid flickering, and is therefore not advised. However, the ant will still run successfully.
