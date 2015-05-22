/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Assignment 3
 * Created on April 4, 2015, 9:07 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//User Defined Libraries

//Function Prototypes
//Chapter 10 Problem 4 Functions
int numbWrd(string phrase);
//Chapter 10 Problem 5 Functions
void sentcCap(string phrase);
//Chapter 11 Problem 1 Structures and Functions
    struct MovieData
    {
        string title;     //Holds the title of the movie
        string director;  //Holds the director's name
        int yearRelease;  //Holds the year the movie was released
        float runTime;    //Holds the running time of the movie(in minutes)
    };
void movData(MovieData &a, int n);
void shwMovData(const MovieData &b);
//Chapter 11 Problem 3 Structures and Functions
    struct SalesData
    {
        string divisionName;     //Holds the division name
        float firstQuatSales;    //Total sales made in the first quarter
        float secondQuatSales;   //Total sales made in the second quarter
        float thirdQuatSales;    //Total sales made in the third quarter
        float fourthQuatSales;   //Total sales made in the fourth quarter
        float totalAnnualSales;  //The sum of all four quarters
        float averageQuatSales;  //Average of sales per quarter
    };      
void salesData(SalesData &a);
void totAvrg(SalesData &b);
//Chapter 12 Problem 1 Functions
char *getStr(int size);
int vowels(char *arr, int size);
int conso(char *arr, int size);
//Functions for Chapter 12 Problem 8
void arrayToFile(fstream &file, int *arr, int size);
void fileToArray(fstream &file, int *arr, int size);
//Chapter 12 Problem 11 Functions

//Execution Begins Here

