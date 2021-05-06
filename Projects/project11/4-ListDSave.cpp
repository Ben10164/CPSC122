#include <iostream>
#include <climits>

using namespace std;

#include "4-ListD.h"

ListD::ListD()
{
   length = 0;

   //create dummy nodes;
   head = new doubleNode;
   tail = new doubleNode;

   //set values for head dummy node;
   head->prev = NULL;
   head->item = INT_MIN;
   head->next = tail;

   //set values for tail dummy node;
   tail->prev = head;
   tail->item = INT_MAX;
   tail->next = NULL;
}

ListD::ListD(ListD *lst)
{
   length = 0;

   //create dummy nodes;
   head = new doubleNode;
   tail = new doubleNode;

   //set values for head dummy node;
   head->prev = NULL;
   head->item = INT_MIN;
   head->next = tail;

   //set values for tail dummy node;
   tail->prev = head;
   tail->item = INT_MAX;
   tail->next = NULL;

   //returns pointer to the first node, which is what we want here
   doubleNode *cur = lst->FindPosition(2);
   for (int i = 1; i <= lst->length; i++)
   {
      Insert(cur->item, i);
      cur = cur->next;
   }
}

ListD::~ListD()
{
   doubleNode *temp = head;

  for (int i = 0; i < length; i ++)
  {
    doubleNode *del = temp;
    temp = temp->next;
    delete del;
  }
}

void ListD::Insert(itemType item, int pos)
{
   //new node goes between these two nodes
   doubleNode *insertPtA = FindPosition(pos);
   doubleNode *insertPtB = insertPtA->next;

   //create new node and set its values
   doubleNode *tmp = new doubleNode;
   tmp->prev = insertPtA;
   tmp->item = item;
   tmp->next = insertPtB;

   //set pointers for nodes before and after the insertion point
   insertPtA->next = tmp;
   insertPtB->prev = tmp;

   length++;
}

void ListD::Delete(int pos)
{
   if (1 <= pos && pos <= length)
   {
      if (pos == length)
      {
         doubleNode *deletePtA = FindPosition(pos);
         doubleNode *deletePtB = FindPosition(pos + 1);
         deletePtA->next = tail;
         tail->next = deletePtA;
         //free(deletePtB);
      }
      else if (pos < length && pos > 1)
      {
         doubleNode *deletePtA = FindPosition(pos);
         doubleNode *deletePtB = FindPosition(pos + 1);
         doubleNode *deletePtC = FindPosition(pos + 2);
         deletePtA->next = deletePtC;
         deletePtC->prev = deletePtA;
         //free(deletePtB);
      }
      else if (pos == 1)
      {
         doubleNode *deletePtA = FindPosition(pos + 2);
         doubleNode *deletePtB = FindPosition(pos + 1);
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

int ListD::DeleteAll(itemType item)
{
   int pos = 1;
   int amount = 0;
   while (true)
   {
      if (pos == length)
      {
         break;
      }
      doubleNode *cur = head->next;
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

void ListD::PrintForward()
{
   doubleNode *cur = head->next;

   int i = 0;
   while (i < length)
   {
      cout << cur->item << endl;
      cur = cur->next;
      i++;
   }
}

void ListD::PrintBackward()
{
   doubleNode *cur = tail->prev;

   int i = 0;
   while (i < length)
   {
      cout << cur->item << endl;
      cur = cur->prev;
      i++;
   }
}

void ListD::Sort()
{
   bool isSorted = false;
   while (!isSorted)
   {
      isSorted = true; // so then it will be marked false if the test fails
      doubleNode *test = head->next;
      for (int i = 0; i < length; i++)
      {
         if (test->item > test->next->item)
         {
            isSorted = false;
         }
      }
      int pos = 1;
      while (true)
      {
         if (pos == length)
         {
            break;
         }
         doubleNode *cur = head->next;
         for (int i = 1; i < pos; i++)
         {
            cur = cur->next;
         }
         if (cur->item > cur->next->item)
         {
            doubleNode *next = FindPosition(pos + 2);
            doubleNode *after = FindPosition(pos + 3);
            doubleNode *before = FindPosition(pos);
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

doubleNode *ListD::FindPosition(int pos)
{
   //Inserting at the tail is a special case.  It can be made much more efficient than
   //this.
   doubleNode *cur = head;
   int i = 0; //begin at the dummy node
   while (i < pos - 1)
   {
      cur = cur->next;
      i++;
   }
   return cur;
}