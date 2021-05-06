/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 
Assignment: Project 13
Description: Part 2 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include <iostream>
using namespace std;

#include "calc.h"

int main(int argc, char *argv[])
{
   Calc *C = new Calc(argv[1]);

   cout << C->Evaluate() << endl;

   C->~Calc();

   return 0;
}
