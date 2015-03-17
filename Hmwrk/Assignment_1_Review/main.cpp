/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis and Savitch Assignment 1 Review Problems
 * Created on March 11, 2015, 8:47 PM
 */

//User Defined Libraries
#include <iostream>
#include<iomanip>
#include<cmath>
#include <cstdlib>
using namespace std;

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
//Main menu setup and output
    unsigned short m_choice;
    bool m_running = true; //The status of the menu loop
    //Enter menu loop
    while (m_running) {
        cout<<"1.  Savitch, 8thEd, Chapter 3, Problem 12\n";
        cout<<"2.  Gaddis, 8thEd, Chapter 3, Problem 13\n";
        cout<<"3.  Gaddis, 8thEd, Chapter 4, Problem 10\n";
        cout<<"4.  Gaddis, 8thEd, Chapter 5, Problem 11\n";
        cout<<"5.  \n";
        cout<<"6.  \n";
        cout<<"7.  \n";
        cout<<"8. Quit the program\n";
        cout << "Enter an integer from 1 to 8 to select an option above: ";
        cin>>m_choice;
        cout<<endl;
        
        //Begin menu
        switch(m_choice){
            case(1):{
                //Problem 1
                //Declare variables
                bool running = true;

                //Inputs
                int x_terms;
                char proceed;//If user wants to continue
                //Outputs
                float pi_aproxim;
                while(running) {
                    //Starting approximation of pi
                    pi_aproxim = 0;
                    cout<<"Enter the number of terms you want to approximate pi with: ";
                    cin>>x_terms;
                    cout<<endl;    
                    //Calculate
                    for(x_terms;x_terms>=0;x_terms--) {
                        pi_aproxim+=(pow(-1,x_terms))/(2*x_terms+1);
                    }
                    pi_aproxim*=4;
                    cout<<"The approximate value of pi is: "<<pi_aproxim<<endl;

                    //Run Again
                    cout<<"Want to approximation pi again?\n";
                    cout<<"If yes, press Y then Return: ";
                    cin>>proceed;
                    cout<<endl;
                    running=(proceed=='Y'||proceed=='y'); 
                }

                //End problem 1
                break;
            }
            case(2):{
                //Problem 2
                //Declare Variables
                float amount, yen_conv, euro_conv;
                
                //Declare constants
                float YEN_PER_DOLLAR=121.28;    //Yen per dollar conversion factor
                float EUROS_PER_DOLLAR=0.95;    //Euro per dollar conversion factor
                
                cout<<"Enter the amount of U.S. Dollars you wish to convert to Yen and Euros\n\n";
                cin>>amount;    //input of the amount of U.S Dollars
                
                cout<<setprecision(2)<<fixed<<showpoint;
                cout<<setw(8);
                yen_conv=amount*YEN_PER_DOLLAR;    //converts U.S. Dollar to Yen
                euro_conv= amount*EUROS_PER_DOLLAR;//converts U.S. Dollar to Euro
                cout<<"The amount of Yen this equals is :     $"<<yen_conv<<"\n";   //output the amount of Yen converted
                cout<<"The amount of Euros this equals is :   $"<<euro_conv<<"\n\n";//output the amount of Euros converted
                
                //End problem 2
                break;
            }
            case(3):{
                //Problem 3
                //Declare Variables
                int month, year;
                
                cout<<"Select a month by entering a number from 1-12: ";
                cin>>month;
                cout<<"Enter a year: ";
                cin>>year;
                cout<<endl;
                
                if (month==1)
                    cout<<"January has 31 days\n\n";
                if (month==2&&year%100==0 &&year%400==0)
                    cout<<"For this year, February has 29 days\n\n";
                else if (month==2&&year%100>0&&year%4==0)
                    cout<<"For this year, February has 29 days\n\n";
                else if (month==2&&year%100>0 &&year%400>0&&year%4>0)
                    cout<<"For this year, February has 28 days\n\n";
                if (month ==3)
                    cout<<"March has 31 days\n\n";
                else if (month == 4)
                    cout<<"April has 30 days\n\n";
                else if (month == 5)
                    cout<<"May has 31 days\n\n";
                else if (month == 6)
                    cout<<"June has 30 days\n\n";
                else if (month == 7)
                    cout<<"July has 31 days\n\n";
                else if (month == 8)
                    cout<<"August has 31 days\n\n";
                else if (month == 9)
                    cout<<"September has 30 days\n\n";
                else if (month == 10)
                    cout<<"October has 31 days\n\n";
                else if (month == 11)
                    cout<<"November has 30 days\n\n";
                else if (month == 12)
                    cout<<"December has 31 days\n\n";
                
                //End problem 3
                break;
            }
            case(4):{
                //Problem 4
                //Declare variables
                float start, incrRte, days, popGrow;
                cout<<"Enter the starting population: ";
                cin>>start;
                cout<<endl;
                cout<<"Enter the rate of increase of population as a percent: ";
                cin>>incrRte;
                cout<<endl;
                cout<<"Enter number of days of growth: ";
                cin>>days;
                cout<<endl;
                
                if (start >= 2&& incrRte >= 0 && days >= 1){
                    popGrow= start+(start*(incrRte/100)*days);
                    cout<<"The population grew to " << popGrow << " organisms!\n\n";
                }
                else
                    cout<<"Incorrect input values\n\n";
                
                //End problem 4
                break;
            }
            case(5):{
                //Problem 5
                
                //End problem 5
                break;
            }
            case(6):{
                //Problem 6
                
                //End problem 6
                break;
            }
            case(7):
            {
                //Problem 7
                
                //End problem 7
                break;
            
            default:
                cout<<"Unknown input, please try again.\n\n";
        }
        }}
    //Exit program
    cout << "Now exiting program\n";
    return 0;
}
