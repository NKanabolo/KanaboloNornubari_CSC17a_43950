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

//Execution Begins Here

int main(int argc, char** argv) {
    //Declare headers
    Board game;       //Structure that holds the board dimensions
    Players **boards; //Structure that composes the players boards
    
    //Call beginning functions
    begin();
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
