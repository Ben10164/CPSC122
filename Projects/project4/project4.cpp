/*
Name: Ben Puryear
Class: CPSC 122 Section 1
Date Submitted: 1/27/2021
Assignment: Project 4
Description: calculates an amount of prime numbers based off of the users input then outputs them to a file with a user specified amount of columns
Notes: This was really fun :) (test)
*/

#include <fstream>
#include <ios>
#include <iostream>
#include <math.h> //sqrt()
#include <vector>

using namespace std;

//Function prototypes
void calculatePrimes(vector<int> &primes);
bool isPrime(int num, vector<int> primes);
void display(vector<int> primes, ofstream &outputFile);

int main(int argc, char *argv[])
{
   string input;
   vector<int> primes(0); //Creates a vector of ints, these will be the prime numbers
   primes.push_back(2);   //Adds 2 to the list of primes to make the function work by having a baseline to be compared with
   if (argc <= 1)
   {
      cout << "Sorry but I believe you forgot a command line parameter" << endl;
      return -1;
   }
   else
      input = argv[1]; //Gets the input from the command line
   ofstream outputFile;
   outputFile.open(input);

   string trashbin;

   calculatePrimes(primes);

   display(primes, outputFile);
}

/*
Description: Simple while loop that continues until 
             the user specified amount of numbers
Input: The vector of prime numbers
Returns: void (but changes the vector of prime numbers)
*/
void calculatePrimes(vector<int> &primes)
{
   int primesLimit = 0, checkedNumber = 3, amountOfPrimes = 1;
   cout << "How many prime numbers do you want to be calculated? \nEnter here: ";
   //cin >> primesLimit;
   primesLimit = 100;
   while (true)
   {
      if (isPrime(checkedNumber, primes))
      {
         primes.push_back(checkedNumber);
         amountOfPrimes++;
      }
      checkedNumber++;
      if (amountOfPrimes == primesLimit)
         break;
   }
}

/*
Description: This function is cool because instead of checking every number
             to see if its remandier is 0 after dividing, it only has to check
             prime numbers, which saves ALOT of processing time
Input: A number to be checked, the vector of primes
Returns: True if the number inputted is prime
*/
bool isPrime(int num, vector<int> primes)
{
   //The for loop continues until the square root of the number because after the square root
   //it would be repetitive to test against other primes because you would have found
   //the other factor pair
   for (int pos = 0; primes.at(pos) <= sqrt(num); pos++)
      if (num % primes.at(pos) == 0)
         return false;
   return true;
}

/*
Description: Displays the primes in the output file
Input: Vector of primes, and the output files ofstream variable
*/
void display(vector<int> primes, ofstream &outputFile)
{
   int col, nums = 1;
   cout << "How many cols: ";
   //cin >> col;
   col = 3;
   while (nums <= primes.size())
   {
      outputFile << primes.at(nums - 1) << '\t';
      if (nums % col == 0)
         outputFile << endl;
      nums++;
   }
   outputFile << endl;
   cout << "Successfully outputted " << primes.size() << " numbers in " << col << " columns to the output file" << endl;
}