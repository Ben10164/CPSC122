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

List::List()
{
   length = 0;
   head = NULL;
}

List::~List()
{
   delete head;
}

bool List::IsEmpty() const
{
   if (length == 0)
   {
      return true;
   }
   return false;
}

int List::GetLength() const
{
   return length;
}

void List::PutItemH(const itemType newItem)
{
   node *temp = new node;
   temp->item = newItem;
   temp->next = head;
   head = temp;
   length++;
   temp = NULL;
}

itemType List::GetItemH() const
{
   node *temp = head;
   return temp->item;
}

void List::DeleteItemH()
{
   node *temp = head;
   temp = temp->next;
   head = temp;
   length--;
   temp = NULL;
}

void List::Print() const
{
   node *temp = new node;
   temp = head;
   int i = 0;
   while (i < length)
   {
      cout << temp->item << endl;
      temp = temp->next;
      i++;
   }
}

int List::Find(const itemType item) const
{
   node *temp = new node;
   temp = head;
   for (int i = 1; i <= length; i++)
   {
      if (temp->item == item)
      {
         return i;
      }
      temp = temp->next;
   }
   return -1;
}

void List::DeleteItem(const int pos)
{
   node *temp1 = head;
   node *temp2 = NULL;
   if (pos == 0)
   {
      DeleteItemH();
   }
   for (int i = 0; i < pos - 2; i++)
   {
      if (temp1->next == NULL) // in theory should never happen
      {
         break;
      }
      temp1 = temp1->next;
   }
   temp2 = temp1->next;
   temp1->next = temp2->next;
   length--;
}