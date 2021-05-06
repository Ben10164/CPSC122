/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 3/4/2021
Assignment: Project 8
Description: Program illustrates using class MyString 
*/

// command used: g++ 8-MyStrTst.cpp 8-MyStr.cpp && ./a.out 'These are the days when birds come back'

#include "8-MyStr.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
   MyString str1(argv[1]);
   MyString *str2 = new MyString(argv[1]);

/*
   // Test of myDisplay
   cout << "***************************************" << endl;
   cout << "*****Test 1 myDisplay*****" << endl;
   cout << "static test" << endl;
   cout << "output should be the command line input" << endl;
   str1.myDisplay();
   cout << endl;
   cout << "*****Test 2  myDisplay*****" << endl;
   cout << "dynamic test" << endl;
   cout << "output should be the command line input" << endl;
   str2->myDisplay();
   //cout << endl; (Im sorry but i thought it looked better with not line between the output and the line of ****)
   cout << "***************************************" << endl;
   // End Test of myDisplay

   // Test of myStrcpy
   cout << "***************************************" << endl;
   cout << "*****Test 1 myStrcpy*****" << endl;
   cout << "static test" << endl;
   cout << "output should be the command line input, then on a new line \"Static test successful\"" << endl;
   str1.myDisplay();
   str1.myStrcpy("Static Test Successful");
   str1.myDisplay();
   cout << endl;
   cout << "*****Test 2  myStrcpy*****" << endl;
   cout << "dynamic test" << endl;
   cout << "output should be the command line input, then on a new line \"Dynamic test successful\"" << endl;
   str2->myDisplay();
   str2->myStrcpy("Dynamic Test Successful");
   str2->myDisplay();
   cout << "***************************************" << endl;
   // End Test of myStrcpy

   // Test of myStrlen
   cout << "***************************************" << endl;
   cout << "*****Test 1 myStrlen*****" << endl;
   cout << "static test" << endl;
   cout << "output should be the length of the command line input" << endl;
   cout << "The length of str1 (static) is: " << str1.myStrlen() << endl;
   cout << endl;
   cout << "*****Test 2  myStrlen*****" << endl;
   cout << "dynamic test" << endl;
   cout << "output should be the length of the command line input" << endl;
   cout << "The length of str2 (dynamic) is: " << str2->myStrlen() << endl;
   cout << "***************************************" << endl;
   // End Test of myStrlen

   // Test of isEqual
   cout << "***************************************" << endl;
   cout << "*****Test 1 isEqual*****" << endl;
   cout << "static test" << endl;
   cout << "output should be True" << endl;
   if (str1.isEqual(argv[1]))
   {
      cout << "True" << endl;
   }
   else
   {
      cout << "False" << endl;
   }
   cout << endl;
   cout << "*****Test 2 isEqual*****" << endl;
   cout << "dynamic test" << endl;
   cout << "output should be True" << endl;
   if (str2->isEqual(argv[1]))
   {
      cout << "True" << endl;
   }
   else
   {
      cout << "False" << endl;
   }
   cout << endl;
   cout << "*****Test 3 isEqual*****" << endl;
   cout << "static test" << endl;
   cout << "output should be False" << endl;
   if (str1.isEqual("Fake Input 1048592028588"))
   {
      cout << "True" << endl;
   }
   else
   {
      cout << "False" << endl;
   }
   cout << endl;
   cout << "*****Test 4 isEqual*****" << endl;
   cout << "dynamic test" << endl;
   cout << "output should be False" << endl;
   if (str2->isEqual("Fake Input 1048592028588"))
   {

      cout << "True" << endl;
   }
   else
      cout << "False" << endl;
   cout << "***************************************" << endl;
   // End Test of isEqual

   // Test of find
   cout << "***************************************" << endl;
   cout << "*****Test 1 find*****" << endl;
   cout << "static test" << endl;
   cout << "output should be the index where the substring starts, -1 if it isnt a substring" << endl;
   cout << "Substring \"the days\" starts at the index: " << str1.find("the days") << endl;
   cout << endl;
   cout << "*****Test 2  find*****" << endl;
   cout << "dynamic test" << endl;
   cout << "output should be the index where the substring starts, -1 if it isnt a substring" << endl;
   cout << "Substring \"the days\" starts at the index: " << str2->find("the days") << endl;
   cout << endl;
   cout << "*****Test 3  find*****" << endl;
   cout << "static test" << endl;
   cout << "output should be the index where the substring starts, -1 if it isnt a substring" << endl;
   cout << "Substring \"kthe days\" starts at the index: " << str1.find("kthe days") << endl;
   cout << endl;
   cout << "*****Test 4  find*****" << endl;
   cout << "dynamic test" << endl;
   cout << "output should be the index where the substring starts, -1 if it isnt a substring" << endl;
   cout << "Substring \"kthe days\" starts at the index: " << str2->find("kthe days") << endl;
   cout << "***************************************" << endl;
   // End Test of find

   // Test of concat
   cout << "***************************************" << endl;
   cout << "*****Test 1 concat*****" << endl;
   cout << "static test" << endl;
   cout << "output should be the cmd input concatinated with the sentence \"this is a test\"" << endl;
   str1.concat("this is a test");
   str1.myDisplay();
   cout << endl;
   cout << "*****Test 2  concat*****" << endl;
   cout << "dynamic test" << endl;
   cout << "output should be the cmd input concatinated with the sentence \"this is a test\"" << endl;
   str2->concat("this is a test");
   str2->myDisplay();
   cout << "***************************************" << endl;
   // End Test of concat
*/
   delete str2;
   return 0;
}