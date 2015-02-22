//
//  Puzzle.cpp
//  Created by Celeste Castillo on 2/21/15.

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include "Puzzle.h"
using namespace std;


template<typename T>
Puzzle<T>::Puzzle(){
    
}   //default constructor


template<typename T>
Puzzle<T>::Puzzle(string file)
{
    size = 9;
    iftream filename;
    filename.open(filename.c_str())
    
    int buffer;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(!(filename >> buffer))
            {
                cout << "Error! Invalid File!"<< endl;
                exit(1);
            }
            
            if (buffer == 0 || buffer > 0 && buffer <= 9)
            {
                SudokuBoardVec[i].push_back(buffer);
            }
        }
    }
    
    for (int i=0; i < size; i++)
    {
        FillBoard.push_back(vector< vector<int>>());
        for(int j=0; j<size; j++)
        {
            FillBoard[i].push_back(vector<int>());
            for(int k=1; k < size; k++)
            {
                FillBoard[i][j].push_back(k);
            }
                
        }
    }
}

template<typename T>
void Puzzle<T>::print_puzzle(){
        for(int i=0; i < size; i++)
        {
            for(int j=0; j < size; j++)
            {
                cout << SudokuBoardVec[i][j] << " ";
            }
            
            cout << endl;
        }
    }
}