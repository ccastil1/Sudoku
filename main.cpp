#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include "Puzzle.h"
using namespace std;

using namespace std;

int main(int argc, char *argv[])
{
    if(argc == 1 || argc > 2)
    {
        return 1;
    }
    
    Puzzle<int> Sudoku(argv[1]);
    
    Sudoku.print_puzzle();
    cout << endl;
}