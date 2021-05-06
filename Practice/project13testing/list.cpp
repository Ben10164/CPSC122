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

#include <iostream>
using namespace std;

#include "list.h"

List::List()
{
   head = NULL;
   length = 0;
}

List::~List()
{
   while (length > 0)
      DeleteItemH();
}

bool List::IsEmpty() const
{
   if (length == 0)
      return true;
   else
      return false;
}

int List::GetLength() const
{
   return length;
}

void List::PutItemH(const itemType item)
{
   node *tmp = new node;
   tmp->item = item;
   tmp->next = head;
   head = tmp;
   length++;
   tmp = NULL;
}

itemType List::GetItemH() const
{
   return head->item;
}

void List::DeleteItemH()
{
   node *cur = head;
   head = head->next;
   delete cur;
   length--;
}

void List::Print() const
{
   node *cur = head;
   for (int i = 0; i < length; i++)
   {
      cout << cur->item << endl;
      cur = cur->next;
   }
}
