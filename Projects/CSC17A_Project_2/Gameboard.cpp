#include "Gameboard.h"

Board::Board()
{
    rows = 0;
    columns = 0;
    ships = 0;
}
Board::Board(int ro,int co,int sh)
{
    rows = ro;
    columns = co;
    
    //Exception validation
    if(sh < (ro*co))
    {
        ships = sh;
    }
    else
        throw InvalidInput();
}
        
//Mutators
void Board::setRows(int ro)
{
    rows = ro;
}
void Board::setCols(int co)
{
    columns = co;
}
void Board::setShips(int sh)
{
    //Exception validation
    if( sh < (rows * columns))
    {
        ships = sh;
    }
    else
        throw InvalidInput();
}
        
//Accessors
int Board::getRows() const{ return rows;}
int Board::getCols() const { return columns;}
int Board::getShips() const { return ships;}
