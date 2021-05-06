/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 3/18/2021
Assignment: Project 10
Description: Completes all the requirements of Project 10 (Writing a Linked List Class with both Head and Tail Pointers)
Notes: https://stackoverflow.com/questions/2265967/writing-a-linkedlist-destructor 
*/

#include <iostream>
using namespace std;

#include "3-ListT.h"

/*
   pre: None. This is the constructor function, invoked like this from the 
        the test program (ex33Tst.cpp):
        List1 lst;
	or
	List1* lst = new List1;
   post: an instance of List1 exists
   */
ListT::ListT()
{
   head = NULL;
   length = 0;
   tail = NULL;
}

/*
   pre: An instance of List1 exists.  This is the destructor function, automatically
        invoked in the case of a static declaration, explcitly invoked, using the delete
        key word, in the case of a dynamic declaration.	
   post: All dynamically declared memory, i.e., the memory for all nodes, has been
        returned to the heap.   
   */
ListT::~ListT()
{
   delete head;
   delete tail;
}

/*
   pre: an instance of lists exists
   post: returns true if list is empty, false otherwise
   */
bool ListT::IsEmpty() const
{
   int len = GetLength();
   if (len == 0)
   {
      return true;
   }
   return false;
}

/*
   pre: an instance of list exists
   post: returns length of the list 
   */
int ListT::GetLength() const
{
   node *temp = head;
   int len = 0;
   while (temp != NULL)
   {
      //cout << "len " << len << " is " << temp->item << endl; // debug
      len++;
      temp = temp->next;
   }
   return len;
}

/*
   pre: an instance of list exists
   post: newItem is at the head of the list 
   */
void ListT::PutItemH(const itemType newItem)
{
   bool empty = false;
   if (IsEmpty())
   {
      empty = true;
   }
   node *temp = new node;
   temp->item = newItem;
   temp->next = head;
   head = temp;
   if (empty)
   {
      tail = temp;
   }

   length = GetLength();
   // Lower bigO alternative
   // length++;

   temp = NULL;
}

/*
   pre: an instance of list exists and is not empty
   post: Returns the contents of the head of the list. 
   */
itemType ListT::GetItemH() const
{
   itemType item = head->item;
   return item;
}

/*
   pre: an instance of list exists and is not empty
   post: head of the list is deleted 
   */
void ListT::DeleteItemH()
{
   node *temp = head;
   temp = temp->next;
   head = temp;
   length = GetLength();
   // Lower bigO alternative
   // length--;
   temp = NULL;
}

/*
   pre: an instance of list exists
   post: newItem is at the tail of the list 
   */
void ListT::PutItemT(const itemType newItem)
{
   bool empty = false;
   if (IsEmpty())
   {
      empty = true;
   }
   node *temp = new node;
   temp->item = newItem;
   tail = temp;
   node *last = PtrTo();
   last->next = temp;
   if (empty)
   {
      head = temp;
   }

   length++;
   // or could be (but higher bigO value)
   length = GetLength();
   temp = NULL;
}

/*
   pre: an instance of list exists and is not empty
   post: Returns the contents of the tail of the list. 
   */
itemType ListT::GetItemT() const
{
   itemType item = tail->item;
   return item;
}

/*
   pre: an instance of list exists and is not empty
   post: tail of the list is deleted 
   */
void ListT::DeleteItemT()
{
   node *last = PtrTo();
   node *temp = new node;
   temp = head;
   while (temp->next != last)
   {
      temp = temp->next;
   }
   tail->next = temp;
   temp->next = NULL;
   free(last);
   length = GetLength();
   // or with smaller bigO val
   // length --;
}

/*
   pre: an instance of list exists and is not empty
   post: contents of list nodes are displayed on subsequent lines, head to tail. 
   */
void ListT::Print() const
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

/*
   pre: an instance of list exists and is not empty
   post: returns the number of nodes in the list that store target 
   */
int ListT::FindItem(const itemType target) const
{
   int count = 0;
   node *temp = new node;
   temp = head;
   int i = 1;
   while (temp != NULL)
   {
      if (temp->item == target)
      {
         count++;
      }
      i++;
      temp = temp->next;
   }
   return count;
}

/*
   pre:  an instance of List exists and is not empty 
   post: deletes all nodes that store target.  Returns
         the number of nodes deleted 
   */
int ListT::DeleteItem(const itemType target)
{
   int amt = 0;
   node *temp = head;

   while (head->item == target) // if the first one is target
   {
      amt++;
      head = head->next;
   }
   while (temp->next != NULL)
   {
      if (temp->next->item == target)
      {
         amt++;
         temp->next = temp->next->next;
      }
      else
      {
         temp = temp->next;
      }
   }
   length = GetLength();
   return amt;
}

/*
   pre: length of list > 1 
   post: returns the address of the node just before the 
         node pointed to by the tail 
   */
node *ListT::PtrTo()
{
   node *temp = new node;
   temp = head;
   while (temp->next != tail->next)
   {
      temp = temp->next;
   }
   return temp;
}