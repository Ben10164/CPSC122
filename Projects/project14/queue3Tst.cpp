/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 4/22/2021
Assignment: Project 14
Description: PQueue
To Compile: make -f makefile_pty 
To Execute: ./pqueue
*/

#include <iostream>
using namespace std;

#include "queue3.h"

int main(int argc, char *argv[])
{
   int amt = 10;
   if (argc > 1)
   {
      amt = stoi(argv[1]);
   }
   PQueue *que = new PQueue;
   for (int i = 0; i < amt; i += 2)
   {
      que->Enqueue(i);
   }
   que->Print();
   cout << endl;
   for (int i = 1; i < amt; i += 2)
   {
      que->Enqueue(i);
   }
   que->Print();
   delete que;
}