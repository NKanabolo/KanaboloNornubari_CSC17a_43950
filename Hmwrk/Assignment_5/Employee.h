/* 
 * File:   Employee.h
 * Author: Nornubari Kanabolo
 *
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include <string>

using namespace std;

class Employee 
{
    private:
        string empName;   //Holds employee name
        int empId;        //Holds employee ID number
        string empHire;   //Holds employee hire date
    public:
        //Constructor
        Employee();                    //Default constructor
        Employee(string,int,string);   //Constructor using input
        
        //Accessors
        string getName() const;
        int getId() const;
        string getHire() const;
};

#endif	/* EMPLOYEE_H */