int main(int argc, char** argv) {
//Main menu setup and output
    unsigned short m_choice;
    bool m_running = true; //The status of the menu loop
    //Enter menu loop
    while (m_running) {
        cout<<"1.  Gaddis, 8thEd, Chapter 10, Problem 4\n";
        cout<<"2.  Gaddis, 8thEd, Chapter 10, Problem 5\n";
        cout<<"3.  Gaddis, 8thEd, Chapter 10, Problem 6\n";
        cout<<"4.  Gaddis, 8thEd, Chapter 11, Problem 9\n";
        cout<<"5.  Gaddis, 8thEd, Chapter 11, Problem 1\n";
        cout<<"6.  Gaddis, 8thEd, Chapter 11, Problem 3\n";
        cout<<"7.  Gaddis, 8thEd, Chapter 12, Problem 1\n";
        cout<<"8.  Gaddis, 8thEd, Chapter 12, Problem 7\n";
        cout<<"9.  Gaddis, 8thEd, Chapter 12, Problem 8\n";
        cout<<"10. Gaddis, 8thEd, Chapter 12, Problem 11\n";
        cout<<"11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout<<endl;
        
        //Begin menu
        switch(m_choice){
            case(1):{
                //Problem 1
                //Declare variables
                string words;          //string that holds the user input
                int wordCnt;         //holder for the return of the numbWrd function
                float totLttr;    //The total number of letters in the string
                float lttrAvg;   //The average of letters per word in the string

                cin.ignore();
                //Input a string
                cout << "\nInput sentence for program to calculate the average number of letters per word" << endl;
                getline(cin, words);
                //Calling the function
                wordCnt = numbWrd(words);
                //Calculating the size of the string
                totLttr = words.length();
                //Calculating the average of letters per word
                lttrAvg = (totLttr - (wordCnt - 1)) / wordCnt;
                //Printing the result
                cout << setprecision(2) << fixed;
                cout << "\nAverage number of letters per word: "<< lttrAvg << " letters."<< endl;
                //End problem 1
                break;
            }
            case(2):{
                //Problem 2
                //Declare Variables
                string notCap;  //Uncapitalized words

                cin.ignore();
                cout << "\nType a short paragraph in all lowercase letters. Program capitalizes first letter of each sentence" << endl;
                getline(cin, notCap);

                // Call word capitalizer function
                sentcCap(notCap); 
                //End problem 2
                break;
            }
            case(3):{
                //Problem 3
                //Declare Variables
                int size=31;
                char *arr=NULL;
                arr=getStr(size);
                
                do{
                //Output number of vowels results
                cout<<"There are " << vowels(arr, size) << " vowels in your string.\n";

                //Output number of consonants results
                cout<<"There are " << conso(arr, size) << " consonants in your string.\n";
                
                //Output number of vowels results
                cout<<"There are " << vowels(arr, size)<< " vowels in your string.\n";

                //Output number of consonants results
                cout<<"There are " << conso(arr, size) << " consonants in your string.\n";
                }while(arr!=getStr(size));
               delete [] arr;
               //End problem 3
                break;
            }
            case(4):{
                //Problem 4
                //Declare variables
                struct Speaker 
                {
                    string name;         //Name of speaker
                    string phoneNumber;  //Speaker's phone number
                    string speakTopic;   //Speaker's topic
                    float fee;           //Fee charged to speaker
                };
                    const int SIZE = 10;
                    Speaker info[SIZE];
                    int menu;
                    string menuName;

                    do
                    {
                        cout << "Enter 1 to input speaker's data"
                             << "\nEnter 2 to change speaker's data"
                             << "\nEnter 3 to display all speaker's data"
                             << "\nEnter 4 to EXIT" << endl;
                        cin >> menu;
                        cout << endl;

                        //Input speaker's data
                        if(menu == 1)
                        {
                            for(int i = 0; i < SIZE; i++)
                            {
                                cin.ignore();
                                cout << "Enter speaker "<< (i+1) << " name: ";
                                getline(cin, info[i].name);
                                cout << "Enter speaker " << (i+1) << " phone number: ";
                                getline(cin, info[i].phoneNumber);
                                cout << "Enter speaker "<< (i+1) << " speaking topic: ";
                                getline(cin, info[i].speakTopic);
                                cout << "Enter speaker "<< (i+1) << " fee: ";
                                cin >> info[i].fee;
                                while(info[i].fee < 0)
                                {
                                    cout << "\nFee cannot be less than 0" << endl;
                                    cout << "Enter speaker "<< (i+1) << " fee: ";
                                    cin >> info[i].fee;
                                }
                                cout << endl;
                            }
                        }
                        //Change speaker data
                        else if(menu == 2)
                        {
                            cin.ignore();
                            cout << "Enter the name of the speaker to change his/hers data: ";
                            getline(cin, menuName);
                            //Searching for that speaker
                            for(int i = 0; i < SIZE; i++)
                            {
                                //If name was found edit data
                                if(menuName == info[i].name)
                                {
                                    cout << "Enter " << info[i].name << "'s new name: ";
                                    getline(cin, info[i].name);
                                    cout << "Enter " << info[i].name << "'s new phone number: ";
                                    getline(cin, info[i].phoneNumber);
                                    cout << "Enter " << info[i].name << "'s new topic: ";
                                    getline(cin, info[i].speakTopic);
                                    cout << "Enter "<< info[i].name << "'s new fee: ";
                                    cin >> info[i].fee;
                                    //Exit loop if name was found
                                    break;
                                }
                            }
                            //If name was not found
                            cout << "\nSpeaker was not found!";
                            cout << endl;
                        }
                        //Printing all speaker's data
                        else if(menu == 3)
                        {
                            cout << "Here are all the speakers data: " << endl;
                            for(int i = 0; i < SIZE; i++)
                            {
                                cout << "\nSpeaker " << (i+1) << " name:   " << info[i].name;
                                cout << "\nTelephone Number: " << info[i].phoneNumber;
                                cout << "\nSpeaking Topic:   " << info[i].speakTopic;
                                cout << "\nFee Required:     " << info[i].fee;
                                cout << endl << endl;
                            }
                        }
                        //Exit
                        else if(menu == 4)
                        {
                            cout << "Exit program" << endl;
                        }
                        //Input validation
                        else
                        {
                            cout << "Invalid input. Enter numbers: 1, 2, 3 or 4 Only.\n";
                        }

                    }while(menu != 4);              
                    //End problem 4
                break;
            }
            case(5):{
                //Problem 5
                //Declare variables
                MovieData movie1;
                MovieData movie2;
                int number1 = 1, number2 = 2;

                //Request movie data
                movData(movie1, number1);
                movData(movie2, number2);

                //Display movie data
                shwMovData(movie1);
                shwMovData(movie2);
                //End problem 5
                break;
            }
            case(6):{
                //Problem 6
                //Declare variables
                SalesData division1, division2, division3, division4;

                //Calling function to collect the data from the user
                salesData(division1);
                salesData(division2);
                salesData(division3);
                salesData(division4);

                //Calling function to calculate total annual sales, average and printing
                totAvrg(division1);
                totAvrg(division2);
                totAvrg(division3);
                totAvrg(division4);                
                //End problem 6
                break;
            }
                case(7):{
                //Problem 7
                //Declare variables
                fstream file;   // File to be open
                string name;    // Name of the file
                int count = 0;  // Set counter to 0

                cin.ignore();
                // Input the name of the file
                cout<<"Enter the file name. ('list_numbers.txt') ";
                getline(cin,name);

                //Opens file name from the input
                file.open(name.c_str(), ios::in);
                if(file.fail()) //File fail to open
                {
                    cout << "\nCannot open file" << endl;
                }

                while(file)   // Loop to print from the file
                {
                    getline(file, name);

                    if(file.eof() && count <= 15)  // If the file has less than 10 lines
                    {
                        cout << "\nAll contents of file are out" << endl;
                        break;
                    }
                    else if(count == 15)
                    {
                        cout << "\nProgram displays just the first 15 lines\n";
                        break;
                    }
                    // Print each line
                    cout << name <<endl;
                    count++;

                }
                file.close();
                //End problem 7
            }
            case(8):{
                //Problem 8
                //Declare variables
                ifstream fileIn;   //File to take input from
                ofstream fileOut;  //File to output
                string nameIn;     //Input file name
                string nameOut;    //Output file name
                string sentence;   //Temporarily stores the date from input file
                int length;        //Length of the string sentence

                cin.ignore();
                //Input file name
                cout << "Enter input file name. ('sentence.txt') ";
                getline(cin, nameIn);
                //Output file name
                cout << "\nEnter output file name ('no_text.txt') ";
                getline(cin, nameOut);

                //Opens file name from the input
                fileIn.open(nameIn.c_str(),ios::in);
                if(fileIn.fail())
                {
                    cout << "\nCannot open file" << endl;
                }
                if(fileIn)
                {
                    getline(fileIn, sentence);
                }
                fileIn.close();

                length = sentence.length();
                for (int i = 0; i <= length; i++) //Makes letters lower case
                {
                    sentence[i] = tolower(sentence[i]);
                    }
                    sentence[0] = toupper(sentence[0]); //Makes first letter upper case
                    //Count how many words
                    for(int j = 0; j <= length; j++) //Makes letter after a period upper case
                    {
                        if(sentence[j] == '.')
                        {
                            sentence[j + 2] = toupper(sentence[j + 2]);
                        }
                     }
                    //Open output file
                    fileOut.open(nameOut.c_str(),ios::out);
                    if(fileOut.fail())
                    {
                            cout << "\nCannot open file" << endl;
                    }

                    if(fileOut) //Prints string to output file
                    {
                            fileOut << sentence;
                    }
                    fileOut.close();

                    cout << "\nSentence from input file was corrected and put in output file" << endl;                
                //End problem 8
                break;
            }
            case(9):{
                //Problem 9
                //Declare variables
                const int size=10;
                int arr[size]={1,2,3,4,5,6,7,8,9,10};
                fstream file;
                int *ptr=NULL;
                srand(static_cast<unsigned int>(time(0)));
                ptr=arr;
                
                arrayToFile(file, ptr, size);
                fileToArray(file, ptr, size);
                
                //End problem 9
                break;
            }
            case(10):{
                //Problem 10
                //Declare variables
                //End problem 10
                break;
            
            default:
                cout<<"Unknown input, please try again.\n\n";
    }
    }
    //Exit program
    cout << "Now exiting program\n";
    return 0;
}
}

