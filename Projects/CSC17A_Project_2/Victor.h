/* 
 * File:   Victor.h
 * Author: Nornubari Kanabolo
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
        Victor(int us, int en){ usrPnts = us; enmyPnts = en;}
        void setUsrPnts(int us){usrPnts = us;}
        void setEnmyPnts(int en){enmyPnts = en;}
        void getRslt();
};


#endif	/* VICTOR_H */

