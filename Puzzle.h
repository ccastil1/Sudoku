//  Puzzle.h

//  Created by Celeste Castillo on 2/21/15.
#ifndef _Puzzle_h
#define _Puzzle_h

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

//template <typename T>
class Puzzle{
    
public:
    Puzzle();
    vector(const vector<int> &);
    ~Puzzle();
    
private:
    vector < vector<int> > vec(9, vector<int>(9));
};


#endif
