/* 
 * File:   Widget.h
 * Author: Nornubari's Laptop
 *
 * Created on June 9, 2015, 7:54 PM
 */

#ifndef WIDGET_H
#define	WIDGET_H

class Widget {
    private:
        int shiftHours;      //Shift hours per day(16)
        int widgetHour;      //Widgets produced per hour (10)
        float widgetOrder;   //Number of widgets ordered
        float days;          //Days to complete the order
    public:
        Widget();                 //Constructor to declare arguments
        void getWidgets(float);   //Mutator to get the number of widgets
        float getDays();          //Accessor to return the number of days
};


#endif	/* WIDGET_H */

