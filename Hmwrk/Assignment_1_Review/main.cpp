/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis and Savitch Assignment 1 Review Problems
 * Created on March 11, 2015, 8:47 PM
 */

//User Defined Libraries
#include <iostream>
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
        cout<<"2.  \n";
        cout<<"3.  \n";
        cout<<"4.  \n";
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
                
                
                break;
            }
            case(3):{
                //Problem 3
                
                
                break;
            }
            case(4):{
                //Problem 4
                
                break;
            }
            case(5):{
                
                break;
            }
            case(6):{
                //Problem 6
                
                break;
            }
            case(7):
            {
                //Problem 7
                
                break;
            
            default:
                cout<<"Unknown input, please try again.\n\n";
        }
        }}
    //Exit program
    cout << "Now exiting program\n";
    return 0;
}
