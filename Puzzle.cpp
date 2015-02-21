//
//  Puzzle.cpp
//  
//
//  Created by Celeste Castillo on 2/21/15.
//
//
#include <iostream>
#include <vector>
#include <iterator>
#include "Puzzle.h"
using namespace std;

//template<Typename T>
Puzzle<int>::Puzzle()
{
    ptr = new T[9];
    vector < vector<int> > vec(9, vector<int>(9));
}

//template<Typename T>
Puzzle<int>::Puzzle(const Puzzle<int> &vec)
{
    ptr = new int[9];
    for(int i =0; i < 9; i++)
    {
        ptr[i] = vec.ptr;
    }
}

//template<Typename T>
Puzzle<int>::~Puzzle()
{
    delete [] ptr;
}