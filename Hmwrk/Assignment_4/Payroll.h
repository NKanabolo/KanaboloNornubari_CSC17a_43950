/* 
 * File:   Payroll.h
 * Author: Nornubari's Laptop
 *
 * Created on June 9, 2015, 7:54 PM
 */

#ifndef PAYROLL_H
#define	PAYROLL_H

class Payroll {
    private:
        float payRate;       //Hourly pay rate
        float hoursWorked;   //Hours worked during the week
        float totalPay;      //Total gross pay for the week
    public:
        Payroll();              //Constructor to declare the arguments
        void getRate(float);    //Mutator to get the pay rate
        void getHours(float);   //Mutator to get the hours worked
        float printTotal();     //Accessor to print the total pay for the week
};


#endif	/* PAYROLL_H */

