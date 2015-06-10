/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Assignment 5
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

//Classes 
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
#include "MilTime.h"
#include "TimeClock.h"

using namespace std;

//Problems Prototypes
void Menu();
int getN();
void def(int);
void problem1();   //Chapter 15 Problem 1
void problem2();   //Chapter 15 Problem 2
void problem3();   //Chapter 15 Problem 3
void problem4();   //Chapter 15 Problem 4
void problem5();   //Chapter 15 Problem 5

//Begin Execution Here!!!
int main(int argv,char *argc[])
{
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;   //Chapter 15 Problem 1
        case 2:    problem2();break;   //Chapter 15 Problem 2
        case 3:    problem3();break;   //Chapter 15 Problem 3
        case 4:    problem4();break;   //Chapter 15 Problem 4
        case 5:    problem5();break;   //Chapter 15 Problem 5
        default:   def(inN);}
    }while(inN>=1&&inN<=5);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for assignment 5"<<endl;
    cout<<"1.  Gaddis, 8thEd, Chapter 15, Problem 1"<<endl;
    cout<<"2.  Gaddis, 8thEd, Chapter 15, Problem 2"<<endl;
    cout<<"3.  Gaddis, 8thEd, Chapter 15, Problem 3"<<endl;
    cout<<"4.  Gaddis, 8thEd, Chapter 15, Problem 4"<<endl;
    cout<<"5.  Gaddis, 8thEd, Chapter 15, Problem 5"<<endl;
    cout<<"Press any key and then Enter to exit.\n"<<endl;}

int getN(){
        int inN;
        cin>>inN;
        return inN;}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Chapter 15 Problem 1
void problem1()
{
    string name = " ";    //Holds employee name
    int id = 0;           //Holds employee ID number
    string hire = " ";    //Holds employee hire date
    int shift  = 0;       //Holds employee shifts 1 = day, 2 = night
    float payRate  = 0;   //Holds employee hourly pay rate

    //User input for the Employee class
    cout << "Enter the employee's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the employee's ID number: ";
    cin >> id;
    cout << "Enter the employee's hire date (mm/dd/yyyy format): ";
    cin.ignore();
    getline(cin, hire);

    //User input for the ProductionWorker class
    cout << "\nEnter " << name << "'s shift (1 = day, 2 = night): ";
    cin >> shift;
    cout << "Enter " << name << "'s hourly pay rate: ";
    cin >> payRate;

    //Set inputs
    ProductionWorker worker(name, id, hire, shift, payRate);

    //Output data
    cout << "\nEmployee's information: " << endl;
    cout << "Name: "  << worker.getName()  << endl;
    cout << "Number : "   << worker.getId()   << endl;
    cout << "Hire date: " << worker.getHire() << endl;
    cout << "Shift: " << worker.getShift() << endl;
    cout << "Hourly pay rate: " << worker.getPayRate() << endl;
    cout << endl;
}

//Chapter 15 Problem 2
void problem2()
{
    string name = " ";    //Holds employee name
    int id = 0;           //Holds employee ID number
    string hire = " ";    //Holds employee hire date
    float salary  = 0;    //Holds employee annual salary
    float bonus  = 0;     //Holds employee end of year bonus

    //User input for the Employee class
    cout << "Enter the employee's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the employee's ID number: ";
    cin >> id;
    cout << "Enter the employee's hire date (mm/dd/yyyy format): ";
    cin.ignore();
    getline(cin, hire);

    //User input for the ProductionWorker class
    cout << "\nEnter " << name << "'s annual salary: ";
    cin >> salary;
    cout << "Enter " << name << "'s end of year bonus: ";
    cin >> bonus;

    //Set inputs
    ShiftSupervisor worker2(name, id, hire, salary, bonus);

    //Output data
    cout << "\nEmployee's information: " << endl;
    cout << "Name: "  << worker2.getName()  << endl;
    cout << "Number : "   << worker2.getId()   << endl;
    cout << "Hire date: " << worker2.getHire() << endl;
    cout << "Annual salary: " << worker2.getSalary() << endl;
    cout << "End of year bonus: " << worker2.getBonus() << endl;
    cout << endl; 
}

