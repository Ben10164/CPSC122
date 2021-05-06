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

PQueue::PQueue() : Queue()
{
   length = 0;
   head = NULL;
   tail = NULL;
}

PQueue::PQueue(PQueue *q) : Queue(q)
{
   length = 0;
   head = NULL;
   tail = NULL;
   node *origLst = q->head; //pointer to cur item  in the original list
   int i = 0;
   while (i < q->length)
   {
      PutItemT(origLst->item);
      origLst = origLst->next;
      i++;
   }
}

void PQueue::Enqueue(itemType newItem)
{
   node *newNode = new node;
   newNode->item = newItem;
   newNode->next = NULL;
   node *posTemp = PtrTo(newItem);
   node *temp = head;
   int index = 0;
   while (temp != posTemp) // FINDS THE INDEX OF THE POSITION IT SHOULD BE IN behind OF
   {
      index++;
      temp = temp->next;
   }
   if (IsEmpty())
      PutItemH(newItem);
   else if (index == length && index != 0) //last position
      insertAtTail(newNode);
   else
      insertAnywhereElse(newNode, index);
}

node *PQueue::PtrTo(itemType newItem)
{
   if (IsEmpty())
      return head;
   else
   {
      node *temp = head;
      while (temp != NULL) // FINDS THE INDEX OF THE POSITION IT SHOULD BE IN FRONT OF
      {
         if (temp->next != NULL)
            if (temp->next->item >= newItem)
               return temp;
         temp = temp->next;
      }
      return temp;
   }
}

void PQueue::insertAtHead(node *newNode)
{
   newNode->next = head;
   head = newNode;
   if (length == 0)
      tail = newNode;
   length++;
}
void PQueue::insertAtTail(node *newNode)
{
   tail->next = newNode;
   tail = newNode;
   length++;
}
void PQueue::insertAnywhereElse(node *newNode, int index)
{
   node *temp2 = head;
   for (int i = 0; i < index; i++)
      temp2 = temp2->next;
   newNode->next = temp2->next;
   temp2->next = newNode;
   length++;
}