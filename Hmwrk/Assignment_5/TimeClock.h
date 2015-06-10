/* 
 * File:   TimeClock.h
 * Author: Nornubari Kanabolo
 *
 */

#ifndef TIMECLOCK_H
#define	TIMECLOCK_H

#include "MilTime.h"

class TimeClock : public MilTime
{
    public:
        //Constructor
        TimeClock(int start, int end)
        {
            calcTimeElapsed(start, end);
        }
        
        //Function to calculate the time elapsed
        void calcTimeElapsed(int, int);
};


#endif	/* TIMECLOCK_H */

