#include <iostream>
#include "DisplayGrid.h"
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



/* *********************************************************************************
 * Base Class - GameMode
 * ---------------------------------------------------------------------------------
 * 1 @param: p_grid
 * *********************************************************************************/
class GameMode{
public:
    int userRows = 0;
    int userCols = 0;
    int Xcounter = 0;
    int XcounterforEmpty = 0;
    int differentPositionCounter = 0;
    int rows = 0;
    int cols = 0;
    double userDensity;
    string PauseOrFileLine;
    string inputText;
    string line;
    string line2;
    char** board;
    char** board2;
    char** temp;
    GameMode();
    ~GameMode();
    bool isEmpty(DisplayGrid* p_grid);
    bool isStable(DisplayGrid* p_grid);
    string AskUser();
    void ClassicMode(DisplayGrid* p_grid);
    void ClassicModeSimulate(DisplayGrid* p_grid);
    void ModeChecker();
    void MirrorMode(DisplayGrid* p_grid);
    void DoughnutMode(DisplayGrid* p_grid);
    void ModeDecider();
    void GamePause();
    void InitialPrintGrid();
};
