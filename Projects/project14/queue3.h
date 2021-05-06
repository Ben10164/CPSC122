/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 4/22/2021
Assignment: Project 14
Description: PQueue
To Compile: make -f makefile_pty 
To Execute: ./pqueue
*/

#ifndef PQUEUE
#define PQUEUE

#include "queue2.h"
/*
PQueue is a priority queue.  Nodes in PQueue are in ascending order by item
*/
class PQueue : public Queue
{
public:
   PQueue();
   PQueue(PQueue *q);

   /*
   pre: an instance of PQueue  exists. nodes in queue are in ascending order by 
        item;
   post: A new node is added to PQueue, which remains in sorted order 
   */
   void Enqueue(itemType newItem);

private:
   /*
   use: Used in Enqueue. 
   pre: Item to be inserted belongs somewhere between the head and tail  
   post: Returns the insertion point of the new item 
   */
   node *PtrTo(itemType newItem);

   /*
   use: Used in PtrTo. 
   pre: Item to be inserted is located at the head 
   post: item is inserted after the head 
   */
   void insertAtHead(node *newNode);

   /*
   use: Used in PtrTo. 
   pre: Item to be inserted is located at the tail 
   post: item is inserted before the tail 
   */
   void insertAtTail(node *newNode);

   /*
   use: Used in PtrTo. 
   pre: Item to be inserted is not located at the head or tail 
   post: item is inserted in their respective position 
   */
   void insertAnywhereElse(node *newNode, int index);
};
#endif
