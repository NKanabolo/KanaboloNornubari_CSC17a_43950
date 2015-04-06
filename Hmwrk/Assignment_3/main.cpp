/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Assignment 3
 * Created on April 4, 2015, 9:07 PM
 */

#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

//User Defined Libraries

//Function Prototypes
void wordCount(char [], int&, float&, int&);//count words in string
float get_avg(int, int, float);//calculate average number of letters in each word of string
int cntVowl(char * str);//count number of vowels in string
int cntCons(char * str);//count number of consonants in string
//Execution Begins Here

int main(int argc, char** argv) {
//Main menu setup and output
    unsigned short m_choice;
    bool m_running = true; //The status of the menu loop
    //Enter menu loop
    while (m_running) {
        cout<<"1.  Mean, Median, Mode\n";
        cout<<"2.  Gaddis, 8thEd, Chapter 10, Problem 4\n";
        cout<<"3.  Gaddis, 8thEd, Chapter 10, Problem 6\n";
        cout<<"4.  Gaddis, 8thEd, Chapter , Problem \n";
        cout<<"5.  Gaddis, 8thEd, Chapter , Problem \n";
        cout<<"6.  Gaddis, 8thEd, Chapter , Problem \n";
        cout<<"7.  Gaddis, 8thEd, Chapter , Problem \n";
        cout<<"8.  Gaddis, 8thEd, Chapter , Problem \n";
        cout<<"9.  Gaddis, 8thEd, Chapter , Problem \n";
        cout<<"10.  Gaddis, 8thEd, Chapter , Problem \n";
        cout<<"11. Quit the program\n";
        cout << "Enter an integer from 1 to 11 to select an option above: ";
        cin>>m_choice;
        cout<<endl;
        
        //Begin menu
        switch(m_choice){
            case(1):{
                //Problem 1
                //Declare variables
                int word = 0, punct = 0;//word count and punctuation initialized
                float allChar = 0.0;    //total number of characters initialized
                float avg = 0.0;        //average initialized
                char cstring[30];       //max size of string
                
                cout << "Enter a string of 30 or fewer characters: ";
                cin>>cstring;
                cout<<endl;
                wordCount(cstring, word, allChar, punct);//call word counter
                cout <<"\nThe number of words in that string: " << word << endl;
                avg = get_avg(word, punct, allChar);//set average equal to called calculated average function
                cout <<"\nAverage number of characters per word: "<< fixed <<
                showpoint << setprecision(2) << avg << "\n" << endl;
                //End problem 1
                break;
            }
            case(2):{
                //Problem 2
                //Declare Variables
                const int SIZE = 60;          //max size of array
                char userString[SIZE];
                char choice;                  //menu choice
                char *strPtr = userString;    //declare and initialize the pointer

                
                cout << "Please enter a string with a maximum of 60 characters :\n\n";
                cin>>userString;//get string from the user

                // Display the menu and get a choice
                cout << "\n\nA. Count the number of vowels in the string \n";
                cout << "B. Count the number of consonants in the string \n";
                cout << "C. Count both the number of vowels and consonants in the string \n";
                cout << "D. Enter another string \n";
                cout << "E. Exit the program \n\n";
                cout << "Your selection: ";
                cin >> choice;

                // Menu selections
                if (tolower(choice) == 'a')
                {
                     cout << "This string contains " << cntVowl(userString)<< " vowels. \n";;//output vowel count
                }
                else if (tolower(choice) == 'b')
                {
                     cout << "This string contains " << cntCons(userString)<< " consonants. \n";;//output consonant count
                }
                else if (tolower(choice) == 'c')
                {
                     cout << "This string contains " << cntVowl(userString)+ cntCons(userString);//output vowel and consonant count
                     cout << " vowels and consonants combined.\n";
                }
                else if (tolower(choice) == 'd')
                {
                     cout << "Enter another string: ";
                     cin.getline(userString, SIZE);//input another string
                }
                else
                {
                    exit(EXIT_SUCCESS);//exit program
                }
    
                //End problem 2
                break;
            }
            case(3):{
                //Problem 3
                //Declare Variables
                
                //End problem 3
                break;
            }
            case(4):{
                //Problem 4
                //Declare variables
                
                //End problem 4
                break;
            }
            case(5):{
                //Problem 5
                //Declare variables
                
                //End problem 5
                break;
            }
            case(6):{
                //Problem 5
                //Declare variables
                
                //End problem 5
                break;
            }
            case(7):{
                //Problem 5
                //Declare variables
                
                //End problem 5
                break;
            }
            case(8):{
                //Problem 5
                //Declare variables
                
                //End problem 5
                break;
            }
            case(9):{
                //Problem 5
                //Declare variables
                
                //End problem 5
                break;
            }
            case(10):{
                //Problem 6
                //Declare variables
                 
                //End problem 6
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

void wordCount(char cstring[],int &word, float &allChar, int &punct)
{
    //Declare variables
    int i = 0;

    while (cstring[i] != '\0')
    {
        if ((isspace(cstring[i])) || (ispunct(cstring[i])))//compare white spaces and punctuations
        {
            while((isspace(cstring[i])) || (ispunct(cstring[i])))
            {
                i++;//increment index of cstring array
            }
        }

    if ((isalnum(cstring[i])) || (ispunct(cstring[i])))//compare alphanumerics and punctuations
    {
        word++;//increment word
        while((isalnum(cstring[i]))||(ispunct(cstring[i])))
        {
            i++;
            allChar++; //counts total characters including digits and punctuation
            if((ispunct(cstring[i])))//check for punctuation
                {
                punct++; //increment punctuation counter
                }
        }
    }
    i++;//increment index
    }
}

float get_avg(int word,int punct, float allChar )
{
    //Declare variables
    float avg = 0.0;
    allChar = allChar - punct; //subtract punctuation from all characters in the string not including spaces
    avg = (allChar / word);//calculate average
    return avg;
}

int cntVowl(char* str)
{
    //Declare variables
    int times = 0;
    const int vsize = 6;
    char vowels[vsize] = {'a', 'e', 'i', 'o', 'u', '\0'};
    char *vwlPtr;

    //go through string and count occurrence of vowels
    for(; *str != '\0'; ++str)
    {
       for(vwlPtr = vowels; *vwlPtr != '\0'; vwlPtr++)
       {
          if( tolower(*str) == *vwlPtr )
          {
              ++times;//increment number of times a vowel appears
              break;
          }
        }
    }return times;
}


int cntCons(char *str)
{
    //Declare variables
    int times = 0;
    const int csize = 22;
    char consnt[csize] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
                             'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y',
                             'z', '\0'};
    char *consPtr;                           
    
    //go through string and count occurrence of consonants
    for(consPtr = consnt; *consPtr != '\0'; consPtr++)
    {
        while(*str != '\0')
                {
                  if(tolower(*str) == *consPtr){
                     times++;
                     str++;
                  }}
    }return times;
}