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

#include "GameMode.h"
#include <chrono>
using namespace std;

// Constructor
GameMode::GameMode(){
  this->PauseOrFileLine = PauseOrFileLine;
}

// Constructor - returns PauseOrFileLine
string GameMode::AskUser(){
  cin >> PauseOrFileLine;
  return PauseOrFileLine;
}

// Constructor
void GameMode::InitialPrintGrid(){
  int generation = 0;
  cout << "\nGen: " << generation << " (input)" << endl;
}

// Destructor
GameMode::~GameMode(){

}

/* ************************************************************************************************
 * Implementation of a member function - ClassicMode
 * ------------------------------------------------------------------------------------------------
 * This function iterates through each position in the grid while checking its neighbors
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: p_grid
 * ************************************************************************************************/
void GameMode::ClassicMode(DisplayGrid* p_grid){

    cout << "To pause before each generation, type ('p') to let the program run infinitely into a file, type ('f'), ";
    cout <<  " or if you want to press ENTER to go to each generation, type ('e'): ";
    cin >> this->PauseOrFileLine;
    int generation = 0;
    if(tolower(this->PauseOrFileLine == "f")){
        p_grid->OpenFile(); //Opens the file we are writing into
        p_grid->InitialSimulatedPrintGrid();
        p_grid->PrintSimulatedGrid();
    }
    else{
        InitialPrintGrid(); //When writing to file, do p_grid->InitialSimulatedPrintGrid();
        p_grid->PrintGrid(); //When writing to file, do p_grid->PrintSimulatedGrid();
    }
    int count = 0;
    while ((!isStable(p_grid) && (!isEmpty(p_grid)))){
        count++;
        generation++;
        int Xcounter = 0;
        //This will iterate through each position in the grid and check each of its neighbors
        for(int i = 1; i <= p_grid->rows; i++){
            for(int j = 1; j <= p_grid->cols; j++){
                if(p_grid->board[i-1][j-1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i-1][j] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i-1][j+1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i][j+1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i+1][j+1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i+1][j] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i+1][j-1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i][j-1] == 'X'){
                    Xcounter++;
                }
                if(Xcounter <= 1){
                    p_grid->board2[i][j] = '-';
                }
                if(Xcounter == 2){
                    //In this condition, nothing happens
                }
                if(Xcounter == 3){
                    p_grid->board2[i][j] = 'X';
                }
                if(Xcounter >= 4){
                    p_grid->board2[i][j] = '-';
                }
                Xcounter = 0;
            }
        }
        if(tolower(this->PauseOrFileLine == "p")){
            GamePause();
        }
        else if(tolower(this->PauseOrFileLine == "e")){
            cin.get();
        }
        if(tolower(this->PauseOrFileLine == "f")){
            p_grid->SwapGrids();
            p_grid->Generation();
            p_grid->PrintSimulatedGrid();
        }
        else
        {
            p_grid->SwapGrids();
            cout << "Gen: " << generation << endl; //When writing to file, do p_grid->Generation();
            p_grid->PrintGrid(); //When writing to file, do p_grid->PrintSimulatedGrid();
        }
    }
    if(isEmpty(p_grid)){
        if(tolower(this->PauseOrFileLine == "f")){
            p_grid->EmptyPrint();
        }
        else{
            cout << "Empty" << endl; //When writing to a file, do p_grid->EmptyPrint();
        }
    }
    else if(isStable(p_grid)){
        if(tolower(this->PauseOrFileLine == "f")){
            p_grid->StabilityPrint();
        }
        else{
            cout << "Stability Achieved" << endl; //When writing to a file, do p_grid->StabilityPrint();
        }
    }
    cout << endl;
    cout << "Press Enter to Exit...." << endl;
    cin.get();
    if(tolower(this->PauseOrFileLine == "f")){
        p_grid->CloseFile(); //Closes the file that we are writing into
    }
}


/* ************************************************************************************************
 * Implementation of a member function - DoughnutMode
 * ------------------------------------------------------------------------------------------------
 * This function iterates through each position in the grid for Doughnut Mode
 * while checking its neighbors
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: p_grid
 * ************************************************************************************************/
