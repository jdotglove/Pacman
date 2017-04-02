/*******************************************************************************
 * Game Class Implementation                                                   *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 *****************************************************************************/

#include <iostream>
using namespace std;

#include "game.h"
#include "pacman.h"
#include "ghost.h"
#include "dot.h"
#include "termfuncs.h"

/* 
 * Constructor
 * sets the level to 1
 * */
Game::Game()
{
        level = 1;
}

/* print_manual()
 * Purpose:   Prints the manual and stalls until the user types a character
 * Arguments: None
 * Returns:   None
 */
void Game::print_manual()
{
        screen_clear();
        cout << "PACMAN GAME\n"
                "            \n"
                " Move left:    " << CMD_LFT << "\n"
                " Move right:   " << CMD_RGT << "\n"
                " Move up:      " << CMD_UP  << "\n"
                " Move down:    " << CMD_DWN << "\n"
                "\n"
                " Collect all the dots. They look like: " << DOT << "\n"
                " Avoid the ghosts.     They look like: " << GHOST << "\n"
                "\n"
                " Good luck!\n"
                "\n"
                " Press any key to continue...\n";

        getachar();
}
/* run()
 * Purpose:   Runs the pacman game while pacman is alive
 * Arguments: None
 * Returns:   None
 */
void Game::run()
{
        int counter = 0;
        int i;
        set_level();       
        while (p.is_alive())
        {
                curr_level();
                char input = getacharnow(SPEED);
                if (p.move(board,input)) {
                        for (i = 0; i < DOTS_PER_LEVEL * level; i++) {
                                if (dots[i].is_at(p.get_row(), p.get_col())) {
                                        dots[i].set_eaten(true);
                                        int n = DOT_REWARD;
                                        p.add_to_score(n);
                                        counter++;}
                        }
                }
                if (p.get_num_moves() % GHOST_FREQ == 0) {
                move_ghosts();}
                if (counter == DOTS_PER_LEVEL * level) {
                        int n = LEVEL_REWARD;
                        p.add_to_score(n);
                        level++;
                        set_level();
                        counter = 0;}
                game_over();
                setup_board();
        }
}
/* make_dots()
 * Purpose:   Initialize the dots and randomizes their location
 * Arguments: None
 * Returns:   None
 */
void Game::make_dots()
{
        for (int i = 0; i < DOTS_PER_LEVEL * level; i++)
        {
                dots[i].set_eaten(false);

                dots[i].set_random_location(board);

        }
}
/* place_dots()
 * Purpose:   Places the dots on the board
 * Arguments: None
 * Returns:   None
 */ 
void Game::place_dots()
{
        int i = 0;

        for (i = 0; i < DOTS_PER_LEVEL * level; i++)
        {
                if(dots[i].was_eaten() == false)
                {
                        dots[i].place_on_board(board);
                }
        }
}
/* setup_board()
 * Purpose:   Initializes the board full of spaces
 * Arguments: None
 * Returns:   None
 */
void Game::setup_board()
{
        int row;
        int col;
        for (row = 0; row < ROWS; row++) {
                for (col = 0; col < COLS; col++) {

                        board[row][col] = SPACE;
                }
        }
}
/* make_ghosts()
 * Purpose:   Sets the starting location of each ghost
 * Arguments: None
 * Returns:   None
 */
void Game::make_ghosts()
{

        ghosts[0].set_location(0,0);
        ghosts[1].set_location(ROWS - 1,0);
        ghosts[2].set_location(0,COLS - 1);
        ghosts[3].set_location(ROWS - 1,COLS - 1);

}
/* print_board()
 * Purpose:   Prints out the board and the border
 * Arguments: None
 * Returns:   None
 */
void Game::print_board()
{
        int col;
        int row;
        screen_home();
        screen_clear();
        cout << BORD_CORN;
        for (col = 1; col < COLS + 1; col++){
                cout << BORD_TOP;}
        if (col == COLS + 1){
                cout << BORD_CORN;}
        cout << endl;          
        col = 0;
        for (row = 0; row < ROWS; row++) {
                cout << BORD_SIDE;
                for (col = 0; col < COLS; col++){
                        cout << board[row][col];}
                cout << BORD_SIDE << endl;}
        cout << BORD_CORN;       
        for (col = 1; col < COLS + 1; col++){
                cout << BORD_TOP;}
        if (col == COLS + 1){
                cout << BORD_CORN;}
        cout << endl; 
        cout << "Score: " << p.get_score() << endl;
        cout << "Level " << level << endl;
}
/* set_boulders()
 * Purpose:   Sets the location for and prints the boulders
 * Arguments: None
 * Returns:   None
 */
void Game::set_boulders()
{
        for (int i = 0; i < BOULDERS_PER_LEVEL * level; i++)
        {
                boulders[i].place_on_board(board);
        }
}
/* place_ghosts()
 * Purpose:   Places ghosts on the board
 * Arguments: None
 * Returns:   None
 */
void Game::place_ghosts()
{
        for (int i = 0; i < NUM_GHOSTS; i++)
        {
                ghosts[i].place_on_board(board);
        }
}
/* set_level()
 * Purpose:   Sets up each new level
 * Arguments: None
 * Returns:   None
 */
void Game::set_level()
{
        screen_clear();
        setup_board();
        set_boulders();
        make_ghosts();
        make_dots();
        p.center();
        curr_level();
        // pasuses the game before each level so the user can prepare
        cout << "Press any key to continue...";
        getachar();
        screen_clear();
}
/* game_over()
 * Purpose:   Ends the game if the parameters are met
 * Arguments: None
 * Returns:   None
 */
void Game::game_over()
{
        int i = 0;

        while (i < NUM_GHOSTS)
        {
                // if the ghost reaches pacman's position the game ends
                if (ghosts[i].is_at(p.get_row(), p.get_col()))
                {
                        p.die();

                        cout << "You Lost :(" << endl;
                }
                i++;
        }
        // if you beat all the levels the game ends
        if (level > NUM_LEVELS)
        {
                p.die();

                cout << "CONGRATS! YOU WIN!" << endl;
        }

}
/* curr_level()
 * Purpose:   Continuously sets up the current level
 * Arguments: None
 * Returns:   None
 */
void Game::curr_level()
{
        screen_clear();
        set_boulders();
        p.place_on_board(board);
        place_ghosts();
        place_dots();
        print_board();
}
/* move_ghosts()
 * Purpose:   Moves each ghost
 * Arguments: None
 * Returns:   None
 */
void Game::move_ghosts()
{
        int i = 0;

        // moves each ghost    
        while (i < NUM_GHOSTS)
        {
                if (ghosts[i].move(board, p.get_row(), p.get_col()))
                {
                        game_over();
                }
                i++;
        }
}
