//  Puzzle.h

//  Created by Celeste Castillo on 2/21/15.
#ifndef _Puzzle_h
#define _Puzzle_h

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <typename T>
class Puzzle{
    
public:
    Puzzle();
    Puzzle(const vector<T> &);
    ~Puzzle();
    
private:
    vector < vector<T> > SudokuVec[9];
};


#endif
