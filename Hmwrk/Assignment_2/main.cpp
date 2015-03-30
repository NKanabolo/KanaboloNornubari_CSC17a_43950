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
void arrAllo(int max, int n);//allocate array of integers
void scores(int scr[], int n);//display scores
void sortScr(int scr[], int n);//sort scores
void scrAve(int scr[], int n);//calculate average of scores
void aveLow(int scr[], int n);//calculate average of scores without lowest score
void donSort(int *arr[], int n);//sort allocated donations array
void donArr(const int arr[], int n);//display original donations array
void donPtr(int *arr[], int n);//display sorted donations array
void reverse(int *rvsPtr, int n);//put array in reverse order
//Execution Begins Here

int main(int argc, char** argv) {
//Main menu setup and output
    unsigned short m_choice;
    bool m_running = true; //The status of the menu loop
    //Enter menu loop
    while (m_running) {
        cout<<"1.  Mean, Median, Mode\n";
        cout<<"2.  Gaddis, 8thEd, Chapter 9, Problem 1\n";
        cout<<"3.  Gaddis, 8thEd, Chapter 9, Problem 2\n";
        cout<<"4.  Gaddis, 8thEd, Chapter 9, Problem 3\n";
        cout<<"5.  Gaddis, 8thEd, Chapter 9, Problem 6\n";
        cout<<"6.  Gaddis, 8thEd, Chapter 9, Problem 10\n";
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
                int max,n;
                arrAllo(max, n);//call allocated array
                //End problem 2
                break;
            }
            case(3):{
                //Problem 3
                //Declare Variables
                int scr[10];
                int n=10;
                 scores(scr, n);//call scores array
                 sortScr(scr, n);//call sorted scores array
                 scrAve(scr, n);//call average of scores array
                //End problem 3
                break;
            }
            case(4):{
                //Problem 4
                //Declare variables
                int scr[10];
                int n=10;
                scores(scr, n);//call scores array
                sortScr(scr, n);//call and output sorted scores array
                aveLow(scr, n);//call and output average of scores calculated without lowest score array
                //End problem 4
                break;
            }
            case(5):{
                //Problem 5
                //Declare variables
                const int n = 15;//size of array
                int donate[n];
                int *arrPtr[n];//pointer to second array
                for(int i=0; i<n; i++){
                cout << "Fill in the "<< i+1 << " score. :";
                cin >> donate[i];//input up to 15 donations for the array
                }
                for (int count = 0; count < n; count++){
                arrPtr[count] = &donate[count];//make each element point to element in donations array
                }
                donSort(arrPtr, n);//call sorted donations array
                cout << "The donations, sorted in ascending order are: \n";
                donPtr(arrPtr, n);//output sorted array
                cout << endl;
                cout << "The donations, in their original order are: \n"; 
                donArr(donate, n);//output original donations array
                cout << endl;
                //End problem 5
                break;
            }
            case(6):{
                //Problem 6
                //Declare variables
                 const int n = 10;
                 int rev[n] = {45, 52, 100, 16, 25, 30, 27, 82, 90, 76};
                 int *rvsPtr = '\0';
                 
                 rvsPtr = rev;
                 reverse(rvsPtr, n);//call and output original and reverse order array
                }
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

void arrAllo(int max, int n){   
    //Declare variables    
    int * ptr;
    cout << "How many numbers do you want to enter? ";      
    cin >> max;//get the number of values to store
    
    ptr= new int[max];//allocate memory for new array
    if (ptr == '\0')
        cout << "Error: memory could not be allocated";
    else
    {
        for (n=0; n<max; n++)
        {
          cout << "Enter number: ";
          cin >> ptr[n];//enter value for use
        }
        cout << "You have entered: ";
        for (n=0; n<max; n++)
          cout << ptr[n] << " ";//display the values entered
        cout<<endl<<endl;
    delete[] ptr;
    }
}

void scores(int scr[], int n){
    //Fill in the scores of the array
    for(int i=0; i<n; i++){
        cout << "Fill in the "<< i+1 << " score. :";
        cin >> scr[i];//input up to 10 scores for the array
    }
    cout << endl<< "Scores entered: ";
        for (n=0; n<10; n++)
          cout << scr[n] << " ";
        cout<<endl<<endl;
}

void sortScr(int scr[], int n){
    //Sort scores
    for(int x=0; x<n; x++){
         for(int y=0; y<n-1; y++){
             if(scr[y]>scr[y+1]){
                 int temp = scr[y+1];//swap scores into ascending order
                 scr[y+1] = scr[y];
                 scr[y] = temp;
             }
         }
     }
    cout << "Ordered Score List: ";
    for(int i =0; i<n; i++){//go through size of array and print each sorted score
        cout << scr[i] << " ";
    }
    cout << "\n\n";
}

void scrAve(int scr[], int n){
    //Declare variables
    int total = 0;
    for(int i=0;i<n; i++){
        total += scr[i]; //add up each of the 10 scores
    }
    cout << "The average score is a " << total/n << endl <<endl;//calculate and output average
}

void aveLow(int scr[], int n){
    //Declare variables
    int  average, low, total = 0;
    int score[0];
    low=score[0];
    for(int i=0;i<n; i++){
        total += scr[i]; //add up each of the 10 scores
        if (scr[i] < low)
            low = scr[i];//find lowest score
    }
    average = (total -  low) / (n-1);//calculate average without the lowest score

    cout << "The average test score is: " << average << endl << endl;//output average score
    cout << "Lowest is: " << low << endl << endl;//output lowest score
}

 void donSort(int *arr[], int n){
     //Declare variables
     int start, min;
     int *elmnt;
     for (start = 0; start < n-1; start++){
         min = start;//initial i equals start number
         elmnt = arr[start];//set first element equal to i of array
         for(int i = start + 1; i < n; i++){
             if (*(arr[i]) < *elmnt){
                 elmnt = arr[i];//swap values
                 min = i;
             }
         }
         arr[min] = arr[start];
         arr[start] = elmnt;
     }
 }

void donArr(const int arr[], int n){
    for (int count = 0; count < n; count++)
        cout << arr[count] << " ";//output original donation values
    cout << endl << endl;
}   

void donPtr(int *arr[], int n){
    for (int count = 0; count < n; count++)
        cout << *(arr[count]) << " ";//output sorted donation values
    cout << endl << endl;
} 

void reverse(int *rvsPtr, int n){
    //Declare variables
    int count;
     cout << "The numbers in set are:\n";
     for (count = 0; count < n; count++){
         cout << *rvsPtr << " ";//prints numbers in the rev array
         rvsPtr++;
     }  
      cout << "\n\nThe numbers in set backward are:\n";
      for (count = 0; count < n; count++){
         rvsPtr--;//decrement order of rev array
         cout << *rvsPtr << " ";//print rev array in reverse order
      }
      cout<<endl<<endl;
}
