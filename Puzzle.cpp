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

template<Typename T>
Puzzle<T>::Puzzle()
{
    ptr = new T[9];
    vector < vector<T> > vec(9, vector<T>(9));
}

template<Typename T>
Puzzle<T>::Puzzle(const Puzzle<T> &vec)
{
    ptr = new T[9];
    for(int i =0; i < 9; i++)
    {
        ptr[i] = vec.ptr;
    }
}

template<Typename T>
Puzzle<T>::~Puzzle()
{
    delete [] ptr;
}