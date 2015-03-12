/* 
 * File:   main.cpp
 * Author: Nornubari's Laptop
 *
 * Created on February 25, 2015, 6:16 PM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//User Defined Libraries

//Global Constants

//Function Prototypes
void prntArr(int a[], int length); //print a one dimensional array
void bSort(int b[], int n); //sort and print one dimensional array
void twoDim(int b[][10], int n); //print a two dimensional array
void twoDimSort(int b[][10], int n); //sort two dimensional array
int binSearch(int n, int a[], int trgt); //search for the number 50 in one dimensional array
int prntbinSrch(int n, int a[], int trgt); //print binary search results
int prntTwoDimSort(int b[][10], int n); //print sorted 2 dimensional array
int binSrchTwoD(int b[][10], int key); //search for the number 50 in two dimensional array
int prntTwoDbinSrch(int b[][10], int key); //print binary search results for 2 dimensional array

int main(int argc, char** argv) {
    
    //Declare array sizes
    int arr[100];
    int barry[10][10];
    
    srand(time(0)); //randomize numbers from all functions
    
    //Call functions to main
    cout << endl << "Display 100 double digit numbers in a one dimensional array" << endl;
    prntArr(arr,100); //prints 100 numbers in one dimensional array
    cout << endl << "Display 100 sorted double digit numbers in a one dimensional array" << endl;
    bSort(arr,100); //print sorted one dimensional array of 100 numbers
    cout << endl << "Determine whether or not the number 50 is present in the array" << endl;
    prntbinSrch(100,arr,50); //print one dimensional binary search results
    cout<< endl;
    cout << endl << "Display a two dimensional 10 by 10 array of double digit numbers" << endl;
    twoDim(barry,10); //print two dimensional 10x10 array
    cout << endl << "Sort and display a two dimensional 10 by 10 array of double digit numbers" << endl;
    prntTwoDimSort(barry, 10); //print two dimensional 10x10 array
    prntTwoDbinSrch(barry,50);
    return 0;
}

void prntArr(int a[], int length)
{
	for(int i=0; i<length; i++) //form a one dimensional array
	{ 
            a[i] = (rand()%90)+10; //controls range of of numbers used. 10-100
            cout << a[i] << " "; //prints each number of array
	}
	cout << endl << endl;
	
}

void bSort(int a[], int n)
{
    int temp; //Declare variables
    for(int i=0;i<n;i++) //sort the one dimensional array
    {
       for(int j=0;j<(n-1);j++) //organize array by looking at each column
            if(a[j]>a[j+1]) //if first number is greater than the next then switch 
                            //them and continue across rest of array
           {
               temp=a[j]; //swap values
               a[j]=a[j+1];
               a[j+1]=temp;
           }
    }
    for(int i=0;i<n;i++) //print each sorted number
        cout<<a[i]<<" ";
    cout<< endl<< endl;
}

int binSearch(int n, int a[], int trgt)
{
    int mid, lowbound= 0, hghbound=n-1; //Declare variables
    while (lowbound <= hghbound) 
    {
         int mid = (lowbound + hghbound)/2; //find middle sorted number in one dimensional array
         if (a[mid] == trgt) //if selected middle value is the target then it is found
             return mid;
         else if (a[mid] < trgt) 
             lowbound = mid + 1; //if selected middle is less than target, then next number is beginning of next search
         else hghbound = mid - 1; //if selected middle is more than target, then previous number is end of next search
    }
      return -1;
    
}

int prntbinSrch(int n, int a[], int trgt)
{
    int found; //Declare variables
    found=binSearch(n, a, trgt); //call binary search function
    if (found==-1) //if value found is not the returned value then say the number was not found, otherwise, it is found
        cout << endl << "The number 50 was not found" << endl;
    else
        cout << endl << "The number 50 was found at location "<<found << endl;
        
}

void twoDim(int b[][10], int n)
{
    for(int i=0;i<n;i++) //make rows for 2 dimensional array
    {
       for(int j=0;j<n;j++) //make columns for 2 dimensional array
       {
           
           b[i][j]=(rand()%90)+10; //set range of values for 2 dimensional array
           cout<<b[i][j]<< " "; //print each value of array
       }
       cout<<endl;
    }
    
}

void twoDimSort(int b[][10], int n)
{
    for (int ia=0; ia < n; ia++) //row coordinate value of 2 dimensional array
        for (int ja=0; ja < n; ja++) //row coordinate value of 2 dimensional array
            for (int ib=0; ib < n; ib++) //column coordinate value of 2 dimensional array
                for (int jb=0; jb < n; jb++) //column coordinate value of 2 dimensional array
        if(b[ia][ib]<b[ja][jb]) //if the value of a coordinate is less than the next value then swap them
        {
            int temp = b[ia][ib];
            b[ia][ib] = b[ja][jb];
            b[ja][jb] = temp;
        }  
}

int prntTwoDimSort(int b[][10], int n)
{
    twoDimSort(b, n); //call sorted 2 dimensional array function
    for(int i=0;i<n;i++) //form row
    {
        for(int j=0;j<n;j++) //form column
        cout << b[i][j] << " "; //print each sorted number to 2 dimensional array
        cout << endl;
    }
    cout<< endl<< endl;
}

int binSrchTwoD(int b[][10], int key)
{
  int start = 0;
  int mid, row, col, value;
  int end = (10 * 10) - 1;
  while (start <= end)
  {
    mid = start + (end - start) / 2; //get your middle value
    row = mid / 10; //find middle value of row
    col = mid % 10; //find middle value of column
    value = b[row][col];
 
    if (value == key) //if selected number is the target then that is your number
      return mid;
    if (value > key) //if the selected number is greater than target then next end value is previous  of selected value
      end = mid - 1;
    else
      start = mid + 1; //else the start value starts at next number
  }
  return 0;
}

int prntTwoDbinSrch(int b[][10], int key)
{
    int value; //Declare variables
    value=binSrchTwoD(b, key); //call binary search function
    if (value==0) //if value found is not the returned value then say the number was not found, otherwise, it is found
        cout << endl << "The number 50 was not found." << endl;
    else
        cout << endl << "The number 50 was found." << endl;
        
}