void GameMode::DoughnutMode(DisplayGrid* p_grid){
    int generation = 0;
    cout << "To pause before each generation, type ('p') to let the program run infinitely into a file, type ('f'), ";
    cout <<  " or if you want to press ENTER to go to each generation, type ('e'): ";
    cin >> this->PauseOrFileLine;

    if(tolower(this->PauseOrFileLine == "f")){
        p_grid->OpenFile(); //Opens the file we are writing into
        p_grid->InitialSimulatedPrintGrid();
        p_grid->PrintSimulatedGrid();
    }
    else{
        InitialPrintGrid(); //When writing to file, do p_grid->InitialSimulatedPrintGrid();
        p_grid->PrintGrid(); //When writing to file, do p_grid->PrintSimulatedGrid();
    }
    int count = 0;
    while((!isStable(p_grid) && (!isEmpty(p_grid)))){
        count++;
        generation++;
        int Xcounter = 0;

        for(int i = 1; i <= p_grid->rows; i++){
            for(int j = 1; j <= p_grid->cols; j++){
                if(i == 1){
                    if(j == 1){ // First column, first row
                        p_grid->board2[i-1][j-1] = p_grid->board[p_grid->rows-1][p_grid->cols-1]; //Sets position diagonal to upper left corner position equal to bottom right corner position
                        p_grid->board2[i][j-1] = p_grid->board[i][p_grid->cols-1];
                        p_grid->board2[i-1][j] = p_grid->board[p_grid->rows-1][j];
                    }
                    else if(j == this->cols - 1){
                        p_grid->board2[i-1][p_grid->cols] = p_grid->board[p_grid->rows - 1][1]; //Sets position diagnol to position in upper right hand corner equal to position in bottom left corner
                        p_grid->board2[i-1][p_grid->cols - 1] = p_grid->board[p_grid->rows - 1][p_grid->cols - 1]; //Sets position above upper right corner equal to position in lower right corner
                        p_grid->board2[i][p_grid->cols] = p_grid->board[i][1];
                    }
                    else{
                        p_grid->board2[i-1][j] = p_grid->board[p_grid->rows - 1][j]; //Sets position above the current position equal to position in the lowest row but in same column
                    }
                }
                if(j == 1){
                    if(i != p_grid->rows-1 && i != 1){ //If the position is in the first column but not in the last row
                        p_grid->board2[i][j-1] = p_grid->board[i][p_grid->cols-1];
                    }
                }
                if(j == p_grid->cols - 1){
                    if(i != p_grid->rows - 1 && i != 1){
                        p_grid->board2[i][p_grid->cols] = p_grid->board[i][1];
                    }
                }
                if(i == p_grid->rows - 1){
                    if(j == 1){
                        p_grid->board2[p_grid->rows][j - 1] = p_grid->board[1][p_grid->cols - 1];
                        p_grid->board2[p_grid->rows - 1][j - 1] = p_grid->board[p_grid->rows - 1][p_grid->cols - 1];
                        p_grid->board2[p_grid->rows][j] = p_grid->board[1][j];
                    }
                    else if(j == p_grid->cols - 1){
                        p_grid->board2[p_grid->rows][p_grid->cols] = p_grid->board[1][1];
                        p_grid->board2[i][p_grid->cols] = p_grid->board[i][1];
                        p_grid->board2[p_grid->rows][j] = p_grid->board[1][j];
                    }
                    else{
                        p_grid->board2[p_grid->rows][j] = p_grid->board[1][j];
                    }
                }
                // Now that DoughnutMode's extra features have been implemented, the same checking system from ClassicMode will be implemented below
                if(p_grid->board[i-1][j-1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i-1][j] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i-1][j+1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i][j+1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i+1][j+1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i+1][j] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i+1][j-1] == 'X'){
                    Xcounter++;
                }
                if(p_grid->board[i][j-1] == 'X'){
                    Xcounter++;
                }
                if(Xcounter <= 1){
                    p_grid->board2[i][j] = '-';
                }
                if(Xcounter == 2){

                }
                if(Xcounter == 3){
                    p_grid->board2[i][j] = 'X';
                }
                if(Xcounter >= 4){
                    p_grid->board2[i][j] = '-';
                }
                Xcounter = 0;
            }
        }
        if(tolower(this->PauseOrFileLine == "p")){
            GamePause();
        }
        else if(tolower(this->PauseOrFileLine == "e")){
            cin.get();
        }
        if(this->PauseOrFileLine == "f"){
            p_grid->SwapGrids();
            p_grid->Generation();
            p_grid->PrintSimulatedGrid();
        }
        else{
            p_grid->SwapGrids();
            cout << "Gen: " << generation << endl; //When writing to file, do p_grid->Generation();
            p_grid->PrintGrid(); //When writing to file, do p_grid->PrintSimulatedGrid();
        }
    }
    if(isEmpty(p_grid)){
        if(tolower(this->PauseOrFileLine == "f")){
            p_grid->EmptyPrint();
        }
        else{
            cout << "Empty" << endl; //When writing to a file, do p_grid->EmptyPrint();
        }
    }
    else if(isStable(p_grid)){
        if(tolower(this->PauseOrFileLine == "f")){
            p_grid->StabilityPrint();
        }
        else{
            cout << "Stability Achieved" << endl; //When writing to a file, do p_grid->StabilityPrint();
        }
    }
    cout << endl;
    cout << "Press Enter to Exit...." << endl;
    cin.get();
    if(tolower(this->PauseOrFileLine == "f")){
        p_grid->CloseFile(); //Closes the file that we are writing into
    }
}


