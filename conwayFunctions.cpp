/*******************************************************************************
* Author: Marco Zamora
* Class: CS 162
* Date: 1/12/15
* Edited: 1/14/15
# Assignment #1
*
* Purpose: Definitions for the implementation of Conway's Game of Life
*******************************************************************************/
#include "conwayFunctions.h"

//copies one array to another
void copyArray ( int original[ROWS + EDGES][COLS + EDGES], int copy[ROWS + EDGES][COLS + EDGES])
{
	for(int i = 0; i < ROWS + EDGES; i++)
	{
		for(int j = 0; j < COLS + EDGES; j++)
		{
			copy[i][j] = original[i][j];
		}
	}
}

//adds the user selected pre-set in the user chosen area of the window
void buildPreset( int array[ROWS + EDGES][COLS + EDGES], int config, int row, int col )
{
	//change values to make room for ghost edges
	int rowCoord = row + EDGES/2;
	int colCoord = col + EDGES/2;
	
	//depending on what pre-set config was chosen will decide which to draw
	switch ( config )
	{
		case 1:
			//glider
			array[rowCoord][colCoord] 			= 1;//left square
			array[rowCoord+1][colCoord] 		= 1;
			array[rowCoord][colCoord+1] 		= 1;
			array[rowCoord+1][colCoord+1] 		= 1;
			array[rowCoord][colCoord+10] 		= 1; //first glider
			array[rowCoord+1][colCoord+10] 		= 1;
			array[rowCoord+2][colCoord+10] 		= 1;
			array[rowCoord-1][colCoord+11] 		= 1;
			array[rowCoord+3][colCoord+11] 		= 1;
			array[rowCoord-2][colCoord+12] 		= 1;
			array[rowCoord+4][colCoord+12] 		= 1;
			array[rowCoord-2][colCoord+13] 		= 1;
			array[rowCoord+4][colCoord+13] 		= 1;
			array[rowCoord+1][colCoord+14] 		= 1;
			array[rowCoord-1][colCoord+15] 		= 1;
			array[rowCoord+3][colCoord+15] 		= 1;
			array[rowCoord][colCoord+16] 		= 1;
			array[rowCoord+2][colCoord+16] 		= 1;
			array[rowCoord+1][colCoord+16] 		= 1;
			array[rowCoord+1][colCoord+17] 		= 1;
			array[rowCoord-2][colCoord+20] 		= 1; //second glider
			array[rowCoord-1][colCoord+20] 		= 1;
			array[rowCoord][colCoord+20] 		= 1;
			array[rowCoord-2][colCoord+21] 		= 1;
			array[rowCoord-1][colCoord+21] 		= 1;
			array[rowCoord][colCoord+21] 		= 1;
			array[rowCoord-3][colCoord+22] 		= 1;
			array[rowCoord+1][colCoord+22] 		= 1;
			array[rowCoord-4][colCoord+24] 		= 1;
			array[rowCoord-3][colCoord+24] 		= 1;
			array[rowCoord+1][colCoord+24] 		= 1;
			array[rowCoord+2][colCoord+24] 		= 1;
			array[rowCoord-2][colCoord+34] 		= 1; //last square
			array[rowCoord-1][colCoord+34] 		= 1;
			array[rowCoord-2][colCoord+35] 		= 1;
			array[rowCoord-1][colCoord+35] 		= 1;

			break;
		case 2:
			//A1
			array[rowCoord][colCoord] 		= 1;
			array[rowCoord-1][colCoord] 	= 1;
			array[rowCoord-2][colCoord] 	= 1;
			array[rowCoord-3][colCoord+1] 	= 1;
			array[rowCoord-2][colCoord+2]	= 1;
			array[rowCoord-1][colCoord+2]	= 1;
			array[rowCoord][colCoord+2]		= 1; //end of A
			array[rowCoord][colCoord+6]		= 1;
			array[rowCoord-1][colCoord+6]	= 1;
			array[rowCoord-2][colCoord+6] 	= 1;
			array[rowCoord-3][colCoord+6] 	= 1;
			array[rowCoord-2][colCoord+5] 	= 1; //end of 1
			break;
		case 3:
			//pentagon
			array[rowCoord-1][colCoord+1]	= 1; //end of top of pentagon
			array[rowCoord][colCoord] 		= 1;
			array[rowCoord][colCoord+1]		= 1;
			array[rowCoord][colCoord+2]		= 1; //end of row 1
			array[rowCoord+1][colCoord]		= 1;
			array[rowCoord+1][colCoord+1]	= 1;
			array[rowCoord+1][colCoord+2]	= 1; //end of row 2
			array[rowCoord+2][colCoord] 	= 1;
			array[rowCoord+2][colCoord+1]	= 1;
			array[rowCoord+2][colCoord+2]	= 1; //end of row 3
			break;
		case 4:
			//square
			array[rowCoord][colCoord] 		= 1;
			array[rowCoord][colCoord+1]		= 1;
			array[rowCoord][colCoord+2]		= 1; //end of row 1
			array[rowCoord+1][colCoord]		= 1;
			array[rowCoord+1][colCoord+1]	= 1;
			array[rowCoord+1][colCoord+2]	= 1; //end of row 2
			array[rowCoord+2][colCoord] 	= 1;
			array[rowCoord+2][colCoord+1]	= 1;
			array[rowCoord+2][colCoord+2]	= 1; //end of row 3
			break;
		case 5:
			//diamonds
			array[rowCoord][colCoord+1]		= 1; //diamond1
			array[rowCoord+1][colCoord]		= 1;
			array[rowCoord+1][colCoord+2] 	= 1;
			array[rowCoord+2][colCoord+1]	= 1;
			array[rowCoord][colCoord+4]		= 1; //diamond2
			array[rowCoord+1][colCoord+3]	= 1;
			array[rowCoord+1][colCoord+5] 	= 1;
			array[rowCoord+2][colCoord+4]	= 1;
			break;
		default:
			//display error message if something else manages to pass
			cout << "An error occured and the pre-set was not added\n";
			
	}
}
