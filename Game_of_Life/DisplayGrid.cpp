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

#include "DisplayGrid.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;


// Constructor
DisplayGrid::DisplayGrid(){

}


// Constructor - overloaded
DisplayGrid::DisplayGrid(int rows, int cols, double density){
  this->density = density;
  this->rows = rows;
  this->cols = cols;
  CreateGrid(this->rows, this->cols, this->density);
}


// Constructor - overloaded
DisplayGrid::DisplayGrid(string inputText){
  this->inputText = inputText;
  SimulatedGrid();
}


//Destructor
DisplayGrid::~DisplayGrid(){
  for(int i = 0; i < this->rows; i++){
    delete[] board[i];
  }
  delete[] board;
}


/* ************************************************************************************************
 * Implementation of a member function - CreateGrid
 * ------------------------------------------------------------------------------------------------
 * This function creates the rows, cols and density for the game
 * ------------------------------------------------------------------------------------------------
 * Function has 3 @param: rows, cols, density
 * ************************************************************************************************/
void DisplayGrid::CreateGrid(int rows, int cols, double density){

    this->totalelements = this->rows * this->cols;
    this->totalPopulation = this->totalelements * this->density;

    if(this->totalPopulation == 0){ // When the density is 0, no X's will be displayed
        this->AllcellsDead = true;
    }
    else if(this->totalPopulation == this->totalelements){ //When the density is 1, only X's will be displayed
        this->AllcellsAlive = true;
    }
    else{
        RandomGrid();
    }

    this->board2 = new char* [this->rows+2]; // This will intialiaze board2, the board you will use to flip between generations
    for(int y = 0; y < this->rows+2; y++){
        board2[y] = new char[this->cols+2];
    }

    this->temp = new char* [this->rows+2]; // This will intialiaze temp
    for(int y = 0; y < this->rows+2; y++){
        temp[y] = new char[this->cols+2];
    }

    this->board = new char* [this->rows+2]; //first create array of char points [char*, char*, ..]
    for(int i = 0; i < this->rows+2; i++){// then for each char* in array, convert it into dynamic array
        board[i] = new char[this->cols+2];
    }
    int overallIPos = 0;
    int rArrayIndex = 0;

    for(int i = 1; i <= this->rows; i++){
        for(int y = 1; y<= this->cols; y++){ // Goes through each column
            if(this->AllcellsAlive){ // Checks if every box has an X
                this->board[i][y] = 'X';
            }
            else if(this->AllcellsDead){ // Checks if every box has an '-'
                this->board[i][y] = '-';
            }
            else if(overallIPos == this->randomPos[rArrayIndex]){ // If neither, then set a random position inside the grid
                this->board[i][y] = 'X';
                rArrayIndex++;
            }
            else{
                this->board[i][y] = '-'; // If none, set position equal to '-'
            }
            overallIPos++;
        }
    }
    // initialize board 2 to blank
    for(int i = 1; i <= this->rows ; i++)
    {
        for (int y = 1; y <= this->cols; y++)
        {
            this->board2[i][y] = '-';
        }
    }
}


