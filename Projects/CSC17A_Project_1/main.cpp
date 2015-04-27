/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Project 1 - War of Ships
 */

//User Defined Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//Function Prototypes

//Prints the beginning to the game
void begin();
//Prints the starting board
void prntBrd(Board);
//Gets the ships position in the board
Players **usrInp(Board);

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare structures
    Board game;       //Structure that holds the board dimensions
    Players **boards; //Structure that composes the players boards
    
    //Call beginning function
    begin();
    
    //Getting input to make the board
    cout << endl << "Enter the number of rows you want the board to be: ";
    cin >> game.rows;
    cout << endl << "Enter the number of columns you want the board to be: ";
    cin >> game.columns;
    cout << endl << "Enter the number of ships you want to use in the game: ";
    cin >> game.ships;
    
    //Calls the function that prints the board
    prntBrd(game);
    
    //Resizing array
    boards = new Players*[game.rows];
    for(int i = 0; i < game.rows; ++i)
        boards[i] = new Players[game.columns];
    
    //Retrieve the user's input
    boards = usrInp(game);
    
    return 0;
}

void begin()
{
    //Output the introduction
    cout << endl << endl;
    cout << right << setw(50) << "Welcome to War of Ships!" << endl ;
    cout << endl << "This is a 2 player ship battle game.\n";
    cout << "Guess where your opponent's vessels are and sink them before your opponent sinks yours!\n"; 
    cout << endl;
}


void prntBrd(Board a)
{
    //Prints the empty board
    //Declare variables
    char test = ' ';
    
    cout << endl << "   User's Board" << endl;
    for(int i = 0; i < a.columns; i++)
    {
        cout << "     " << i+1;
    }
    cout << endl;
    for(int i = 0; i < a.rows; i++)
    {
        cout << "  ";
        for(int j = 0; j < a.columns; j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl;
        cout << i+1 << " ";
        for(int j = 0; j < a.columns; j++)
        {
            cout << "|  " << test << "  ";
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for(int j = 0; j < a.columns; j++)
    {
        cout << "|-----";
    }
    cout << "|" << endl;
    
}

Players **usrInp(Board b)
{
    //Declaring dynamic array
    Players **arr;     
    
    arr = new Players*[b.rows];
    for(int i = 0; i < b.rows; ++i)
        arr[i] = new Players[b.columns];
    
    int tRow = 0;      //temporary value for the row
    int tCol = 0;      //temporary value for the column
    bool valLoc = true;//check for valid input
    
    srand(time(0));
    
    //Set array spaces to blank spaces
    for(int i = 0; i < b.rows; i++)
    {
        for(int j = 0; j < b.columns; j++)
        {
            arr[i][j].playrBd = ' ';
            arr[i][j].enemyBd = ' ';
        }
    }
    
    //Get locations for user's ships
    cout << "Put your "<< b.ships << " ships in the board" << endl;
    
    for(int i = 0; i < b.ships; i++)
    {
        do
        {
            cout << endl << "Ship " << i+1 << endl;
            cout << "Row: ";
            cin >> tRow;
            while(tRow <= 0 ||tRow > b.rows)
            {
                cout << endl << "Invalid input!" << endl;
                cout << "Row: ";
                cin >> tRow;
            }
            cout << "Column: ";
            cin >> tCol;
            while(tCol <= 0 ||tCol > b.columns)
            {
                cout << endl << "Invalid input!" << endl;
                cout << "Row: ";
                cin >> tCol;
            }
    
            //Check if position is valid
            if(arr[tRow-1][tCol-1].playrBd == 'O')
            {
                valLoc = false;
                cout << endl << "You already have a ship there!" << endl;
            }
            else
            {
                arr[tRow-1][tCol-1].playrBd = 'O';
            }
        }while(valLoc == false);
    }
    
    //Enemy randomly selects ship position
    for(int i = 0; i < b.ships; i++)
    {
        do
        {
            tRow = (rand() % b.rows);
            tCol = (rand() % b.columns);
            
            if(arr[tRow][tCol].enemyBd == 'O')
            {
                valLoc = false;
            }
            else
            {
                arr[tRow][tCol].enemyBd = 'O';
            }
        }while(valLoc == false);
    }
    
    
    return arr;//Return array with position of ship
}