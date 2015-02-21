//  Puzzle.h
//  Created by Celeste Castillo on 2/21/15.
#include <iostream>
#include <vector>
#include <iterator>

#ifndef _Puzzle_h
#define _Puzzle_h
using namespace std:

template <typename T>
class Puzzle{
    
public:
    Puzzle();
    Puzzle(const Puzzle<int> &);
    ~Puzzle();
    
private:
    Puzzle<int> rows;
    Puzzle<int> columns;
};


#endif
