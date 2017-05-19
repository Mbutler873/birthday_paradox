/*
Max Butler

This program test the actual results of the birthday paradox and
outputs the percentage of the time that at least two people share
a birthday in a test group with a given number of people
*/
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

bool checkDuplicates(int[], int, int);

const int TRIALS = 100000; //number of times the test is done
const int TOTAL = 23; //number of people in the room
int main()
{
   srand(time(0));

   int people[TOTAL] = {0}; //holds the birthdates

   double yes = 0; //variables for calculating percentages
   double no = 0;

   //this loop runs the test a given number of times
   //and fills an array with random numbers from
   //1 to 365. It then will test to see if there are
   //any duplicate numbers
   for(int j = 0; j < TRIALS; ++j){
      for(int i = 0; i < TOTAL; ++i){
         people[i] = rand() % 365 + 1;
      }
      if(checkDuplicates(people,TOTAL,0) == true)
         yes += 1;
      else
         no += 1;
   }

   //outputs the percentages
   cout << "True = " << yes/TRIALS*100 << "%" << endl;
   cout << "False = " << no/TRIALS*100 << "%" << endl;
}

//recursive function that checks an array for duplicate numbers
bool checkDuplicates(int arr[], int arr_size, int index){
   if(index == arr_size){
      return false;
   }

   for(int i = index + 1; i < arr_size; ++i){
      if(arr[index] == arr[i]){
         return true;
      }
   }

   return checkDuplicates(arr, arr_size, ++index);
}




