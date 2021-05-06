/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: March 11, 2021
Assignment: Project 9
Description: Program illustrates a simple linked list 
Notes: https://stackoverflow.com/questions/2265967/writing-a-linkedlist-destructor 
*/

#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
   // Needed for all tests
   List lst;              // sets up static list
   List *lst1 = new List; // sets up dynamic lust

   for (int i = 0; i < 5; i++)
   {
      lst.PutItemH(i); // adds values 0-4 to static list
   }
   for (int i = 0; i < 5; i++)
   {
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust
   }

   //////////////////////
   /// TESTS ////////////
   //////////////////////

   /*
   // Test for IsEmpty
   cout << "Test for IsEmpty()" << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: List is not empty" << endl;
   if (lst.IsEmpty())
   {
      cout << "List is empty" << endl;
   }
   else
   {
      cout << "List is not empty" << endl;
   }

   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: List is not empty" << endl;
   if (lst1->IsEmpty())
   {
      cout << "List is empty" << endl;
   }
   else
   {
      cout << "List is not empty" << endl;
   }
*/

   /*
   // Test for GetLength
   cout << "Test for getLength()" << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: The length of lst (5)" << endl;
   cout << "The length of lst is " << lst.GetLength() << endl;

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: The length of lst1 (5)" << endl;
   cout << "The length of lst1 is " << lst1->GetLength() << endl;
*/

   /*
   // Test for PutItemH
   cout << "Test for putItemH()" << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: lst.Print() with the number 10 added to the front" << endl;
   cout << "lst.PutItemH(10);" << endl;
   lst.PutItemH(10);

   lst.Print();

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: lst1->Print() with the number 10 added to the front" << endl;
   cout << "lst1->PutItemH(10);" << endl;
   lst1->PutItemH(10);
   lst1->Print();
*/

   /*
   // Test for GetItemH
   cout << "Test for GetItemH()" << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: The head of lst" << endl;
   cout << "The head of lst is: " << lst.GetItemH() << endl;

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: The head of lst1" << endl;
   cout << "The head of lst1 is: " << lst1->GetItemH() << endl;
*/

   /*
   // Test for DeleteItemH
   cout << "Test for DeleteItemH()" << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: str.Print() before and after lst.DeleteItemH() is called" << endl;
   cout << "Before:" << endl;
   lst.Print();
   cout << endl;
   cout << "lst.DeleteItemH();" << endl;
   lst.DeleteItemH();
   lst.Print();

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: str1->Print() before and after lst1->DeleteItemH() is called" << endl;
   cout << "Before:" << endl;
   lst1->Print();
   cout << endl;
   cout << "lst1->DeleteItemH();" << endl;
   lst1->DeleteItemH();
   lst1->Print();
*/

   /*
   // Test for Print
   cout << "Test for Print()" << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: 4 - 0 on separate lines" << endl;
   lst.Print();

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: 40 - 0 (increments of 10) on separate lines" << endl;
   lst1->Print();
*/

   /*
   // Test for Find
   cout << "Test for Find()" << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: lst.Print() followed by the position that 3 is located in lst" << endl;
   lst.Print();
   cout << "The location of 3 in lst is " << lst.Find(3) << endl;

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: lst1->Print() followed by the position that 30 is located in lst1" << endl;
   lst1->Print();
   cout << "The location of 30 in lst1 is " << lst1->Find(30) << endl;
*/

   /*
   // Test for DeleteItem
   cout << "Test for DeleteItem()" << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: str.Print() before and after lst.DeleteItem(2) is called" << endl;
   cout << "Before:" << endl;
   lst.Print();
   cout << endl;
   cout << "lst.DeleteItem(2);" << endl;
   lst.DeleteItem(2);
   lst.Print();

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: str1->Print() before and after lst1->DeleteItem(2) is called" << endl;
   cout << "Before:" << endl;
   lst1->Print();
   cout << endl;
   cout << "lst1->DeleteItem(2);" << endl;
   lst1->DeleteItem(2);
   lst1->Print();
*/
   delete lst1; // necessary to invoke destructor on dynamic list
   return 0;
}