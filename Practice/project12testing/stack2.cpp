/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: April 9th, 2021
Assignment: Project 12
Description: Part 1 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

//Stack implemented using List and inheritance
#include <iostream>
using namespace std;

#include "stack2.h"

Stack::Stack() : List()
{
}

void Stack::Push(itemType newItem)
{
   PutItemH(newItem);
}

void Stack::Pop()
{
   DeleteItemH();
}

itemType Stack::Peek()
{
   return GetItemH();
}
