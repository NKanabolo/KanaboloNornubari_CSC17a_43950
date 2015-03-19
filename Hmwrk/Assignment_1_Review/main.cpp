/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Gaddis and Savitch Assignment 1 Review Problems
 * Created on March 11, 2015, 8:47 PM
 */

//User Defined Libraries
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;

//Function Prototypes
float celcius(int fhnt);
void prntArr(string names[], int length);
int binSearch(string names[], int NUM_NAMES, string trgt); //search for the number 50 in one dimensional array
int prntbinSrch(string names[], int NUM_NAMES, string trgt); //print binary search results
void bSort(string names[], int NUM_NAMES);
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
                    cout<<"Incorrect input value(s)\n\n";
                
                //End problem 4
                break;
            }
            case(5):{
                //Problem 5
                for (int fhnt=0;fhnt<=20;fhnt++)
                cout<<"  "<<fhnt<<"     "<<celcius(fhnt)<<endl;
                //End problem 5
                break;
            }
            case(6):{
                //Problem 6
                int scount=0, ccount=0, rcount=0;
                char a[3][30];
                int b[3][3];
                ifstream infile;
                infile.open("RainOrShine.txt");
                for (int i=0; i<3;i++){
                    for(int j=0; j<30;j++){
                        infile>>a[i][j];
                        cout<<a[i][j]<<" ";}
                cout<<endl;}
                cout<<endl<<endl<<"   S    C    R\n";
                for (int i=0;i<3;i++){
                    for (int j=0;j<30;j++){
                        if (a[i][j] == 'S')
                            scount++;
                        else if (a[i][j] == 'C')
                            ccount++;
                        else
                            rcount++;
                    }
                    b[i][0]=scount;
                    b[i][1]=ccount;
                    b[i][2]=rcount;
                    scount=0;
                    ccount=0;
                    rcount=0;
                    
                }
                for (int i=0;i<3;i++){
                    for (int j=0;j<3;j++){
                        cout<<setw(4)<<b[i][j]<<" ";
                    }
                    cout<<endl;
                }
                
                //End problem 6
                break;
            }
            case(7):
            {
                //Problem 7
                 string names[5] = {"Nornubari Kanabolo,", "Joseph Levin,", "Mark Lehr,", "G2 Caddel,", "Bae,"};
                 bSort(names, 5);
                 prntArr(names, 5);
                 prntbinSrch(names, 5, "Nornubari Kanabolo");
                //End problem 7
                break;
            }
            default:
                cout<<"Unknown input, please try again.\n\n";
        }
        }
    //Exit program
    cout << "Now exiting program\n";
    return 0;
}

float celcius(int fhnt)
{
    float celTemp;
    celTemp= (5.0/9.0)*(fhnt-32.0);
    return celTemp;
    
}

void prntArr(string names[], int length)
{
	for(int i=0; i<length; i++) //form a one dimensional array
	{ 
            names[i] = 5; //controls range of of numbers used. 10-100
            cout << names[i] << " "; //prints each number of array
	}
	cout << endl << endl;
	
}

void bSort(string names[], int n)
{
    string temp; //Declare variables
    for(int i=0;i<n;i++) //sort the one dimensional array
    {
       for(int j=0;j<(n-1);j++) //organize array by looking at each column
            if(names[j]>names[j+1]) //if first number is greater than the next then switch 
                            //them and continue across rest of array
           {
               temp=names[j]; //swap values
               names[j]=names[j+1];
               names[j+1]=temp;
           }
    }
    for(int i=0;i<n;i++) //print each sorted number
        cout<<names[i]<<" ";
    cout<< endl<< endl;
}

int binSearch(string names[], int n, string trgt)
{
    int mid, lowbound= 0, hghbound=n-1; //Declare variables
    while (lowbound <= hghbound) 
    {
         int mid = (lowbound + hghbound)/2; //find middle sorted number in one dimensional array
         if (names[mid] == trgt) //if selected middle value is the target then it is found
             return mid;
         else if (names[mid] < trgt) 
             lowbound = mid + 1; //if selected middle is less than target, then next number is beginning of next search
         else hghbound = mid - 1; //if selected middle is more than target, then previous number is end of next search
    }
      return -1;
    
}

int prntbinSrch(string names[], int n, string trgt)
{
    string found; //Declare variables
    found=binSearch(names, n, trgt); //call binary search function
    if (found=="Nornubari Kanabolo") //if value found is not the returned value then say the number was not found, otherwise, it is found
        cout << endl << "The number 50 was not found" << endl;
    else
        cout << endl << "The number 50 was found at location "<<found << endl;
        
}
