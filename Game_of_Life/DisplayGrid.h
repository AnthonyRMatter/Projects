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
#include <string>
#include <fstream>
//#include "GameMode.h"
using namespace std;

/* **********************************************************************************
 * Base Class - DisplayGrid
 * ----------------------------------------------------------------------------------
 * 3 @param: rows, columns and density
 * **********************************************************************************/
class DisplayGrid{
public:

    int* randomPos;
    int totalPopulation;
    int rows = 0;
    int cols = 0;
    double density;
    int totalelements;
    int rowsWithBounds = rows + 2;
    int colsWithBounds = cols + 2;
    int generationCounter = 0;
    bool AllcellsDead = false;
    bool AllcellsAlive = false;
    ofstream out_file;
    string inputText;
    string fileName;
    ifstream in_file;

    char** board;
    char** board2;
    char** temp;

    DisplayGrid(int rows, int cols, double density);
    DisplayGrid(string inputText);
    DisplayGrid();
    ~DisplayGrid();

    void PrintGrid();
    void PrintSimulatedGrid();
    void SwapGrids();
    void OpenFile();
    void CloseFile();
    void EmptyPrint();
    void StabilityPrint();
    void Generation();
    void CreateGrid(int rows, int cols, double density);
    void SimulatedGrid();
    void RandomGrid();
    void InitialSimulatedPrintGrid();
};
