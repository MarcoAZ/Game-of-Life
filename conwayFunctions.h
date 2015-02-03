/*******************************************************************************
* Author: Marco Zamora
* Class: CS 162
* Date: 1/11/15
* Edited: 1/14/15
# Assignment #1
*
* Purpose: Declarations for the implementation of Conway's Game of Life
*******************************************************************************/
#ifndef CONWAY_H
#define CONWAY_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//the size of the board
#define COLS 80
#define ROWS 22
#define EDGES 80

//copies one array to another
void copyArray ( int original[ROWS + EDGES][COLS + EDGES], int copy[ROWS + EDGES][COLS + EDGES]);

//adds the user selected pre-set in the user chosen area of the window
void buildPreset( int array[ROWS + EDGES][COLS + EDGES], int config, int row, int col );

#endif
