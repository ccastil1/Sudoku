//
//  Puzzle.cpp
//  Created by Celeste Castillo on 2/21/15.

#include <iostream>
#include <vector>
#include <iterator>
#include "Puzzle.h"
using namespace std;
typename std::vector<T>::iterator i;

template<typename T>
Puzzle<T>::Puzzle(){
    vector< vector<T> > PuzzleVec(9, vector<T>(9));
}


template<typename T>
Puzzle<T>::Puzzle(const vector<T> &vec)
{
    vector< vector<T> > PuzzleVec(9,vector<T>(9));


    for(int i = 0; i <= 9; i++)
    {
        for(vector<T>::iterator i = PuzzleVec[i].begin(); i != PuzzleVec[i].end(); i++)
            {
                PuzzleVec[i].push_back(vec[i].pop_front());
            }
    }

}

            
template<typename T>
Puzzle<T>::~Puzzle()
{
    delete [] SudokuVec;
}
            
            
            
            
            
/*template<typename T>
Puzzle<T>::Puzzle(const vector<T> &vec)
{
    ptr = new T[9];
    for(int i =0; i < 9; i++)
    {
        ptr[i] = vec.ptr;
    }
}
*/