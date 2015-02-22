//  Puzzle.h

//  Created by Celeste Castillo on 2/21/15.
#ifndef _Puzzle_h
#define _Puzzle_h

#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>

using namespace std;

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

    template<typename T>
    Puzzle<T>::Puzzle()
    {
        
    }   //default constructor
    
    
    template<typename T>
    Puzzle<T>::Puzzle(string file)
    {
        size = 9;
        cout << "Enter a file name: ";
        cin >> file;
        
        ifstream filename;
        filename.open(file.c_str())
        
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
    void Puzzle<T>::print_puzzle()
    {
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

#endif


