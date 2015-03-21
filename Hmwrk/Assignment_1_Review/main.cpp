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
float celsius(int fhnt);                                     //converts Fahrenheit to Celsius
void prntArr(string names[], int length);                    //Prints unsorted string array
int binSearch(string names[], int NUM_NAMES, string trgt);   //search for the number 50 in one dimensional array
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
                //Inputs
                cout<<"Select a month by entering a number from 1-12: ";
                cin>>month;     //input month
                cout<<"Enter a year: ";
                cin>>year;      //input year
                cout<<endl;
                
                if (month==1)   //if input=1 then output January
                    cout<<"January has 31 days\n\n";
                if (month==2&&year%100==0 &&year%400==0)    //if input=2, year is divisible by 100 and 400, then output Leap Year
                    cout<<"This year is a Leap Year, so February has 29 days\n\n";
                else if (month==2&&year%100>0&&year%4==0)   //if input=2, year is not divisible by 100, but divisible by 4, then output Leap Year
                    cout<<"This year is a Leap Year, so February has 29 days\n\n";
                else if (month==2&&year%100>0 &&year%400>0&&year%4>0)   //if input=2, year is not divisible by 100 and 400, then output non Leap Year
                    cout<<"For this year, February has 28 days\n\n";
                if (month ==3)      //if input=3 then output March
                    cout<<"March has 31 days\n\n";
                else if (month == 4)//else if input=4 then output April
                    cout<<"April has 30 days\n\n";
                else if (month == 5)//else if input=5 then output May
                    cout<<"May has 31 days\n\n";
                else if (month == 6)//else if input=6 then output June
                    cout<<"June has 30 days\n\n";
                else if (month == 7)//else if input=7 then output July
                    cout<<"July has 31 days\n\n";
                else if (month == 8)//else if input=8 then output August
                    cout<<"August has 31 days\n\n";
                else if (month == 9)//else if input=9 then output September
                    cout<<"September has 30 days\n\n";
                else if (month == 10)//else if input=10 then output October
                    cout<<"October has 31 days\n\n";
                else if (month == 11)//else if input=11 then output November
                    cout<<"November has 30 days\n\n";
                else if (month == 12)//else if input=12 then output December
                    cout<<"December has 31 days\n\n";
                
                //End problem 3
                break;
            }
            case(4):{
                //Problem 4
                //Declare variables
                float start, incrRte, days, popGrow;
                
                //Inputs
                cout<<"Enter the starting population: ";
                cin>>start;     //input the starting population
                cout<<endl;
                cout<<"Enter the rate of increase of population as a percent: ";
                cin>>incrRte;   //input the rate of increase in percent
                cout<<endl;
                cout<<"Enter number of days of growth: ";
                cin>>days;      //input the number of days for growth
                cout<<endl;
                
                if (start >= 2&& incrRte >= 0 && days >= 1){    //if starting populatiuon is greater than or equal to 2, rate of increase 
                                                                //is greater than or equal to 0, and days of growth greater than 
                                                                //or equal to 1, then calculate growth
                    popGrow= start+(start*(incrRte/100)*days);  //calculate population growth
                    cout<<"The population grew to " << popGrow << " organisms!\n\n";//out put population growth
                }
                else
                    cout<<"Incorrect input value(s)\n\n";
                //End problem 4
                break;
            }
            case(5):{
                //Problem 5
                //Declare variables
                for (int fhnt=0;fhnt<=20;fhnt++)               //loop the Fahrenheit counter
                cout<<"  "<<fhnt<<"     "<<celsius(fhnt)<<endl;//output Fahrenheit and Celsius conversion equivalent
                //End problem 5
                break;
            }
            case(6):{
                //Problem 6
                //Declare variables
                int scount=0, ccount=0, rcount=0;   //initialize variables
                char a[3][30];                      //set month by day array size
                int b[3][3];                        //set weather report array size
                ifstream infile;                    //declare file
                infile.open("RainOrShine.txt");     //open file for data
                for (int i=0; i<3;i++){             
                    for(int j=0; j<30;j++){
                        infile>>a[i][j];            //loop extraction of data from file into month by day array
                        cout<<a[i][j]<<" ";}
                cout<<endl;}
                cout<<endl<<endl<<"   S    C    R\n";
                for (int i=0;i<3;i++){
                    for (int j=0;j<30;j++){
                        if (a[i][j] == 'S')         //if the array element is an "S" then add one occurrence for "S" to report
                            scount++;
                        else if (a[i][j] == 'C')    //else if the array element is an "C" then add one occurrence for "C" to report
                            ccount++;
                        else                        //else any other array element is an "R", so add one occurrence for "R" to report
                            rcount++;
                    }
                    b[i][0]=scount;//store "S" values
                    b[i][1]=ccount;//store "C" values
                    b[i][2]=rcount;//store "R" values
                    scount=0;      //reset "S" counter
                    ccount=0;      //reset "C" counter
                    rcount=0;      //reset "R" counter
                }
                for (int i=0;i<3;i++){
                    for (int j=0;j<3;j++){
                        cout<<setw(4)<<b[i][j]<<" ";//loop and output values into each element of weather report array
                    }
                    cout<<endl;
                }
                //End problem 6
                break;
            }
            case(7):
            {
                //Problem 7
                //Declare variables
                 string names[20] = {"Nornubari", "Levin", "Mark", "Caddel", "Bae", 
                 "Terry", "Alex", "Patrick", "Garon", "Aaron",
                 "Sean", "Ricardo", "Rick", "Andres", "Josue", 
                 "Fernando", "Britney", "Maxwell", "Jamal", "Henry"};//declare values of the string
                 bSort(names, 20);                                   //call bubble sort function for string
                 prntArr(names, 20);                                 //call print array function
                 prntbinSrch(names, 20, "Maxwell");                    //call binary search function
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

float celsius(int fhnt)
{
    //Declare variables
    float celTemp;
    celTemp= (5.0/9.0)*(fhnt-32.0);//convert Fahrenheit to Celsius
    return celTemp;                //return converted Celsius temperature
    
}

void prntArr(string names[], int n)
{
	for(int i=0; i<n; i++) //form a one dimensional array
	{ 
            cout << names[i] << " "; //prints each string of array
	}
	cout << endl << endl;
	
}

void bSort(string names[], int n)
{
    //Declare variables
    string temp;
    for(int i=0;i<n;i++) //sort the one dimensional array
    {
       for(int j=0;j<(n-1);j++) //organize array by looking at each column
            if(names[j]>names[j+1]) //if first string is greater than the next then switch 
                                    //them and continue across rest of array
           {
               temp=names[j]; //swap values
               names[j]=names[j+1];
               names[j+1]=temp;
           }
    }
    for(int i=0;i<n;i++) //print each string sorted
        cout<<names[i]<<" ";
    cout<< endl<< endl;
}

int binSearch(string names[], int n, string trgt)
{
    //Declare variables
    int mid, lowbound= 0, hghbound=n-1; 
    while (lowbound <= hghbound) 
    {
         int mid = (lowbound + hghbound)/2; //find middle sorted string in one dimensional array
         if (names[mid] == trgt) //if selected middle string is the target then it is found
             return mid;
         else if (names[mid] < trgt) 
             lowbound = mid + 1; //if selected middle is less than target, then next string is beginning of next search
         else hghbound = mid - 1; //if selected middle is more than target, then previous string is end of next search
    }
      return -1;
    
}

int prntbinSrch(string names[], int n, string trgt)
{
    //Declare variables
    int found; 
    found=binSearch(names, n, trgt); //call binary search function
    if (found==-1) //if string found is not the returned value then say the string was not found, otherwise, it is found
        cout << endl << "Maxwell was not found." << endl;
    else
        cout << endl << "Maxwell was found."<< endl;
        
}