/* ************************************************************************************************
 * Implementation of a member function - MirrorMode
 * ------------------------------------------------------------------------------------------------
 * This function iterates through each position in the grid for Mirror Mode
 * while checking its neighbors
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: p_grid
 * ************************************************************************************************/
void GameMode::MirrorMode(DisplayGrid* p_grid){

    int generation = 0;
    cout << "To pause before each generation, type ('p') to let the program run infinitely into a file, type ('f'), ";
    cout <<  " or if you want to press ENTER to go to each generation, type ('e'): ";
    cin >> this->PauseOrFileLine;
    if(tolower(this->PauseOrFileLine == "f")){
        p_grid->OpenFile(); //Opens the file we are writing into
        p_grid->InitialSimulatedPrintGrid();
        p_grid->PrintSimulatedGrid();
    }
    else{
        InitialPrintGrid(); //When writing to file, do p_grid->InitialSimulatedPrintGrid();
        p_grid->PrintGrid(); //When writing to file, do p_grid->PrintSimulatedGrid();
    }
    int count = 0;
    while ((!isStable(p_grid) && (!isEmpty(p_grid)))){
        count++;
        generation++;
        int Xcounter = 0;
        for(int i = 1; i <= p_grid->rows; i++){
            for(int j = 1; j <= p_grid->cols; j++){
                if(i == 1){
                    if(j == 1){ // First column, first row
                        p_grid->board2[i-1][j-1] = p_grid->board[i][j]; //Sets position diagonal to upper left corner position equal to bottom right corner position
                        p_grid->board2[i][j-1] = p_grid->board[i][j];
                        p_grid->board2[i-1][j] = p_grid->board[i][j];
                    }
                    else if(j == this->cols - 1){
                        p_grid->board2[i-1][p_grid->cols] = p_grid->board[i][j]; //Sets position diagnol to position in upper right hand corner equal to position in bottom left corner
                        p_grid->board2[i-1][p_grid->cols - 1] = p_grid->board[i][j]; //Sets position above upper right corner equal to position in lower right corner
                        p_grid->board2[i][p_grid->cols] = p_grid->board[i][j];
                    }
                    else{
                        p_grid->board2[i-1][j] = p_grid->board[i][j]; //Sets position above the current position equal to position in the lowest row but in same column
                    }
                }
                if(j == 1){
                    if(i != p_grid->rows-1 && i != 1){ //If the position is in the first column but not in the last row
                        p_grid->board2[i][j-1] = p_grid->board[i][j];
                    }
                }
                if(j == p_grid->cols - 1){
                    if(i != p_grid->rows - 1 && i != 1){
                        p_grid->board2[i][p_grid->cols] = p_grid->board[i][j];
                    }
                }
                if(i == p_grid->rows - 1){
                    if(j == 1){
                        p_grid->board2[p_grid->rows][j - 1] = p_grid->board[i][j];
                        p_grid->board2[p_grid->rows - 1][j - 1] = p_grid->board[i][j];
                        p_grid->board2[p_grid->rows][j] = p_grid->board[i][j];
                    }
                    else if(j == p_grid->cols - 1){
                        p_grid->board2[p_grid->rows][p_grid->cols] = p_grid->board[i][j];
                        p_grid->board2[i][p_grid->cols] = p_grid->board[i][j];
                        p_grid->board2[p_grid->rows][j] = p_grid->board[i][j];
                    }
                    else{
                        p_grid->board2[p_grid->rows][j] = p_grid->board[i][j];
                    }
                }
                // Now that MirrorMode's features have been implemented, the same checking system from ClassicMode will be implemented here
                if(p_grid->board[i-1][j-1] == 'X'){
                    this->Xcounter++;
                }
                if(p_grid->board[i-1][j] == 'X'){
                    this->Xcounter++;
                }
                if(p_grid->board[i-1][j+1] == 'X'){
                    this->Xcounter++;
                }
                if(p_grid->board[i][j+1] == 'X'){
                    this->Xcounter++;
                }
                if(p_grid->board[i+1][j+1] == 'X'){
                    this->Xcounter++;
                }
                if(p_grid->board[i+1][j] == 'X'){
                    this->Xcounter++;
                }
                if(p_grid->board[i+1][j-1] == 'X'){
                    this->Xcounter++;
                }
                if(p_grid->board[i][j-1] == 'X'){
                    this->Xcounter++;
                }
                if(this->Xcounter <= 1){
                    p_grid->board2[i][j] = '-';
                }
                if(this->Xcounter == 2){

                }
                if(this->Xcounter == 3){
                    p_grid->board2[i][j] = 'X';
                }
                if(this->Xcounter >= 4){
                    p_grid->board2[i][j] = '-';
                }
                this->Xcounter = 0;
            }
        }
        //if Player presses p for pause, pause on screen
        if(tolower(this->PauseOrFileLine == "p")){
            GamePause();
        }
        else if(tolower(this->PauseOrFileLine == "e")){
            cin.get();
        }
        if(tolower(this->PauseOrFileLine == "f")){
            p_grid->SwapGrids();
            p_grid->Generation();
            p_grid->PrintSimulatedGrid();
        }
        else{
            p_grid->SwapGrids();
            cout << "Gen: " << generation << endl; //When writing to file, do p_grid->Generation();
            p_grid->PrintGrid(); //When writing to file, do p_grid->PrintSimulatedGrid();
        }
    }
    if(isEmpty(p_grid)){
        if(tolower(this->PauseOrFileLine == "f")){
            p_grid->EmptyPrint();
        }
        else{
            cout << "Empty" << endl; //When writing to a file, do p_grid->EmptyPrint();
        }
    }
    else if(isStable(p_grid)){
        if(tolower(this->PauseOrFileLine == "f")){
            p_grid->StabilityPrint();
        }
        else{
            cout << "Stability Achieved" << endl; //When writing to a file, do p_grid->StabilityPrint();
        }
    }
    cout << endl;
    cout << "Press Enter to Exit...." << endl;
    cin.get();
    if(tolower(this->PauseOrFileLine == "f")){
        p_grid->CloseFile(); //Closes the file that we are writing into
    }
}


