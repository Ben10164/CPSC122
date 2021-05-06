/*
   THIS VERSION OF PROJECT13 WAS MADE BEFORE DEPALMA UPLOADED THE 
   STARTER CODE OF PROJECT13
*/
/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: April 8th, 2021
Assignment: Project 12
Description: Part 1 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

//Stack implemented using a List and inheritance
#ifndef STACK_H
#define STACK_H

#include "list.h"

class Stack : public List
{
public:
   Stack();

   /*
   pre: an instance of stack exists
   post: newItem is at the top of the stack 
   */
   void Push(itemType newItem);

   /*
   pre: an instance of stack exists and is not empty
   post: top of the stack has been removed 
   */
   void Pop();

   /*
   pre: an instance of stack exists and is not empty
   post: returns the top of the stack. stack is undisturbed 
   */
   itemType Peek();
};
#endif
