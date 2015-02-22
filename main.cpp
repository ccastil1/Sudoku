#include <iostream>
#include <vector>
#include <iterator>
#include "Puzzle.h"

using namespace std;
/*int main(){
    
    vector< vector<int> > PuzzleVec[9];
    
    cout << "Enter 9 integers(1-9): "<<endl;
   // cin >> PuzzleVec;
//    cout << PuzzleVec;
   // cout << PuzzleVec;
}
*/



int main(int argc, char *argv[]){
    if(argc == 1 || argc > 2)
    {
        return 1;
    }
    
    Puzzle<int> Sudoku(argv[1]);
    
    Sudoku.print_puzzle();
    cout << endl;
}