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
#include <math.h>

using namespace std;

typedef vector<int> oneVector;
typedef vector<oneVector> twoDvector;
typedef vector<vector<oneVector> > threeDvector;


template<typename T>
class Puzzle
{
public:
    Puzzle();   //declare default constructor
    Puzzle(string);   //declare non default constructor
    void print_puzzle();    //declare member function to print the puzzle
    void boardPlacement();
    void checkPlacement(int, int);
    //    void playAgain();
    
private:
    int size; //declare size variable for board size
    twoDvector SudokuBoardVec; //2D board vector
    threeDvector FillBoard; //3D vector to place numbers in board
};
#endif

template<typename T>
Puzzle<T>::Puzzle()
{
    
}   //default constructor


template<typename T>
Puzzle<T>::Puzzle(string file){
    size = 9;
    cout << "Enter a file name: ";
    cin >> file;
    
    ifstream filename;
    filename.open("puzzle.txt");
    
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
            
            if (buffer == 0 || (buffer > 0 && buffer <= 9))
            {
                SudokuBoardVec[i].push_back(buffer);
            }
        }
    }
    
    for (int i=0; i < size; i++)
    {
        FillBoard.push_back(vector<oneVector>());
        for(int j=0; j<size; j++)
        {
            FillBoard[i].push_back(oneVector());
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

template<typename T>
void Puzzle<T>::checkPlacement(int xcoord, int ycoord)
{
    int x = xcoord;
    int y = ycoord;
    
    if(SudokuBoardVec[xcoord][ycoord] != 0)
    {
        for(int i=0; i < size; i++)
        {
            FillBoard[x][y][i] = 0;
        }
    }
    
    for(x=0; x < size; x++)
    {
        for(int z=0; z < size; z++)
        {
            if(SudokuBoardVec[x][ycoord] == FillBoard[xcoord][ycoord][z])
            {
                FillBoard[xcoord][ycoord][z] = 0;
            }
        }
    }
    
    for(y=0; y < size; y++)
    {
        for(int z=0; z < size; z++)
        {
            if(SudokuBoardVec[x][ycoord] == FillBoard[xcoord][ycoord][z])
            {
                FillBoard[xcoord][ycoord][z] = 0;
            }
        }
    }
    
    x = xcoord;
    y = ycoord;
    int sqrSize = sqrt(size);
    int rSqr = xcoord/sqrSize;
    int cSqr = ycoord/sqrSize;
    
    for(int i=sqrSize*rSqr; i < sqrSize*rSqr + sqrSize; i++)
    {
        for(int j=sqrSize*cSqr; j < sqrSize*cSqr + sqrSize; j++)
        {
            for (int z=0; z < size; z++)
            {
                if(SudokuBoardVec[i][j] == FillBoard[xcoord][ycoord][z])
                {
                    FillBoard[xcoord][ycoord][z] = 0;
                }
            }
        }
    }
}

template<typename T>
void Puzzle<T>::boardPlacement()
{
    int xcoord;
    int ycoord;
    int num;
    
    cout << "Enter an x position: " <<endl;
    cin >> xcoord;
    cout << "Enter a y position: " <<endl;
    cin >> ycoord;
    cout << "Enter a number(1-9): " <<endl;
    cin >> num;
    cout << endl;
    
    checkPlacement(xcoord,ycoord);
}
