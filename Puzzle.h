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
    void printPuzzleBoard();
    void display();
    void numPlacement();
    int checkPlacement(int, int, int);
    void error();
    void finished();
    
private:
    int size;
    twoDvector SudokuBoardVec;
    threeDvector checkBoard;
};

template<typename T>
Puzzle<T>::Puzzle(string filename)
{
    size = 9;
    
    ifstream infile;
    infile.open(filename.c_str());
    
    SudokuBoardVec.resize(size);
    checkBoard.resize(size);
    
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
        checkBoard.push_back(vector<oneVector>());
        for(int j=0; j<size; j++)
        {
            checkBoard[i].push_back(oneVector());
            for(int k=1; k<size; k++)
            {
                checkBoard[i][j].push_back(k);
            }
        }
    }
    
}

/*template<typename T>
 void Puzzle<T>::printPuzzleBoard()
 {
 for(int i=0; i<size; i++)
 {
 for(int j=0; j<size; j++)
 {
 if(SudokuBoardVecVec[i][j] == 0)
 {
 cout << " ";
 }
 
 else
 {
 cout << SudokuBoardVecVec[i][j] << " ";
 }
 }
 
 cout << endl;
 }
 
 } */

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
    
    if(SudokuBoardVec[xcoord][ycoord] != 0)
    {
        cout << "Error! Spot already has a number! Try again.\n" <<endl;
        display();
        numPlacement();
    }
    
    if(checkPlacement(xcoord, ycoord, num))
    {
        SudokuBoardVec[xcoord][ycoord] == num;
        display();
        numPlacement();
    }
}


template<typename T>
int Puzzle<T>::checkPlacement(int xcoord, int ycoord, int num)
{
    size = 9;
    for(int i=0; i<size; i++)
    {
        if(num == SudokuBoardVec[xcoord][i] && xcoord!=i)
        {
            error();
            return 0;
        }
        
        if(num == SudokuBoardVec[i][ycoord] && ycoord!=i)
        {
            error();
            return 0;
        }
        
    }
    
    for(int j=xcoord; j<(xcoord+3); j++)
    {
        for(int k=ycoord; k<(ycoord+3); k++)
        {
            if(num == SudokuBoardVec[j][k] && xcoord !=j && ycoord !=k)
            {
                error();
                return 0;
            }
        }
    }
    
    return 1;
    
}

template<typename T>
void Puzzle<T>::error()
{
    cout << "Error! Number already used in puzzle!" <<endl;
    numPlacement();
}

template<typename T>
void Puzzle<T>::finished()
{
    int done = 0;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(SudokuBoardVec[i][j] == 0)
            {
                done = 1;
            }
        }
    }
    if(done = 1)
    {
        cout<<"Board full!"<<endl;
    }
}