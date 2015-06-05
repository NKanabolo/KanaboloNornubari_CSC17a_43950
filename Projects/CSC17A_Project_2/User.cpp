#include <iostream>
#include <cstdlib> 
#include "User.h"

using namespace std;

//Ask for user input and put in an array
char **User::getUsr()
{
    //Getting input form the Board object
    int rows = getRows();
    int columns = getCols();
    int ships = getShips();
    
    //Resize pointer array
    userBoard = new char*[rows];
    for(int i = 0; i < rows; ++i)
    {
        userBoard[i] = new char[columns];
    }
        
    int tempRow = 0;     //Temporary int for row
    int tempCol = 0;     //Temporary int for column
    bool validLoc = true;//Bool to check for valid input
    
    
    
    //Put array spaces to ' '
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            userBoard[i][j] = ' ';
        }
    }
    
    //Get places for user's ships
    cout << endl << "Put your "<< ships << " ships on the board" << endl;
    
    for(int i = 0; i < ships; i++)
    {
        do
        {
            cout << endl << "Ship " << i+1 << endl;
            cout << "Row: ";
            cin >> tempRow;
            while(tempRow <= 0 ||tempRow > rows)
            {
                cout << endl << "Invalid input!" << endl;
                cout << "Row: ";
                cin >> tempRow;
            }
            cout << "Column: ";
            cin >> tempCol;
            while(tempCol <= 0 ||tempCol > columns)
            {
                cout << endl << "Invalid input!" << endl;
                cout << "Column: ";
                cin >> tempCol;
            }
    
            //Check if space is valid
            if(userBoard[tempRow-1][tempCol-1] == 'O')
            {
                validLoc = false;
                cout << endl << "You already have a ship there!" << endl;
            }
            else
            {
                userBoard[tempRow-1][tempCol-1] = 'O';
            }
        }while(validLoc == false);
    }
  
    return userBoard;
}

//Generates random input and stores in an array
char **User::getEnmy()
{
    //Getting input form the Board object
    int rows = getRows();
    int columns = getCols();
    int ships = getShips();
    
    //Resize pointer array
    enmyBoard = new char*[rows];
    for(int i = 0; i < rows; ++i)
    {
        enmyBoard[i] = new char[columns];
    }
    
    //Setting all the array spaces to ' '
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            enmyBoard[i][j] = ' ';
        }
    }
    
    int tempRow = 0;     //Temp int for the row
    int tempCol = 0;     //Temp int for the column
    bool validLoc = true;//Check if input valid
        
        
     //Enemy randomly selects its ships position
    for(int i = 0; i < ships; i++)
    {
        do
        {
            tempRow = (rand() % rows);
            tempCol = (rand() % columns);
            
            if(enmyBoard[tempRow][tempCol] == 'O')
            {
                validLoc = false;
            }
            else
            {
                enmyBoard[tempRow][tempCol] = 'O';
            }
        }while(validLoc == false);
    }
    
    return enmyBoard;
}
