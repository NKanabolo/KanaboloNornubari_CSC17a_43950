/* 
 * File:   User.h
 * Author: Nornubari Kanabolo
 */

#ifndef USER_H
#define	USER_H

#include "Gameboard.h"

class User : public Board
{
    private:
        char **userBoard;  //Array with all the player tokens
        char **enmyBoard;   //Array with all the enemy tokens
    public:
        User(){}
        User(int r, int c, int s):Board(r, c, s){}
        
        ~User()
        {
            delete [] userBoard;
            delete [] enmyBoard;
        }
        
        char **getUsr();
        char **getEnmy();
};

#endif	/* USER_H */

