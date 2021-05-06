/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 3/18/2021
Assignment: Project 10
Description: Completes all the requirements of Project 10 ()
Notes: https://stackoverflow.com/questions/2265967/writing-a-linkedlist-destructor 
*/

#include <iostream>
using namespace std;

#include "3-ListT.h"

int main(int argc, char *argv[])
{
   // Needed for all tests
   ListT lst;               // sets up static list
   ListT *lst1 = new ListT; // sets up dynamic list

   // I hope its okay that the tests were made to be tested individually

   //////////////////////
   // Test for IsEmpty //
   //////////////////////
/*
   cout << "Test for IsEmpty()" << endl;

   cout << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: List is empty" << endl;
   if (lst.IsEmpty())
      cout << "List is empty" << endl;
   else
      cout << "List is not empty" << endl;

   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: List is empty" << endl;
   if (lst1->IsEmpty())
      cout << "List is empty" << endl;
   else
      cout << "List is not empty" << endl;

   cout << endl;

   cout << "Now adding values to the lists" << endl;

   cout << endl;
   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: List is not empty" << endl;
   if (lst.IsEmpty())
      cout << "List is empty" << endl;
   else
      cout << "List is not empty" << endl;

   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: List is not empty" << endl;
   if (lst1->IsEmpty())
      cout << "List is empty" << endl;
   else
      cout << "List is not empty" << endl;
*/
   ////////////////////////
   // Test for GetLength //
   ////////////////////////
/*
   cout << "Test for GetLength()" << endl;

   cout << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: The length of lst (0)" << endl;
   cout << "The length of lst is " << lst.GetLength() << endl;
   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: The length of lst1 (0)" << endl;
   cout << "The length of lst1 is " << lst1->GetLength() << endl;

   cout << endl;

   cout << "Now adding values to lst and lst1" << endl;

   cout << endl;
   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: The length of lst (5)" << endl;
   cout << "The length of lst is " << lst.GetLength() << endl;
   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: The length of lst1 (5)" << endl;
   cout << "The length of lst1 is " << lst1->GetLength() << endl;
*/
   ///////////////////////
   // Test for PutItemH //
   ///////////////////////
/*
   cout << "Test for PutItemH(const itemType newItem)" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

   cout << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: lst.Print() followed by lst.Print() after lst.PutItemH(100)" << endl;
   lst.Print();
   cout << "After lst.PutItemH(100)" << endl;
   lst.PutItemH(100);
   lst.Print();

   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: lst1->Print() followed by lst1->Print() after lst1->PutItemH(100)" << endl;
   lst1->Print();
   cout << "After lst1->PutItemH(100)" << endl;
   lst1->PutItemH(100);
   lst1->Print();
*/
   /////////////////////////
   // Test for GetItemH() //
   /////////////////////////
/*
   cout << "Test for GetItemH()" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

   cout << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: The head of lst (4)" << endl;
   cout << lst.GetItemH() << endl;
   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: The head of lst1 (40)" << endl;
   cout << lst1->GetItemH() << endl;
*/
   //////////////////////////
   // Test for DeleteItemH //
   //////////////////////////
/*
   cout << "Test for DeleteItemH()" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

   cout << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: lst.Print() before and after lst.DeleteItemH()" << endl;
   lst.Print();
   cout << "After lst.DeleteItemH()" << endl;
   lst.DeleteItemH();
   lst.Print();
   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: lst1->Print() before and after lst1->DeleteItemH()" << endl;
   lst1->Print();
   cout << "After lst1->DeleteItemH()" << endl;
   lst1->DeleteItemH();
   lst1->Print();
*/
   ///////////////////////
   // Test for PutItemT //
   ///////////////////////
/*
   cout << "Test for PutItemT(const itemType newItem)" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

   cout << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: lst.Print() followed by lst.Print() after lst.PutItemT(100)" << endl;
   lst.Print();
   cout << "After lst.PutItemT(100)" << endl;
   lst.PutItemT(100);
   lst.Print();

   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: lst1->Print() followed by lst1->Print() after lst1->PutItemT(100)" << endl;
   lst1->Print();
   cout << "After lst1->PutItemT(100)" << endl;
   lst1->PutItemT(100);
   lst1->Print();
*/
   /////////////////////////
   // Test for GetItemT() //
   /////////////////////////
/*
   cout << "Test for GetItemT()" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

   cout << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: The tail of lst (0)" << endl;
   cout << lst.GetItemT() << endl;
   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: The tail of lst1 (0)" << endl;
   cout << lst1->GetItemT() << endl;
*/
   ////////////////////////////
   // Test for DeleteItemT() //
   ////////////////////////////
/*
   cout << "Test for DeleteItemT()" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

   cout << endl;

   // Use of a static list
   cout << "Static test" << endl;
   cout << "expected output: lst.Print() before and after lst.DeleteItemT()" << endl;
   lst.Print();
   cout << "After lst.DeleteItemT()" << endl;
   lst.DeleteItemT();
   lst.Print();
   cout << endl;

   // Use of a dynamic list
   cout << "dynamic test" << endl;
   cout << "expected output: lst1->Print() before and after lst1->DeleteItemT()" << endl;
   lst1->Print();
   cout << "After lst1->DeleteItemT()" << endl;
   lst1->DeleteItemT();
   lst1->Print();
*/
   //////////////////////
   // Test for Print() //
   //////////////////////
/*
   cout << "Test for Print()" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(10 * i); // adds values 0-40(increments of 10) to dynamic lust

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
   /////////////////////////
   // Test for FindItem() //
   /////////////////////////
/*
   cout << "Test for FindItem()" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i%2); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH((10 * i)%20); // adds values 0-40(increments of 10) to dynamic lust

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: lst.Print() followed by the amount of times 1 shows up in lst" << endl;
   lst.Print();
   cout << "1 is in lst " << lst.FindItem(1) << " times" << endl;

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: lst1->Print() followed by the amount of times 0 shows up in lst1" << endl;
   lst1->Print();
   cout << "0 is in lst1 " << lst1->FindItem(0) << " times" << endl;
*/
   /////////////////////////
   // Test for DeleteItem //
   /////////////////////////
/*
   cout << "Test for DeleteItem()" << endl;

   for (int i = 0; i < 5; i++)
      lst.PutItemH(i%2); // adds values 0-4 to static list
   for (int i = 0; i < 5; i++)
      lst1->PutItemH((10 * i)%20); // adds values 0-40(increments of 10) to dynamic lust

   // Use of a static list
   cout << "Static test" << endl;
   cout << "Expected output: str.Print() before and after lst.DeleteItem(0) is called, as well as the amount deleted (3)" << endl;
   cout << "Before:" << endl;
   lst.Print();
   cout << endl;
   cout << "After lst.DeleteItem(0)" << endl;
   cout << "Deleted a total of " << lst.DeleteItem(0) << endl;
   cout << endl;
   lst.Print();

   cout << endl;

   // Use of a dynamic list
   cout << "Dynamic test" << endl;
   cout << "Expected output: str1->Print() before and after lst1->DeleteItem(10) is called, as well as the amount deleted (2)" << endl;
   cout << "Before:" << endl;
   lst1->Print();
   cout << endl;
   cout << "After lst1->DeleteItem(10)" << endl;
   cout << "Deleted a total of " << lst1->DeleteItem(10) << endl;
   cout << endl;
   lst1->Print();
*/
}