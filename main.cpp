#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include "Puzzle.h"

using namespace std;

int main()
{
    Puzzle<int> Sudoku("puzzle.txt");
    
    Sudoku.display();
    Sudoku.numPlacement();
    
}