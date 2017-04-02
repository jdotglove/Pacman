/*******************************************************************************
 * Ghost Class Interface                                                       *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 * ****************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
#include "ghost.h"
#include "constants.h"
#include "termfuncs.h"
/*
 * Ghost constuctor
 */
Ghost::Ghost()
{


}
/* set_location(r, c)
 * Purpose:   Sets the ghost location to the row and col passed from game
 * Arguments: Row, Col
 * Returns:   None
 */
void Ghost::set_location(int r, int c)
{
        row = r;
        col = c;

}
/* place_on_board(board)
 * Purpose:   Places the ghost on the board at their respective locations
 * Arguments: 2D array of the board
 * Returns:   None
 */
void Ghost::place_on_board(char board[ROWS][COLS])
{
        board[row][col] = GHOST;
}
/* is_at(r, c)
 * Purpose:   Checks to see if the ghost is at a given row and col
 * Arguments: Row and Col
 * Returns:   Returns true if the ghost is there and false if otherwise
 */
bool Ghost::is_at(int r, int c)
{
        if (row == r and col == c)
        {
                return true;
        }
        else {
                return false;
        }
}
/* move(board, target_r, target_c)
 * Purpose:   Moves the ghosts towards pacman
 * Arguments: Pacman's current row and pacman's current col
 * Returns:   Returns true if a ghost eats pacman and false if otherwise
 */
bool Ghost::move(char board[ROWS][COLS], int target_r, int target_c)
{
        if (abs(row - target_r) >= abs(col - target_c)){
                if (row < target_r){
                        row++;
                        if (board[row][col] == GHOST){
                                row--;}
                }
                else if (row > target_r){
                        row--;
                        if (board[row][col] == GHOST){
                                row++;}
                }
        }
        if (abs(col - target_c) > abs(row - target_r)) {       
                if (col > target_c){
                        col--;
                        if (board[row][col] == GHOST){
                                col++;}
                }
                else if (col < target_c){
                        col++;
                        if (board[row][col] == GHOST){
                                col--;}
                }
        }
        if (row == target_r and col == target_c) {
                return true;}
        else {
                return false;}
} 
