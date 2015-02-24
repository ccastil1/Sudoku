#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef vector<int> oneVector;
typedef vector<oneVector> twoDvector;
typedef vector<vector<oneVector> > threeDvector;

template<typename T>
class Puzzle{
public:
    Puzzle();
    Puzzle(string);
    void display();
    void numPlacement();
    void checkPlacement(int, int);
    void continuePlay();
    
private:
    int size;
    twoDvector SudokuBoardVec;
    threeDvector fillBoard;
};

template<typename T>
Puzzle<T>::Puzzle(string filename)
{
    size = 9;
    
    ifstream infile;
    infile.open(filename.c_str());
    
    SudokuBoardVec.resize(size);
    fillBoard.resize(size);
    
    int buffer;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(!(infile >> buffer))
            {
                cout << "Error! Invalid file!"<<endl;
                exit(1);
            }
            
            if(buffer == 0 || (buffer>0 && buffer<=size))
            {
                SudokuBoardVec[i].push_back(buffer);
            }
        }
    }
    
    for(int i=0; i<size; i++)
    {
        fillBoard.push_back(vector<oneVector>());
        for(int j=0; j<size; j++)
        {
            fillBoard[i].push_back(oneVector());
            for(int k=1; k<size; k++)
            {
                fillBoard[i][j].push_back(k);
            }
        }
    }
    
}

template<typename T>
void Puzzle<T>::numPlacement()
{
    int xcoord;
    int ycoord;
    int num;
    
    cout << "Enter an x position: " <<endl;
    cin >> ycoord;
    cout << "Enter a y position: " <<endl;
    cin >> xcoord;
    cout << "Enter a number(1-9): " <<endl;
    cin >> num;
    cout << endl;
    
    checkPlacement(xcoord, ycoord);
    
    SudokuBoardVec[xcoord][ycoord] = num;
    display();
    continuePlay();
    
    
}

template<typename T>
void Puzzle<T>::display()
{
    typename twoDvector::iterator i;
    typename oneVector::iterator j;
    
    for(i=SudokuBoardVec.begin(); i !=SudokuBoardVec.end(); i++)
    {
        for(j=(*i).begin(); j != (*i).end(); j++)
        {
            cout << (*j);
        }
        cout <<endl;
    }
}


template<typename T>
void Puzzle<T>::checkPlacement(int xcoord, int ycoord)
{
    int x = xcoord;
    int y = ycoord;
    
    if(SudokuBoardVec[xcoord][ycoord] != 0)
    {
        for(int z=0; z<size; z++)
        {
            fillBoard[xcoord][ycoord][z] = 0;
        }
    }
    
    for(x=0; x<size; x++)
    {
        for(int z=0; z<size; z++)
        {
            if(SudokuBoardVec[x][ycoord] == fillBoard[xcoord][ycoord][z])
            {
                fillBoard[xcoord][ycoord][z] = 0;
            }
        }
    }
    
    for(y=0; y<size; y++)
    {
        for(int z=0; z<size; z++)
        {
            if(SudokuBoardVec[xcoord][y] == fillBoard[xcoord][ycoord][z])
            {
                fillBoard[xcoord][ycoord][z] = 0;
            }
        }
    }
    
    x = xcoord;
    y = ycoord;
    
    int squareSize = sqrt(size);
    int rSquare = xcoord/squareSize;
    int cSquare = ycoord/squareSize;
    
    for(int i=squareSize*rSquare; i<squareSize*rSquare + squareSize; i++)
    {
        for(int j=squareSize*cSquare; j<squareSize*cSquare + squareSize; j++)
        {
            for(int z=0; z<size; z++)
            {
                if(SudokuBoardVec[i][j] == fillBoard[xcoord][ycoord][z])
                {
                    fillBoard[xcoord][ycoord][z] = 0;
                }
            }
        }
    }
}

template<typename T>
void Puzzle<T>::continuePlay(){
    
    string playAgain;
    cout << "Continue Playing? ";
    cin >> playAgain;
    
    if(playAgain == "yes")
    {
        numPlacement();
    }
    else
    {
        exit(1);
    }
    
}