//Chapter 10 Problem 4 functions
int numbWrd(string phrase)
{
    int count = 1;                 //Set counter to 1
    int length = phrase.length();  //Gets the length of the input

    //Count how many words
    for(int i = 0; i <= length; i++)
    {
        if(phrase[i] == ' ')
        {
            count++;
        }
    }
    //Returning the number of words
    return count;
}
//Chapter 10 Problem 5 functions
void sentcCap(string phrase)
{
    int length = phrase.length();  //Gets the length of the input

    //Sets the first letter as upper case
    phrase[0] = toupper(phrase[0]);
    //Loop to capitalize the first letter after a period
    for(int i = 0; i <= length; i++)
    {
    if(phrase[i] == '.')
    {
    phrase[i + 2] = toupper(phrase[i + 2]);
    }
    }
    //Prints capitalized paragraph
    cout << "\nCapitalized paragraph: " << endl;
    cout << phrase << endl;
}
//Chapter 11 Problem 1 functions
void movData(MovieData &a, int n)
{
    //Requesting inputs
    cin.ignore();
    cout << "Movie " << n << endl;
    cout << "Enter the title of the movie: ";
    getline(cin, a.title);
    cout << "Enter the director's name: ";
    getline(cin, a.director);
    cout << "Enter the year it was released: ";
    cin >> a.yearRelease;
    cout << "Enter the running time(minutes): ";
    cin >> a.runTime;
    cout << endl;
}
//Function to print the data for problem 1
void shwMovData(const MovieData &b)
{   //Prints the information in the structure
    cout << "Title:         " << b.title << endl;
    cout << "Director:      " << b.director << endl;
    cout << "Year Released: " << b.yearRelease << endl;
    cout << "Running Time:  " << b.runTime << endl;
    cout << endl;
}

