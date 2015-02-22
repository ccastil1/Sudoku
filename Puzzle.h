//  Puzzle.h

//  Created by Celeste Castillo on 2/21/15.
#ifndef _Puzzle_h
#define _Puzzle_h

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;

/*template <typename T>
class Puzzle{
    
public:
    Puzzle();
    Puzzle(const vector<T> &);
    ~Puzzle();
    
private:
    vector < vector<T> > SudokuVec[9];
};
*/

class Puzzle{
public:
    Puzzle();   //declare default constructor
    Puzzle(string);   //declare non default constructor
    void print_puzzle();    //declare member function to print the puzzle
private:
    int size; //declare size variable for board size
    vector< vector<int> > SudokuBoardVec; //2D board vector
    vector <vector <vector < vector<int> > > FillBoard; //3D vector to place numbers in board
};



#endif


