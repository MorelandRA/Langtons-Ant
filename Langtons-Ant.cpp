#include <iostream>  // cin >> , cout << ;
#include <stdlib.h>  // system("CLS"); PROGRAM WILL ONLY WORK IN WINDOWS
                     // Also doesn't work in Eclipse.
#include <windows.h> // Sleep(); PROGRAM WILL ONLY WORK IN WINDOWS

using namespace std;

//Adjust these to the height and width of your console.
const int SCREEN_WIDTH = 62;             // SCREEN_WIDTH must be no less than 64 for the highway to appear.
const int SCREEN_HEIGHT = 48;            // SCREEN_HEIGHT must be no less than 50 for the highway to appear.

// Adjust this to change how fast you want the ant to move.
const int MILLISECONDS_PER_REFRESH = 25; // Lower values mean a faster ant, but an unstable console.





enum direction: int {UP, RIGHT, DOWN, LEFT};            // The direction that the ant is facing.
enum color: bool {WHITE, BLACK};                        // The color of the tile.
enum turnDirection: int {CLOCKWISE, COUNTER_CLOCKWISE}; // The direction for the ant to turn.

int main();

void windowResize();                                                              // Initialization; makes sure the user's console window is the right size.
void displayBoard(bool tiles[SCREEN_WIDTH-2][SCREEN_HEIGHT-2]);                   // Displays the board.
void rePosition(bool tiles[SCREEN_WIDTH-2][SCREEN_HEIGHT-2], int position[3]);    // Calls turn, ant, and walk.

void flip(bool tiles[SCREEN_WIDTH-2][SCREEN_HEIGHT-2], int position[3]);          // Flips the current tile.
void turn(int, int position[3]);                                                  // Changes the direction that the ant is facing.
void walk(int position[3]);                                                       // Moves the position of the ant.


int main()
   {

   windowResize();                                                  // Initialization; makes sure the user's console window is the right size.

   bool tiles[SCREEN_WIDTH-2][SCREEN_HEIGHT-2] = {WHITE};           // All tiles start off white.
   int position[3] = {UP, (SCREEN_WIDTH-1)/2, (SCREEN_HEIGHT-1)/2}; // Ant starts in the center of the screen.


   while(position[1] > 0 && position[1] < SCREEN_WIDTH - 2 && position[2] > 0 && position[2] < SCREEN_HEIGHT - 2)
        {                                                           // While the ant is on the screen, run the program.
        displayBoard(tiles);                                        // Displays the board.
        rePosition(tiles, position);                                // Calls turn, ant, and walk.
        }

   cin.ignore();                                                    // Causes the program to require input before quitting.
   }
   
void windowResize()
    {
    cout << "Resize your window until all X's can be seen in a single row, and no more." << endl << endl;


    for(int i = 0; i < SCREEN_WIDTH; i++)                     // Displays X's in a row, as many as SCREEN_WIDTH
        cout << "X";
    cout << endl << endl << "There will be two lines of space between the row of X's and this line.";
    cout << endl << "Press Enter when this has been done.";
    cin.ignore();                                             // Waits for any text input before continuing.

    system("CLS");                                            // Clears the screen

    for(int i = 0; i < SCREEN_HEIGHT - 5; i++ )               // Displays a column of X's.
        {                                                     // -5 to account for other text.
        cout << "X";

        for(int j = 0; j < SCREEN_WIDTH - 1; j++)
            {
            cout << " ";
            }
        }

    cout << "Scroll up, and resize your window until all X's form a " << endl;
    cout << "constant vertical line, and all text can be seen." << endl << endl;

    cout << endl << "Press Enter when this has been done.";
    cin.ignore();                                             // Waits for any text input before continuing.
    }

void displayBoard(bool tiles[SCREEN_WIDTH-2][SCREEN_HEIGHT-2])
    {
    system("CLS");                                  // Clears the console.

    string board = "";                              // Stores the board, so that everything is printed with less of a delay between each character.

    for(int i = 0; i < SCREEN_WIDTH; i++)           // Creates a blank top border.
        {
        board += " ";
        }

    for(int i = 0; i < SCREEN_HEIGHT - 2; i++ )
        {
        board += " ";                               // Creates a blank left border.

        for(int j = 0; j < SCREEN_WIDTH - 2; j++)   // Creates the actual tile layout.
            {
            if(tiles[j][i] == WHITE)
                board += (char)(-37);               // ASCII for the solid white block.
            else
                board += " ";                       // A solid black block.
            }
        board += " ";                               // Creates a blank right border.
        }



    for(int i = 0; i < SCREEN_WIDTH - 1; i++)
        {
        board += " ";                               // Creates a blank bottom border.
        }

        cout << board;                              // Displays the board.

    Sleep(MILLISECONDS_PER_REFRESH);                // Causes a delay, so that the board doesn't flicker as much.
    }
    
void rePosition(bool tiles[SCREEN_WIDTH-2][SCREEN_HEIGHT-2], int position[])
    {
    if(tiles[position[1]][position[2]] == WHITE)    // Turn clockwise if the tile is white.
        turn(CLOCKWISE, position);

    else                                            // Otherwise, turn counter-clockwise.
        turn(COUNTER_CLOCKWISE, position);

    flip(tiles, position);                          // Flip the tile.

    walk(position);                                 // Move forward.

    }


void flip(bool tiles[SCREEN_WIDTH-2][SCREEN_HEIGHT-2], int position[])
   {
   if(tiles[position[1]][position[2]] == WHITE)     // If the tile is white, make it black.
        tiles[position[1]][position[2]] = BLACK;
   else                                             // Otherwise, make it white.
        tiles[position[1]][position[2]] = WHITE;

   }

void turn(int clock, int position[])
    {
    if(clock == CLOCKWISE)               // Turns the ant clockwise.
        {
        if(position[0] == UP)
            position[0] = RIGHT;
        else if(position[0] == RIGHT)
            position[0] = DOWN;
        else if(position[0] == DOWN)
            position[0] = LEFT;
        else // if (position[0] == LEFT)
            position[0] = UP;
        }

    else                                // Turns the ant counter-clockwise.
        {
        if(position[0] == UP)
            position[0] = LEFT;
        else if(position[0] == LEFT)
            position[0] = DOWN;
        else if(position[0] == DOWN)
            position[0] = RIGHT;
        else // if (position[0] == RIGHT)
            position[0] = UP;
        }
    }

void walk(int position[])               // Moves the ant forward.
    {
    if(position[0] == UP)
        position[2] += 1;
    else if(position[0] == RIGHT)
        position[1] += 1;
    else if(position[0] == DOWN)
        position[2] -= 1;
    else //if(position[0] == LEFT)
        position[1] -= 1;
    }
