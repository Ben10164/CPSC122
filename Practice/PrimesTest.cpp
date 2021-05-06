#include <cmath>
#include <fstream>
#include <ios>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool isPrime(long num, vector<long> primes);

void display(vector<long> primes, int col, ofstream &outputFile);

int main(int argc, char *argv[])
{
   string input = argv[1];

   ofstream outputFile;
   outputFile.open(input);

   vector<long> primes(0);
   primes.push_back(2);
   string trashbin;
   int amount = 0;
   int temp = 1;
   long i = 3;
   int cols;
   cout << "How many prime numbers do you want to be calculated? \nEnter here: ";
   cin >> amount;
   while (true)
   {
      if (isPrime(i, primes))
      {
         primes.push_back(i);
         temp++;
      }
      i++;
      if (temp == amount)
         break;
   }
   cout << "How many cols: ";
   cin >> cols;
   display(primes, cols, outputFile);
}

bool isPrime(long num, vector<long> primes)
{
   for (long i = 0; primes.at(i) <= sqrt(num); i++)
      if (num % primes.at(i) == 0)
         return false;
   return true;
}

void display(vector<long> primes, int col, ofstream &outputFile)
{
   long nums = 1;
   while (nums <= primes.size())
   {
      outputFile << primes.at(nums - 1) << '\t';
      if (nums % col == 0)
         outputFile << endl;
      nums++;
   }
   outputFile << endl;
}
