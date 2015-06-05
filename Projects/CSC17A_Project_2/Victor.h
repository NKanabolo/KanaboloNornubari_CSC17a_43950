/* 
 * File:   Victor.h
 * Author: Nornubari's Laptop
 */

#ifndef VICTOR_H
#define	VICTOR_H

class Victor 
{
    private:
        int usrPnts;
        int enmyPnts;
    public:
        Victor()
        {
            usrPnts = 0; 
            enmyPnts = 0;
        }
        Victor(int pl, int en){ usrPnts = pl; enmyPnts = en;}
        void setUsrPnts(int pl){usrPnts = pl;}
        void setEnmyPnts(int en){enmyPnts = en;}
        void getRslt();
};


#endif	/* VICTOR_H */

