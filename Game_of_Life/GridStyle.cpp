/* ********************************************************************************
 * Anthony Matter
 * Spring 22 CPSC 350
 * March 10, 2022
 * Assignment 4
 * ---------------------------------------------------------------------------------
 * This program is a game called Game of Life/GOL. The game itself is played on a
 * 2-dimensional grid. Each grid location is either empty or occupied by a single
 * cell X. A location’s neighbors are any of the cells in the surrounding eight
 * adjacent locations. The GOL will prompt the user for a decimal value (greater
 * than 0 and less than or equal to 1) representing the initial population density
 * of the world.
 * --------------------------------------------------------------------------------
 * GOL asks the user if it wishes to provide a  map file of the world in which the
 * simulation will be carried out, or if they would like a random assignment.
 * GOL will output to screen and can output to file depending on the user selects.
 * ---------------------------------------------------------------------------------
 * The game has 3 game modes; classic, mirror and doughnut mode.
 * ---------------------------------------------------------------------------------
 * Classic Mode: All locations off the grid are considered to be empty.
 * Doughnut Mode: The grid is wrapped around itself horizontally and vertically,
 *                resulting in a torus (doughnut) shape.
 * Mirror Mode: References off the grid are bounced back as though the wall were a
 *               mirror. This means the reflection of a cell could count as its own
 *               neighbor.
 * *********************************************************************************/

#include <iostream>
#include "GridStyle.h"

// Constructor
GridStyle::GridStyle(){

}


// Destructor
GridStyle::~GridStyle(){

}


/* ************************************************************************************************
 * Implementation of a member function - DisplayDecision
 * ------------------------------------------------------------------------------------------------
 * This function asks the user for input to play the game and to decide the games modes along
 * with output.
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param:
 * ************************************************************************************************/
void GridStyle::DisplayDecision(){

    DisplayGrid *p_grid = 0;
    GameMode c;
    cout << "\nWelcome to the Game of Life!" << endl;
    cout << "Which game mode would you like to play? ('c') for Classic Mode, ('d') for Doughnut Mode, or ('m') for Mirror Mode: ";
    cin >> line2;
    cout << "To use either a map file or random simulation, type ('m') for map file or ('r') for random: ";
    cin >> line;
    if(line == "m" || line == "M"){
        cout << "What is the name of the map file ending in .txt? ";
        cin >> inputText;
        p_grid = new DisplayGrid (inputText);
        if(line2 == "c" || line2 == "C"){
            c.ClassicMode(p_grid);
        }
        else if(line2 == "d" || line2 == "D"){
            c.DoughnutMode(p_grid);
        }
        else if(line2 == "m" || line2 == "M"){
            c.MirrorMode(p_grid);
        }
        else{
            cout << "\nType in the letter c for Classic Mode, d for Doughnut Mode, or m for Mirror Mode: ";
            cin >> line2;
        }
    }
    else if(line == "r" || line == "R"){
        cout << "Type in the number of rows: ";
        cin >> this->userRows;
        cout << "Type in the number of columns: ";
        cin >> this->userCols;
        cout << "Type in the population density between 0 and 1: ";
        cin >> this->userDensity;

        p_grid = new DisplayGrid(this->userRows, this->userCols, this->userDensity);
        if(line2 == "c" || line2 == "C"){
            c.ClassicMode(p_grid);
        }
        else if(line2 == "d" || line2 == "D"){
            c.DoughnutMode(p_grid);
        }
        else if(line2 == "m" || line2 == "M"){
            c.MirrorMode(p_grid);
        }
        else{
            cout << "\nType in the letter c for Classic Mode, d for Doughnut Mode, or m for Mirror Mode: ";
            cin >> line2;
        }
    }
    else{
        cout << "\nType in the letter m for map file or r for random simulation: "; // Turn this into some sort of while loop that keeps going through both if statements until user types r or m
        cin >> line;
    }
}
