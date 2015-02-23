#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "Puzzle.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout << "Using " << argv[0] <<endl;
        return 1;
    }
    
    Puzzle<int> Sudoku(argv[1]);
    
    Sudoku.print_puzzle();
    int game = 2;
    while(game != 1)
    {
        Sudoku.boardPlacement();
    }
    
    cout << endl;
}