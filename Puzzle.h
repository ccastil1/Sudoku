//  Puzzle.h
//  Created by Celeste Castillo on 2/21/15.
#include <iostream>
#include <vector>
#include <iterator>

#ifndef _Puzzle_h
#define _Puzzle_h

template <typename T>
class Puzzle{
    
public:
    Puzzle();
    Puzzle(const Puzzle<T> &);
    ~Puzzle();
    
private:
    vector<T> rows;
    vector<T> columns;
};


#endif