//Chapter 15 Problem 3
void problem3()
{
    string name = " ";          //Holds employee name
    int id = 0;                 //Holds employee ID number
    string hire = " ";          //Holds employee hire date
    int shift  = 0;             //Holds employee shifts 1 = day, 2 = night
    float payRate  = 0.0;       //Holds employee hourly pay rate
    float amountBonus = 0.0;    //Bonus amount if completed hours
    float hoursReq = 0.0;       //Required hours to get the bonus
    float hoursAttend = 0.0;    //Hours attended by the employee

    //User input for the Employee class
    cout << "Enter the employee's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the employee's ID number: ";
    cin >> id;
    cout << "Enter the employee's hire date (mm/dd/yyyy format): ";
    cin.ignore();
    getline(cin, hire);

    //User input for the ProductionWorker class
    cout << "\nEnter " << name << "'s shift (1 = day, 2 = night): ";
    cin >> shift;
    cout << "Enter " << name << "'s hourly pay rate: ";
    cin >> payRate;
    
    //User input for the TeamLeader class
    cout << "\nEnter the bonus amount: ";
    cin >> amountBonus;
    cout << "Enter the required hours to earn the bonus: ";
    cin >> hoursReq;
    cout << "Enter " << name << "'s completed hours: ";
    cin >> hoursAttend;

    //Set inputs
    TeamLeader worker3(name, id, hire, shift, payRate, amountBonus, hoursReq, hoursAttend);
    
    //Calling function from the TeamLeader class to calculate the total pay
    worker3.calcTotal();

    //Output data
    cout << "\nEmployee's information: " << endl;
    cout << "Name: "  << worker3.getName()  << endl;
    cout << "Number : "   << worker3.getId()   << endl;
    cout << "Hire date: " << worker3.getHire() << endl;
    cout << "Shift: " << worker3.getShift() << endl;
    cout << "Hourly pay rate: " << worker3.getPayRate() << endl;
    cout << "Hours worked: " << worker3.getAttendHours() << endl;
    cout << "Total payment including bonus: " << worker3.getTotal() << endl;
    cout << endl;
}

//Chapter 15 Problem 4
void problem4()
{
    int mHours = 0;     //Military time
    int mSeconds = 0;   //Military seconds
    
    //Requesting input with validation
    cout << "\nEnter the military time you want to convert to standard time: ";
    cin >> mHours;
    while(mHours < 0 || mHours > 2359 || (mHours%100) < 0 ||(mHours%100) > 59)
    {
        cout << "\nERROR! Hours must be 0 - 2359 with minutes 0 - 59" << endl;
        cout << "Enter the military time you want to convert to standard time: ";
        cin >> mHours;
    }
    cout << "Enter the seconds: ";
    cin >> mSeconds;
    while(mSeconds < 0 || mSeconds > 59)
    {
        cout << "\nERROR! Seconds must be 0 - 59" << endl;
        cout << "Enter the seconds: ";
        cin >> mSeconds;
    }
    
    //Declaring class object
    MilTime time(mHours, mSeconds);
    
    //Printing output
    cout << "\nMilitary time: " << time.getMilHours() << ":" 
         << time.getMilSeconds() << endl;
    cout << "Standard time: " << time.getHour() << ":" << time.getMinutes()
         << ":" << time.getSeconds() <<" "<< time.getMeridiem() << endl << endl;
}

//Chapter 15 Problem 5
void problem5()
{
    int time1 = 0;   //Starting military time
    int time2 = 0;   //Ending military time
    
    //Requesting input with validation
    cout << "\nEnter the starting time in military format: ";
    cin >> time1;
    while(time1 < 0 || time1 > 2359 || (time1%100) < 0 ||(time1%100) > 59)
    {
        cout << "\nERROR! time must be 0 - 2359 with minutes 0 - 59" << endl;
        cout << "Enter the starting time in military format: ";
        cin >> time1;
    }
    cout << "Enter the ending time in military format: ";
    cin >> time2;
    while(time2 < 0 || time2 > 2359 || (time2%100) < 0 ||(time2%100) > 59)
    {
        cout << "\nERROR! time must be 0 - 2359 with minutes 0 - 59" << endl;
        cout << "Enter the ending time in military format: ";
        cin >> time2;
    }
    
    //Declaring TimeClock object
    TimeClock timeElapsed(time1, time2);
    
    //Printing output
    cout << "\nThe time elapsed between " << time1 << " and " << time2 << " is: "
         << timeElapsed.getHour() << ":" << timeElapsed.getMinutes() 
         <<  " hours." << endl << endl;
}
