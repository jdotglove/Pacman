/*******************************************************************************
 * Game Class Interface                                                        *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 ******************************************************************************/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constants.h"
#include "pacman.h"
#include "ghost.h"
#include "dot.h"
#include "boulder.h"

class Game {
        public:
                Game();

                // prints the manual and stalls until the user types a character
                void print_manual();

                // Runs the Pacman game!
                void run();

                // sets up and initializes the board
                void setup_board();

                // prints the board and the border
                void print_board();

                // places the dots
                void place_dots();

                // initializes the dots
                void make_dots();

                // initializes the ghosts
                void make_ghosts();

                // sets the boulders on the board
                void set_boulders();

                // pauses to set up the new level
                void set_level();

                // places the ghosts on the board
                void place_ghosts();

                // checks to see if the game should be ended
                void game_over();

                // keeps setting the current level
                void curr_level();

                // a function to move each ghost
                void move_ghosts();
        private:
                char board[ROWS][COLS];

                Pacman p;
                Ghost ghosts[NUM_GHOSTS];
                Dot dots[NUM_DOTS];
                Boulder boulders[NUM_BOULDERS];
                int level;
};

#endif
