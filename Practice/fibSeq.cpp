#include <iostream>
#include <ios>
#include <fstream>
#include <math.h> //sqrt()
#include <vector>
#include "infInt.h"

using namespace std;

int main(int argc, char *argv[])
{
   ofstream file;
   file.open("Ouput.out");
   InfInt userInput;
   cout << "How many fib numbers do you want? Enter here: ";
   cin >> userInput;
   cout << endl;
   InfInt num1 = 0;
   InfInt num2 = 1;
   InfInt num3 = 0;
   InfInt tempNum = 0;
   cout << "Fib number 1 is: " << num1 << endl
        << endl;
   cout << "Fib number 2 is: " << num2 << endl
        << endl;
   file << "Fib number 1 is: " << num1 << endl
        << endl;
   file << "Fib number 2 is: " << num2 << endl
        << endl;
   for (InfInt i = 2; i < userInput; i++)
   {
      // 1 2 0 0
      num3 = num1 + num2;
      // 1 2 3 0
      file << "Fib number " << i + 1 << " is: " << num3 << endl
           << endl;
      // 1 2 3 0
      tempNum = num2;
      // 1 2 3 2
      num2 = num3;
      // 1 3 3 2
      num1 = tempNum;
      // 2 3 3 2
      num3 = 0;
      // 2 3 0 2
      tempNum = 0;
      // 2 3 0 0
   }
   if (userInput == 1)
      cout << "The fib number in position " << userInput << " is 0" << endl;
   else if (userInput < 1)
      cout << "Please restart the program and enter a positive number" << endl;
   else
      cout << "The fib number in position " << userInput << " is " << num2 << endl;
}