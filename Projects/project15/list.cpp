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

//Non-recursive functions. I have written them for you.
List::List()
{
   head = NULL;
}

bool List::IsEmpty()
{
   if (head == NULL)
      return true;
   return false;
}

void List::PutItemH(itemType item)
{
   node *tmp = new node;
   tmp->item = item;
   tmp->next = head;
   head = tmp;
   tmp = NULL;
}

itemType List::GetItemH()
{
   return head->item;
}

void List::DeleteItemH()
{
   node *cur = head;
   head = head->next;
   delete cur;
   cur == NULL;
}

//Write the following functions recursively or in such a way that they use
//recursive functions.  You may add recursive utility functions to the
//private section of the header (.h) file.

List::~List()
{
   if (IsEmpty())
      delete head;
   else
   {
      node *temp = head->next;
      delete temp;
   }
}

int List::GetLength()
{
   if (head->next == NULL)
      return -1;
   node *temp = head->next;
   int returnVal = 1 + GetLength(temp);
   return returnVal;
}

int List::GetLength(node *temp)
{
   if (temp == NULL)
      return 0;
   return 1 + GetLength(temp->next);
}

void List::Print()
{
   node *temp = head;
   Print(temp);
}

void List::PrintRev()
{
   node *temp = head;
   PrintRev(temp);
}

void List::PrintRev(node *temp)
{
   if (temp == NULL)
      return;
   PrintRev(temp->next);
   cout << temp->item << endl;
}

void List::Print(node *temp)
{
   if (temp == NULL)
      return;
   cout << temp->item << endl;
   Print(temp->next);
}
