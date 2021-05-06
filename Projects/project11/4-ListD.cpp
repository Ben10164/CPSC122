/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 
Assignment: N/A 
Description: header file for a doubly linked list with dummy notes at head and tail
*/

#include <iostream>
#include <climits>
#include "4-ListD.h"

using namespace std;

template <typename T>
ListD<T>::ListD()
{
   length = 0;

   //create dummy nodes;
   head = new doubleNode<T>;
   tail = new doubleNode<T>;

   //set values for head dummy node;
   head->prev = NULL;
   head->item = INT_MIN;
   head->next = tail;

   //set values for tail dummy node;
   tail->prev = head;
   tail->item = INT_MAX;
   tail->next = NULL;
}

template <typename T>
ListD<T>::ListD(ListD *lst)
{
   length = 0;

   //create dummy nodes;
   head = new doubleNode<T>;
   tail = new doubleNode<T>;

   //set values for head dummy node;
   head->prev = NULL;
   head->item = INT_MIN;
   head->next = tail;

   //set values for tail dummy node;
   tail->prev = head;
   tail->item = INT_MAX;
   tail->next = NULL;

   //returns pointer to the first node, which is what we want here
   doubleNode<T> *cur = lst->FindPosition(2);
   for (int i = 1; i <= lst->length; i++)
   {
      Insert(cur->item, i);
      cur = cur->next;
   }
}

template <typename T>
ListD<T>::~ListD()
{
   doubleNode<T> *temp = head;

   for (int i = 0; i < length; i++)
   {
      doubleNode<T> *del = temp;
      temp = temp->next;
      delete del;
   }
}

template <typename T>
void ListD<T>::Insert(T item, int pos)
{
   //new node goes between these two nodes
   doubleNode<T> *insertPtA = FindPosition(pos);
   doubleNode<T> *insertPtB = insertPtA->next;

   //create new node and set its values
   doubleNode<T> *tmp = new doubleNode<T>;
   tmp->prev = insertPtA;
   tmp->item = item;
   tmp->next = insertPtB;

   //set pointers for nodes before and after the insertion point
   insertPtA->next = tmp;
   insertPtB->prev = tmp;

   length++;
}

template <typename T>
void ListD<T>::Delete(int pos)
{
   if (1 <= pos && pos <= length)
   {
      if (pos == length)
      {
         doubleNode<T> *deletePtA = FindPosition(pos);
         doubleNode<T> *deletePtB = FindPosition(pos + 1);
         deletePtA->next = tail;
         tail->next = deletePtA;
         //free(deletePtB);
      }
      else if (pos < length && pos > 1)
      {
         doubleNode<T> *deletePtA = FindPosition(pos);
         doubleNode<T> *deletePtB = FindPosition(pos + 1);
         doubleNode<T> *deletePtC = FindPosition(pos + 2);
         deletePtA->next = deletePtC;
         deletePtC->prev = deletePtA;
         //free(deletePtB);
      }
      else if (pos == 1)
      {
         doubleNode<T> *deletePtA = FindPosition(pos + 2);
         doubleNode<T> *deletePtB = FindPosition(pos + 1);
         head->next = deletePtA;
         deletePtA->prev = head;
         //free(deletePtB);
      }
      length--;
   }
   else
   {
      cout << "Delete(" << pos << ") is out of range with the lenght of " << length << endl;
   }
}

template <typename T>
int ListD<T>::DeleteAll(T item)
{
   int pos = 1;
   int amount = 0;
   while (true)
   {
      if (pos == length)
      {
         break;
      }
      doubleNode<T> *cur = head->next;
      for (int i = 1; i < pos; i++)
      {
         cur = cur->next;
      }
      if (cur->item == item)
      {
         Delete(pos);
         amount++;
      }
      pos++;
   }
   return amount;
}

template <typename T>
void ListD<T>::PrintForward()
{
   doubleNode<T> *cur = head->next;

   int i = 0;
   while (i < length)
   {
      cout << cur->item << endl;
      cur = cur->next;
      i++;
   }
}

template <typename T>
void ListD<T>::PrintBackward()
{
   doubleNode<T> *cur = tail->prev;

   int i = 0;
   while (i < length)
   {
      cout << cur->item << endl;
      cur = cur->prev;
      i++;
   }
}

template <typename T>
void ListD<T>::Sort()
{
   bool isSorted = false;
   while (!isSorted)
   {
      isSorted = true; // so then it will be marked false if the test fails
      doubleNode<T> *test = head->next;
      for (int i = 0; i < length - 2; i++)
      {
         if (test->item > test->next->item)
         {
            isSorted = false;
            break;
         }
         test = test->next;
      }
      int pos = 1;
      while (true)
      {
         if (pos == length)
         {
            break;
         }
         doubleNode<T> *cur = head->next;
         for (int i = 1; i < pos; i++)
         {
            cur = cur->next;
         }
         if (cur->item > cur->next->item)
         {
            doubleNode<T> *next = FindPosition(pos + 2);
            doubleNode<T> *after = FindPosition(pos + 3);
            doubleNode<T> *before = FindPosition(pos);
            before->next = next;
            next->prev = before;
            next->next = cur;
            cur->prev = next;
            cur->next = after;
            after->prev = cur;
         }
         pos++;
      }
   }
}

template <typename T>
doubleNode<T> *ListD<T>::FindPosition(int pos)
{
   //Inserting at the tail is a special case.  It can be made much more efficient than
   //this.
   doubleNode<T> *cur = head;
   int i = 0; //begin at the dummy node
   while (i < pos - 1)
   {
      cur = cur->next;
      i++;
   }
   return cur;
}