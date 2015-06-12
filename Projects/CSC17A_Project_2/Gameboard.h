/* 
 * File:   Gameboard.h
 * Author: Nornubari Kanabolo
 */

#ifndef GAMEBOARD_H
#define	GAMEBOARD_H

class Board 
{
    private:
        int rows;     //Amount of rows in the board
        int columns;  //Amount of columns in the board
        int ships;    //Amount of ships in the board
    public:
        //Constructor
        Board();              //Default constructor
        Board(int,int,int);   //Constructor using input
        //Exceptions
        class InvalidInput{};
        
        //Mutators
        void setRows(int);
        void setCols(int);
        void setShips(int);
        
        //Accessors
        int getRows() const;
        int getCols() const;
        int getShips() const;

};


#endif	/* GAMEBOARD_H */