//Chapter 11 Problem 3 functions
void salesData(SalesData &a)
{
    //Requesting inputs with input validation
    cin.ignore();
    cout << "Enter division name(East, West, North or South) ";
    getline(cin, a.divisionName);
    cout << "Enter First-Quarter Sales: ";
    cin >> a.firstQuatSales;
    while(a.firstQuatSales < 0)
    {
        cout << "\nSales cannot be a negative number" << endl;
        cout << "Enter the First-Quarter Sales: ";
        cin >> a.firstQuatSales;
    }
    cout << "Enter the Second-Quarter Sales: ";
    cin >> a.secondQuatSales;
    while(a.secondQuatSales < 0)
    {
        cout << "\nSales cannot be a negative number" << endl;
        cout << "Enter the First-Quarter Sales: ";
        cin >> a.secondQuatSales;
    }
    cout << "Enter the Third-Quarter Sales: ";
    cin >> a.thirdQuatSales;
    while(a.thirdQuatSales < 0)
    {
        cout << "\nSales cannot be a negative number" << endl;
        cout << "Enter the First-Quarter Sales: ";
        cin >> a.thirdQuatSales;
    }
    cout << "Enter the Fourth-Quarter Sales: ";
    cin >> a.fourthQuatSales;
    while(a.fourthQuatSales < 0)
    {
        cout << "\nSales cannot be a negative number" << endl;
        cout << "Enter the First-Quarter Sales: ";
        cin >> a.fourthQuatSales;
    }
    cout << endl;
}

void totAvrg(SalesData &b)
{
    //Calculate total annual sales
    b.totalAnnualSales = b.firstQuatSales + b.secondQuatSales + 
                         b.thirdQuatSales + b.fourthQuatSales;
    //Calculate average quarterly sales
    b.averageQuatSales = (b.firstQuatSales + b.secondQuatSales + 
                          b.thirdQuatSales + b.fourthQuatSales) / 4.0;
    //Printing the structure variables
    cout << "Division Name:             $" << b.divisionName;
    cout << "\nFirst-Quarter:             $" << b.firstQuatSales;
    cout << "\nSecond-Quarter:            $" << b.secondQuatSales;
    cout << "\nThird-Quarter:             $" << b.thirdQuatSales;
    cout << "\nFourth-Quarter:            $" << b.fourthQuatSales;
    cout << "\nTotal Annual Sales:        $" << b.totalAnnualSales;
    cout << "\nAverage Quarterly Sales:   $" << b.averageQuatSales;
    cout << endl << endl;
}

void arrayToFile(fstream &file, int *arr, int size){
    
    file.open("list_numbers.txt", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(arr), sizeof(arr));
    cout<<endl;
    file.close();
}

void fileToArray(fstream &file, int *arr, int size){
    file.open("list_numbers.txt", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(arr), sizeof(arr));
    cout<<"The following data was read by the program."<<endl;
    for(int count=0; count<size; count++){
        cout<<arr[count]<<" ";
    }
    cout<<endl;
    file.close();
}

//Chapter 10 Problem 6 functions
char *getStr(int size){
    char *arr=NULL;
    
    arr=new char[size];
    
    //Request sentence with a max of 50 characters
    cout<<"Type sentence less than 30 characters: \n";
    cin.getline(arr, size);
 
    return arr;
}

int vowels(char *arr, int size){
    int vowels=0;
    int count=0;
    
    while (arr[count] != '\0'){ //Runs through the arr stopping and terminator
        count++; //while not terminator increment count
        
        static_cast<int>(arr[count]);
        
        if(arr[count]==65 || arr[count]==97){
            vowels++;
        }else if(arr[count]==69 || arr[count]==101){
            vowels++;
        }else if(arr[count]==73 || arr[count]==105){
            vowels++;
        }else if(arr[count]==79 || arr[count]==111){
            vowels++;
        }else if(arr[count]==85 || arr[count]==117){
            vowels++;
        }
        
    }
    return vowels;  
}

int conso(char *arr, int size){
    int conso=0;
    int count=0;
    
    while (arr[count] != '\0'){ //Goes through array stopping and terminator
        count++;                //while not terminator increment count
        
        static_cast<int>(arr[count]);
        
        conso++;//Increment consonant count
        
        //Subtract from consonant count if the following are found.
        if(arr[count]==65 || arr[count]==97){
            conso--;
        }else if(arr[count]==69 || arr[count]==101){
            conso--;
        }else if(arr[count]==73 || arr[count]==105){
            conso--;
        }else if(arr[count]==79 || arr[count]==111){
            conso--;
        }else if(arr[count]==85 || arr[count]==117){
            conso--;
        }else if (arr[count]>=32 && arr[count]<=64){
            conso--;
        }else if (arr[count]>=91 && arr[count]<=96){
            conso--;
        }else if (arr[count]>=123 && arr[count]<=126){
            conso--;
        }
            
        
    }
    return conso;  
}
//Chapter 12 Problem 11 functions