/* ************************************************************************************************
 * Implementation of a member function - SwapGrids
 * ------------------------------------------------------------------------------------------------
 * This function swaps the grids so we can load the information to a new grid and cont the gens
 * ------------------------------------------------------------------------------------------------
 * Function has  @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::SwapGrids(){
    char** temp2 = this->board2;
    this->board2 = this->board;
    this->board = temp2;
}


/* ************************************************************************************************
 * Implementation of a member function - OpenFile
 * ------------------------------------------------------------------------------------------------
 * This function opens the text file.
 * ------------------------------------------------------------------------------------------------
 * Function has  @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::OpenFile(){
    cout << "Type the name of the file you want to write into ending with .txt: ";
    cin >> this->fileName;
    this->out_file.open(this->fileName);
}


/* ************************************************************************************************
 * Implementation of a member function - CloseFile
 * ------------------------------------------------------------------------------------------------
 * This function closes the input text file
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::CloseFile(){
    this->out_file.close();
}


/* ************************************************************************************************
 * Implementation of a member function - EmptyPrint
 * ------------------------------------------------------------------------------------------------
 * This function outputs empty to file in regards to the grid
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::EmptyPrint() {
    this->out_file << "Empty" << endl;
}


/* ************************************************************************************************
 * Implementation of a member function - StabilityPrint
 * ------------------------------------------------------------------------------------------------
 * This function outputs to file Stability achieved .
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::StabilityPrint(){
  this->out_file << "Stability Achieved" << endl;
}


/* ************************************************************************************************
 * Implementation of a member function - Generation
 * ------------------------------------------------------------------------------------------------
 * This function outputs to file the generations .
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::Generation(){
  this->out_file << "Gen " << generationCounter << endl;
}


/* ************************************************************************************************
 * Implementation of a member function - PrintGird
 * ------------------------------------------------------------------------------------------------
 * This function displays the grids rows and columns
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::PrintGrid(){
    this->generationCounter++;
    for(int i = 1; i <= this->rows; i++){
        for(int j = 1; j <= this->cols; j++){

            cout << this->board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

/* ************************************************************************************************
 * Implementation of a member function - PrintSimulatedGrid
 * ------------------------------------------------------------------------------------------------
 * This function prints the simulated grid cols and rows
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::PrintSimulatedGrid(){
    this->generationCounter++;
    for(int i = 1; i <= this->rows; i++){
        for(int j = 1; j <= this->cols; j++){
            this->out_file << this->board[i][j];
        }
        this->out_file << endl;
    }
    this->out_file << endl;
}


/* ************************************************************************************************
 * Implementation of a member function - InitialSimulatedPrintGrid
 * ------------------------------------------------------------------------------------------------
 * This function initializes the simulated grid
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value nd type - none
 * ************************************************************************************************/
void DisplayGrid::InitialSimulatedPrintGrid(){
    int generation = 0;
    this->out_file << "\nmGen: " << generation << " (input)" << endl;
}


/* ************************************************************************************************
 * Implementation of a member function - SimulatedGrid
 * ------------------------------------------------------------------------------------------------
 * This function creates the simulated grid
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::SimulatedGrid() {

    this->in_file.open(this->inputText);
    this->in_file >> this->rows;
    this->in_file >> this->cols;
    this->board = new char *[this->rows + 2];

    for (int i = 0; i < this->rows + 2; i++) {// then for each char* in array, convert it into dynamic array
        board[i] = new char[this->cols + 2];
    }
    for (int i = 1; i <= this->rows; i++) {
        for (int y = 1; y <= this->cols; y++) {
            this->in_file >> this->board[i][y];
        }
    }
    this->board2 = new char *[this->rows +2]; // This will initialize board2, the board you will use to flip between generations
    for (int y = 0; y < this->rows + 2; y++) {
        board2[y] = new char[this->cols + 2];
    }
    // initialize board 2 to blank
    for (int i = 1; i <= this->rows + 1; i++) {
        for (int y = 1; y <= this->cols + 1; y++) {
            this->board2[i][y] = '-';
        }
    }
    this->in_file.close();
}


/* ************************************************************************************************
 * Implementation of a member function - RandomGrid
 * ------------------------------------------------------------------------------------------------
 * This function creates the random grid
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param: none
 * return value and type - none
 * ************************************************************************************************/
void DisplayGrid::RandomGrid() {

    srand(time(0));
    this->randomPos = new int[this->totalPopulation];
    int available[this->totalelements];
    int newtotalelements = this->totalelements;
    int rindexposition = 0;
    for (int i = 0; i < this->totalelements; i++) {
        available[i] = i;
    }
    for (int i = 0; i < this->totalPopulation; i++) {
        rindexposition = rand() % newtotalelements;
        this->randomPos[i] = available[rindexposition];
        for (int z = rindexposition; z < newtotalelements; z++) {
            available[z] = available[z + 1];
        }
        newtotalelements--;
    }
    sort(this->randomPos, this->randomPos + this->totalPopulation);
}
