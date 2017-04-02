/***************************************************************************
 *****
 * Pacman Class Implementation
   *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)
   *
********/

#include <iostream>
using namespace std;

#include "termfuncs.h"
#include "constants.h"
#include "pacman.h"


/* 
 * Pacman contructor
 * sets Pacman to be alive
 * starts the score at 0
 * and sets the number of moves to 0
 */
Pacman::Pacman()
{
       alive = true;
       score = 0;
       num_moves = 0;
}
/* center()
 * Purpose:    Sets Pacman's location to the center of board, faces Pacman up
 * Arguments:  None
 * Returns:    None
 * */
void Pacman::center()
{
        // halfway down the rows and halfway down the cols
        row = (ROWS - 1) / 2;
        col = (COLS - 1) / 2;
       
        head = UP;
}

/*
 * Purpose:   Places Pac on the board, at Pacman's location
 * Arguments: 2D array of board
 * Returns:   None
 */
void Pacman::place_on_board(char board[ROWS][COLS])
{
        board[row][col] = head;
}

/* move(board, input)
 * Purpose:   Moves pacman
 * Arguments: 2D board array and input from the user
 * Returns:   True if it eats a dot, false if otherwise
 */
bool Pacman::move(char board [ROWS][COLS], char input)
{ 
        if (input == CMD_UP)
        {
                Pacman::up(board);
        }
        else if (input == CMD_DWN)
        {
                Pacman::down(board);
        }
        else if (input == CMD_RGT)
        {
                Pacman::right(board);
        }       
        else if (input == CMD_LFT)
        {
                Pacman::left(board);
        }
        Pacman::wraparound(board);
        // when the dot gets eaten
        if (board[row][col] == DOT)
        {
                return true;

        }
        else {
                return false;
        }
}
/* up(board)
 * Purpose:   Moves pacman up unless a boulder is in the way
 * Arguments: 2D board array
 * Returns:   None
 */
void Pacman::up(char board[ROWS][COLS])
{
        row--;
        head = UP;
        
        if (board[row][col] == BOULDER)
        {
              row++;
        }
}
/* down(board)
 * Purpose:   Moves pacman down unless a boulder is in the way
 * Arguments: 2D board array
 * Returns:   None
 */
void Pacman::down(char board[ROWS][COLS])
{
        row = row + 1;
        head = DOWN;

        if (board[row][col] == BOULDER)
        {
                row--;        
        }
}
/* right(board)
 * Purpose:   Moves pacman right unless a boulder is in the way
 * Arguments: 2D board array
 * Returns:   None
 */
void Pacman::right(char board[ROWS][COLS])
{
        col++;
        head = RIGHT;
        
         if (board[row][col] == BOULDER)
         {
                col--;
         }
}
/* left(board)
 * Purpose:   Moves pacman left unless a boulder is in the way
 * Arguments: 2D board array
 * Returns:   None
 */
void Pacman::left(char board[ROWS][COLS])
{
        col--;
        head = LEFT;;

        if (board[row][col] == BOULDER)
        {
                col++;
        }
}
/* wraparound(board)
 * Purpose:   Wraps pacman around the board
 * Arguments: 2D board array
 * Returns:   None
 */
void Pacman::wraparound(char board[ROWS][COLS])
{
        if (row < 0) {
                row = ROWS - 1;

                if (board[row][col] == BOULDER) {
                        row = 0;
                }
        }
        else if (row > ROWS - 1) {
                row = 0;

                if (board[row][col] == BOULDER) {
                        row = ROWS - 1;
                }
        }
        else if (col < 0) {
                col = COLS - 1;

               if (board[row][col] == BOULDER) {
                        col = 0;
                }
        }
        else if (col > COLS - 1) {
                col = 0;

                if (board[row][col] == BOULDER) {
                        col = COLS - 1;
                }
        }
}
/* die()
 * Purpose:   Kills pacman
 * Arguments: None
 * Returns:   None
 */
void Pacman::die()
{
        alive = false;
}
/* is_alive()
 * Purpose:   Checks to see if Pacman is alive
 * Arguments: None
 * Returns:   True if alive and false if otherwise
 */
bool Pacman::is_alive()
{        
        if (alive == true)
        {
                return true;
        }
        else {
                return false;
        }
}
/* is_at()
 * Purpose:   Checks to see if pacman is at that current row and col
 * Arguments: It is passed the row and col from the game function
 * Returns:   Returns true if pacman is there and false if otherwise
 */
bool Pacman::is_at(int r, int c)
{
        if (r == row and c == col)
        {
                return true;
        }
        else {
                return false;
        }
}
/* get_row()
 * Purpose:   Returns Pacman's current row
 * Arguments: None
 * Returns:   The current row of Pacman
 */
int Pacman::get_row()
{
        return row;
}
/* get_col()
 * Purpose:   Returns Pacman's current col
 * Arguments: None
 * Returns:   The current col of Pacman
 */
int Pacman::get_col()
{
        return col;
}
/* add_to_score()
 * Purpose:   Adds the new score to the current score
 * Arguments: Gets passed the socre that should be added
 * Returns:   None
 */
void Pacman::add_to_score(int n)
{
        score += n;
}
/* get_score()
 * Purpose:   Returns the current score
 * Arguments: None
 * Returns:   The current score
 */
int Pacman::get_score()
{
        return score;
}
/* get_num_moves()
 * Purpose:   Keeps track of how many times pacman moves
 * Arguments: None
 * Returns:   The current number of moves
 */
int Pacman::get_num_moves()
{
                num_moves++;

                return num_moves;
}
