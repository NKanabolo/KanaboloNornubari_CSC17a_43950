#include "Employee.h"

//Default constructor
Employee::Employee()
{
    empName = " ";
    empId = 0;
    empHire = " ";
}

//Constructor with inputs
Employee::Employee(string name,int id,string hire)
{
    empName = name;
    empId = id;
    empHire = hire;
}
             
//Accessors
string Employee::getName() const { return empName;}
int Employee::getId() const { return empId;}
string Employee::getHire() const { return empHire;}