/* ************************************************************************************************
 * Implementation of a member function - Mode Decider
 * ------------------------------------------------------------------------------------------------
 * This function
 * ------------------------------------------------------------------------------------------------
 * Function has 0 @param:
 * ************************************************************************************************/
void GameMode::ModeDecider(){

}


/* ************************************************************************************************
 * Implementation of a member function - isEmpty
 * ------------------------------------------------------------------------------------------------
 * This function will check the grid to see if the cells are empty
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: p_grid
 * return: returns a bool of false or true
 * ************************************************************************************************/
bool GameMode::isEmpty(DisplayGrid* p_grid){

    for(int i = 1; i <= p_grid->rows; i++){
        for(int j = 1; j <= p_grid->cols; j++){
            if(p_grid->board[i][j] == 'X'){
                return false;
            }
        }
    }
    return true;
}


/* ************************************************************************************************
 * Implementation of a member function - isStable
 * ------------------------------------------------------------------------------------------------
 * This function will check the grid to see if the cells are empty
 * ------------------------------------------------------------------------------------------------
 * Function has 1 @param: p_grid
 * return: returns a bool of false or true
 * ************************************************************************************************/
bool GameMode::isStable(DisplayGrid* p_grid){
    if(isEmpty(p_grid)){
        return false;
    }
    else{
        for(int i = 1; i <= p_grid->rows; i++){
            for(int j = 1; j <= p_grid->cols; j++){
                if(p_grid->board[i][j] != p_grid->board2[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
}


/* ************************************************************************************************
* Implementation of a member function - GamePause
* ------------------------------------------------------------------------------------------------
* This function uses the system clock to pause the game
* ------------------------------------------------------------------------------------------------
* Function has 0 @param:
* return: nothing
* ************************************************************************************************/
void GameMode::GamePause(){
  time_t start = time(0);
  time_t current = time(0);
  while(difftime(current, start) < 1){
    current = time(0);
  }
}
