
#include <iostream>
#include "Victor.h"

using namespace std;

void Victor::getRslt()
{
    
    if(usrPnts > enmyPnts)
    {
        cout<<"You sunk " << enmyPnts << " enemy ships" << endl;
        cout<<"The enemy only sunk " << usrPnts << " of your ships" << endl;
    }
    if(usrPnts < enmyPnts)
    {
        cout<<"You only sunk " << enmyPnts << " enemy ships" << endl;
        cout<<"The enemy only sunk " << usrPnts << " of your ships" << endl;
    }  
}