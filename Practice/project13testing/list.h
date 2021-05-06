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

#ifndef LIST_H
#define LIST_H

typedef int itemType;

struct node
{
   itemType item;
   node *next;
};

class List
{
public:
   List();
   ~List();

   /*
   pre: an instance of lists exists
   post: returns true if list is empty, false otherwise
   */
   bool IsEmpty() const;

   /*
   pre: an instance of list exists
   post: returns length of the list 
   */
   int GetLength() const;

   /*
   pre: an instance of list exists
   post: newItem is at the head of the list 
   */
   void PutItemH(const itemType item);

   /*
   pre: an instance of list exists and is not empty
   post: Returns the contents of the head of the list. 
   */
   itemType GetItemH() const;

   /*
   pre: an instance of list exists and is not empty
   post: head of the list is deleted 
   */
   void DeleteItemH();

   /*
   pre: an instance of list exists and is not empty
   post: contents of list nodes are displayed on subsequent lines 
   */
   void Print() const;

   //protected:
private:
   int length; //length of the list
   node *head; //point to the first node on the list
};
#endif
