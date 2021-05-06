/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 4/29/2021
Assignment: Project 15
Description: recursive functionality in list
To Compile: make 
To Execute: ./list
*/

#include <iostream>
using namespace std;

#include "list.h"

int main()
{
   List *lst1 = new List;
   for (int i = 0; i < 5; i++)
      lst1->PutItemH(i);
   cout << "lst1->Print();" << endl;
   lst1->Print();
   cout << "lst1->PrintRev();" << endl;
   lst1->PrintRev();
   cout << "delete lst1;" << endl;

   cout << "length" << endl;
   cout << lst1->GetLength();
   delete lst1;

   return 0;
}