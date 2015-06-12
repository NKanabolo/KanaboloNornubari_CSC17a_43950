/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * CSC 17A Project 2 - War of Ships V. 2
 */



using namespace std;
//User Defined Libraries
#include <iomanip>
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <fstream>

//Classes
#include "User.h"
#include "Victor.h"

//Function prototypes

//Prints the beginning to the game
void begin();
//Prints the starting board
void prntBrd(User);
//Gets input and prints user board
void userBoard(int, int, char**);
//Gets input and prints enemy board
void enmyBoard(int, int, char**);
//Checks for a victor
bool victory(int, int, int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    int row = 0;         //User input for rows
    int column = 0;      //User input for columns
    int ship = 0;        //User input for ships amount
    int usrRow = 0;      //User rows
    int usrColumn = 0;   //User columns
    int enmyRow = 0;     //Enemy rows
    int enmyCol = 0;     //Enemy columns
    char **usr;          //Pointer array for User board
    char **enemy;        //Pointer array for enemy board
    int usrPnts = 0;     //Counter for number of ships sunk by user
    int enmyPnts = 0;    //Counter for number of ships sunk by enemy
        
    //Set random number seed
    srand(time(0));

    //Calling the begin function
    begin();

    //Getting input to make the board
    cout << endl << "Enter the amount of rows you want the board to be: ";
    cin >> row;
    cout << "Enter the amount of columns you want the board to be: ";
    cin >> column;
    cout << "Enter the amount of ships you want to use in the game: ";
    cin >> ship;
    
    //Initializing class object
    User battle;
    
    //Declaring class object with exceptions
    try
    {
        battle.setRows(row);
        battle.setCols(column);
        battle.setShips(ship);
    }
    catch(Board::InvalidInput)
    {
        cout << endl << "You can't have that many ships. Enter a valid amount" << endl;
        cout << "Please enter how many ships you want: ";
        cin >> ship;
        battle.setShips(ship);
    }
    
    //Calls the function that prints the reference board
    prntBrd(battle);
    
    //Initializing the blind board for the enemy to hide the real board
    char invisBrd[battle.getRows()][battle.getCols()];  
    
    //Resizing the pointer array to hold the user board
    usr = new char*[battle.getRows()];
    for(int i = 0; i < battle.getRows(); ++i)
    {
        usr[i] = new char[battle.getCols()];
    }
    //Calling the getUsr function from the class User and store the value into the user pointer array
    usr = battle.getUsr();
    
    //Resizing the pointer array to hold the enemy board
    enemy = new char*[battle.getRows()];
    for(int i = 0; i < battle.getRows(); ++i)
    {
        enemy[i] = new char[battle.getCols()];
    }
    //Calling the getEnmy function from the class User and store the value into the enemy pointer array
    enemy = battle.getEnmy();
    
    //Setting invisBrd array with empty spaces
    for(int i = 0; i < battle.getRows(); i++)
    {
        for(int j = 0; j < battle.getCols(); j++)
        {
            invisBrd[i][j] = ' ';
        }
    }
    
    //Move loop
    while(usrPnts <= battle.getShips() || enmyPnts <= battle.getShips())
    {
        userBoard(battle.getRows(), battle.getCols(), usr);
        
        //Printing the user board
        cout << endl << "User Board" << endl;
        for(int i = 0; i < battle.getCols(); i++)
        {
            cout << "     " << i+1;
        }
        cout << endl;
        for(int i = 0; i < battle.getRows(); i++)
        {
            cout << "  ";
            for(int j = 0; j < battle.getCols(); j++)
            {
                cout << "|-----";
            }
            cout << "|" << endl;
            cout << i+1 << " ";
            for(int j = 0; j < battle.getCols(); j++)
            {
                cout << "|  " << usr[i][j] << "  ";
            }
            cout << "|" << endl;
        }
        cout << "  ";
        for(int j = 0; j < battle.getCols(); j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl << endl;
    
        enmyBoard(battle.getRows(), battle.getCols(), enemy);
        
        //Printing the enemy board
        cout << "Enemy Board" << endl;
        for(int i = 0; i < battle.getCols(); i++)
        {
            cout << "     " << i+1;
        }
        cout << endl;
        for(int i = 0; i < battle.getRows(); i++)
        {
            cout << "  ";
            for(int j = 0; j < battle.getCols(); j++)
            {
                cout << "|-----";
            }
            cout << "|" << endl;
            cout << i+1 << " ";
            for(int j = 0; j < battle.getCols(); j++)
            {
                cout << "|  " << invisBrd[i][j] << "  ";
            }
            cout << "|" << endl;
        }
        cout << "  ";
        for(int j = 0; j < battle.getCols(); j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl;
    
        //Finding victor by calling the victory function
        if(victory(usrPnts, enmyPnts, battle.getShips()) == true)
        {
            break;
        }
    
        //Getting coordinates to attack
        cout << endl << "What are the coordinates to launch an attack ?" << endl;
        cout << "Row: ";
        cin >> usrRow;
        while(usrRow <= 0 ||usrRow > battle.getRows())
        {
            cout << endl << "Invalid input!" << endl;
            cout << "Row: ";
            cin >> usrRow;
        }
        cout << "Column: ";
        cin >> usrColumn; 
        while(usrColumn <= 0 || usrColumn > battle.getCols())
        {
            cout << endl << "Invalid input!" << endl;
            cout << "Column: ";
            cin >> usrColumn;
        }
        
       //Validating user moves
        if( enemy[usrRow-1][usrColumn-1] == ' ')
        {
            enemy[usrRow-1][usrColumn-1] = 'X';
            invisBrd[usrRow-1][usrColumn-1] = 'X';
            cout << endl << "You missed!";
        }
        else if( enemy[usrRow-1][usrColumn-1] == 'O')
        {
            enemy[usrRow-1][usrColumn-1] = '#';
            invisBrd[usrRow-1][usrColumn-1] = '#';
            cout << endl << "Great job, captain!You hit one";
            usrPnts++;
        }
        else if( enemy[usrRow-1][usrColumn-1] == 'X' || enemy[usrRow-1][usrColumn-1] == '#')
        {
            cout << endl << "Captain, we chose that spot already. Get your head in the game!";
        }
        
        //Getting randomly generated input for the enemy moves
        enmyRow = (rand() % battle.getRows());
        enmyCol = (rand() % battle.getCols());
            
        //Validating enemy moves
        if( usr[enmyRow][enmyCol] == 'O')
        {
            usr[enmyRow][enmyCol] = '#';
            cout << endl << "We've been hit, Captain!";
            enmyPnts++;
        }
        else if( usr[enmyRow][enmyCol] == ' ')
        {
            usr[enmyRow][enmyCol] = 'X';
        }
        else if(enemy[enmyRow][enmyCol] == 'X' || 
                enemy[enmyRow][enmyCol] == '#')
        {
            cout << endl << "They missed, make them pay for their mistakes";
        }
    }
    
    cout << endl << "The crew thanks yee for the leadership you have shown us. Maybe our paths will cross again one day." << endl;
   
    //Template 
    //Victor result(usrPnts, enmyPnts);
    //result.getRslt();
    
    //Delete user pointer arrays
    for (int i = 0; i < battle.getCols(); i++)
    {
        delete[] usr[i];
    }
    delete [] usr;
    //Delete enemy pointer arrays
    for (int i = 0; i < battle.getCols(); i++)
    {
        delete[] enemy[i];
    }
    delete [] enemy;
    return 0;
}
void begin()
{
  string line;
  ifstream begin ("begin.txt");
  
  if (begin.is_open())
  {
    while ( getline (begin,line) )
    {
      cout << line << '\n';
    }
    begin.close();
  }
  else cout << "Unable to open file";
}

void prntBrd(User a)
{
    //Prints board for User to place ships
    //Declare variables
    char start = ' ';
    
    cout << endl << "Game Board" << endl;
    for(int i = 0; i < a.getCols(); i++)
    {
        cout << "     " << i+1;
    }
    cout << endl;
    for(int i = 0; i < a.getRows(); i++)
    {
        cout << "  ";
        for(int j = 0; j < a.getCols(); j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl;
        cout << i+1 << " ";
        for(int j = 0; j < a.getCols(); j++)
        {
            cout << "|  " << start << "  ";
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for(int j = 0; j < a.getCols(); j++)
    {
        cout << "|-----";
    }
    cout << "|" << endl;
    
}
//Function that checks for a victor
bool victory(int usr, int enemy, int ships)
{
    bool vic = false;
    
        if(usr == ships)
        {
            cout << endl << "Great job, Captain!! You are victorious!" << endl;
            vic = true;
        }
        if(enemy == ships)
        {
            cout << endl << "Captain...How could you allow the enemy to win?" << endl;
            vic = true;
        }
    
    return vic;
}

void userBoard(int, int, char**){
    
}
//Gets input and prints enemy board
void enmyBoard(int, int, char**){
    
}