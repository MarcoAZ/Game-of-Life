/*******************************************************************************
* Author: Marco Zamora
* Class: CS 162
* Date: 1/11/15
* Edited: 1/14/15
# Assignment #1
*
* Purpose: Implementation of Conway's Game of Life
*******************************************************************************/
#include "conwayFunctions.h"

int main()
{
	//welcome the user, show list of possible starting configs
	cout << "Welcome to Conway's Game of Life! To begin, make sure the window is";
	cout << " set to fullsize and select a pre-set by number from the list below : " << endl;
	cout << "1. Glider" << endl << "2. A1" << endl << "3. Pentagon" << endl
		 << "4. Square" << endl << "5. Diamonds" << endl;
	
	//get selection
	int preset;
	//available options
	int numOptions = 5;
	
	do
	{
		cout << "Enter your selection: ";
	} while ( !(cin >> preset) || preset < 1 || preset > numOptions );
	
	//get column and row where the pre-set will start	
	int startRow;
	do
	{
		cout << "What row would you like to set the pre-set in(0-22)?";
	} while ( !(cin >> startRow) || startRow < 0 || startRow > ROWS);

	int startColumn;
	do
	{
		cout << "What column would you like to set the pre-set in(0-80)?";
	} while ( !(cin >> startColumn) || startColumn < 0 || startColumn > COLS);
	
	//the full size board with ghost edges of 12 each
	int board[ROWS + EDGES][COLS + EDGES];
		
	//prepare board with a 0 in each value to indicate dead cell
	for(int i = 0; i < ROWS + EDGES; i++)
	{
		for(int j = 0; j < COLS + EDGES; j++)
		{
			board[i][j] = 0;
		}
	}
	
	//add the live cells for the pre-set
	buildPreset( board, preset, startRow, startColumn );
	
	//run the simulation loop
	//response variable required when asking user to continue
	char response;
	do
	{
		//ask how many generations the user would like to be simulated
		int generations;
		do
		{
			cout << "How many generations would you like to simulate? ";
		} while ( !(cin >> generations) || generations < 1 );
	
		do
		{	
			//clear the screen
			system("clear");
			
			//display the board, without the ghost edges
			for(int i = EDGES/2; i <= ROWS + EDGES/2; i++)
			{
				for(int j = EDGES/2; j <= COLS + EDGES/2; j++)
				{
					if (board[i][j] == 0)
					{
						//blank spaces for dead cells
						cout << " ";
					}
					else
					{
						//Xs for live cells
						cout << "X";
					}
				}
				//new line at the end of each row
				cout << endl;
			}
	
			//pause for 0.1 second
			system("sleep 0.1");
	
			//copy board to temporary 2D array
			int temp[ROWS + EDGES][COLS + EDGES];
			
			copyArray( board, temp );
	
			//for each cell, check for each condition
			//need a 1 cell buffer on the borders
			for(int i = 1; i <= ROWS + EDGES - 1; i++)
			{
				for(int j = 1; j <= COLS + EDGES - 1; j++)
				{
					//count number of neighbors
					int neighbors = 0;
					neighbors = board[i-1][j-1] + board[i][j-1] + board[i+1][j-1]
							  + board[i-1][j] + board[i+1][j]
							  + board[i-1][j+1] + board[i][j+1] + board[i+1][j+1];
							  
					//cell dies?
					if ( neighbors <= 1 )
					{
						temp[i][j] = 0;
					}
					else if ( neighbors > 3 )
					{
						//cell still dies
						temp[i][j] = 0;
					}
					else if ( neighbors == 3 )
					{
						//cell is born or still lives
						temp[i][j] = 1;
					}
				}
			}			
	
			//copy the temp 2D array back to the original
			copyArray( temp, board );
	
			//loop back while there are still generations to simulate
			generations--;
		} while ( generations > 0 );
	
		//ask user if they would like to continue
		do
		{
			cout << "Would you like to continue? (y or n) ";
		} while ( !(cin >> response) );
	
	//if no, break out of loop
	//else let loop continue
	} while( response == 'y' );
	
	cout << "Thanks for checking out my implementation of Conway's Game of Life.\n";
	
	//All done
	return 0;
	
}
