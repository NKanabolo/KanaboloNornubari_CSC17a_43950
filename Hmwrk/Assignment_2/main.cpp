/* 
 * File:   main.cpp
 * Author: Nornubari Kanabolo
 * Assignment 2
 * Created on March 24, 2015, 11:10 PM
 */

//User Defined Libraries
#include<iostream>

using namespace std;

//Function Prototypes
void mode(int[], int);//finds most frequent number in array
void mean(int[], int);//calculates average of array values
void sort(int[], int);//sorts array
void median(int[], int);//selects middle number or numbers of sorted array
//Execution Begins Here

int main(int argc, char** argv) {
//Main menu setup and output
    unsigned short m_choice;
    bool m_running = true; //The status of the menu loop
    //Enter menu loop
    while (m_running) {
        cout<<"1.  Mean, Median, Mode\n";
        cout<<"2.  Gaddis, 8thEd, Chapter 9, Problem \n";
        cout<<"3.  Gaddis, 8thEd, Chapter 9, Problem \n";
        cout<<"4.  Gaddis, 8thEd, Chapter 9, Problem \n";
        cout<<"5.  Gaddis, 8thEd, Chapter 9, Problem \n";
        cout<<"6.  Gaddis, 8thEd, Chapter 9, Problem \n";
        cout<<"7. Quit the program\n";
        cout << "Enter an integer from 1 to 7 to select an option above: ";
        cin>>m_choice;
        cout<<endl;
        
        //Begin menu
        switch(m_choice){
            case(1):{
                //Problem 1
                //Declare variables
                int array[15];    //size of array
                float total, mode;
                int n = 15;       //number of elements in array

                //fill in the value of array
                for(int i=0; i<n; i++){
                    cout << "Fill in the "<< i+1 << " number. :";
                    cin >> array[i];//input up to 15 values for the array
                }

                sort(array, n);//call sorted array

                //End problem 1
                break;
            }
            case(2):{
                //Problem 2
                //Declare Variables
                
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
                //Problem 6
                //Declare variables
                
                }
                //End problem 6
                break;
            
            
            default:
                cout<<"Unknown input, please try again.\n\n";
    }}
        
    //Exit program
    cout << "Now exiting program\n";
    return 0;
}

void mean(int newArr[], int terms){
    //Calculate average of array
    //Declare variables
    float total = 0;
    for(int i=0;i<terms; i++){
        total += newArr[i]; //add up each of the 15 values
    }
    cout << "The mean is " << total/terms << endl;//calculate and output mean
    mode(newArr, terms);
    }

void median(int newArr[], int terms){
    //Calculate middle sorted number
    if(terms % 2 != 0){            //check if number is odd
        int temp = ((terms+1)/2)-1;//calculate median if only one is median
        cout << "The median is " << newArr[temp] << endl;//output single median
    }
    else{// then it's even! :)
        cout << "The median is "<< newArr[(terms/2)-1] << " and " << newArr[terms/2] << endl;//calculate median if two are medians
    }
    mean(newArr, terms);//call mean function
}

void mode(int newArr[], int terms) {
    //Find mode of array
    int* repeat = new int[terms];//create new array of same size
    for (int i = 0; i < terms; i++) {//go through each term until size of array is reached
        repeat[i] = 0;//initialize each element to 0
        int j = 0;
        while ((j < i) && (newArr[i] != newArr[j])) {
            if (newArr[i] != newArr[j]) {//if old array is not equal to new array then add 1 to counter
                j++;
            }
        }
        (repeat[j])++;//add one to new array repeat counter
    }
    int maxRep = 0;//initialize repetitions to 0
    for (int i = 1; i < terms; i++) {//go through each number up to the size of the array
        if (repeat[i] > repeat[maxRep]) {//if the number being repeated is greater than the maximum repetitions then 
                                         //the max rep is that number 
            maxRep = i;
        }
    }
    cout<< "The mode is " << newArr[maxRep] << endl;//output mode

}

void sort(int newArr[], int terms){
    //Sort the array
    for(int x=0; x<terms; x++){
         for(int y=0; y<terms-1; y++){
             if(newArr[y]>newArr[y+1]){
                 int temp = newArr[y+1];//swap values
                 newArr[y+1] = newArr[y];
                 newArr[y] = temp;
             }
         }
     }
    cout << "List: ";
    for(int i =0; i<terms; i++){//go through size of array and print each sorted value
        cout << newArr[i] << " ";
    }
    cout << "\n";
    median(newArr, terms);//call median function
}