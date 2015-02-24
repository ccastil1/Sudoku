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
 //   Puzzle<char> charSudoku("wordoky.txt");

    Sudoku.display();
    Sudoku.numPlacement();
  //  charSudoku.display();
  //  charSudoku.numPlacement();
}
