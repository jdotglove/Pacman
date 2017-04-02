/*******************************************************************************
 ******
 * Dot Class Implementation
   *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)
   *
 *******************************************************************************
******/

#include <iostream>
using namespace std;

#include "termfuncs.h"
#include "constants.h"
#include "dot.h"

/*
 * dot constructor
 */
Dot::Dot()
{

}
/* set_random_location(board)
 * Purpose:   Chooses a random location for the dot on the board with space
 * Arguments: 2D array of board
 * Returns:   None
 */
void Dot::set_random_location(char board[ROWS][COLS])
{
        //sets a random location until the dot occupies an empty space
        do {
                row = random_int(1, ROWS - 2);
                col = random_int(1, COLS - 2);

        }while (board[row][col] != SPACE);
}

/* place_on_board(board)
 * Purpose:   Places the Dot on the board, at its location.
 * Arguments: 2D array of board
 * Returns:   None
 */

void Dot::place_on_board(char board[ROWS][COLS])
{
        // prints out only the uneaten dots
        if (eaten == false){
                board[row][col] = DOT;
        }
}


/* is_at(r, c)
 * Purpose:   Returns if the Dot is at this row and col
 * Arguments: Passed the row and col from the game function
 * Returns:   Returns true if it is and false if otherwise
 */
bool Dot::is_at(int r, int c)
{
 
        if (row == r and col == c)
        {
                return true;
        }
        else {
                return false;
        }
        
        return false;
}
/* set_eaten(e)
 * Purpose:   Updates the dot's eaten value
 * Arguments: A bool saying if the dot was eaten or not
 * Returns:   None
 */
void Dot::set_eaten(bool e)
{
        eaten = e;
}
/* was_eaten()
 * Purpose:   Returns the dot's eaten value
 * Arguments: None
 * Returns:   True if it was eaten and false if otherwise
 */
bool Dot::was_eaten()
{
        if (eaten == true)
        {
                return true;
        }
        else {
                return false;
        }
}
