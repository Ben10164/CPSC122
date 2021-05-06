#ifndef BENVECTOR_H
#define BENVECTOR_H

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class benVector
{
public:
   int *getArray();                 // returns the current array
   int getSize();                   // returns the current value of size
   void insert(int index, int add); // inserts a specific number (add) at a specific index (index)
   void display();                  // displays the contents of the current array using cout
   int *createArray(int sizeUser);  // creates an array that is 0 - sizeUser in their index, changes the value of size as well as the actual main array
   void pushBack(int num);          // adds a number (num) to the back of the main array
   void shuffle();                  // shuffles the contents of the main array
   void popBack(int amount);        // deletes an amount (amount) of indexes from the back of the main array
   int at(int index);               // returns the value of the main array at the index passed through (index)

private:
   int *nums_ = nullptr;
   int size_;
   void setArray(int *num, int sizeUser); // sets the main array
   void swap(int index1, int index2);     // swaps the contents of two indexes in the main array
   int *createEmptyArray(int sizeUser);   // creates an empty array with length sizeUser, also changes the value of size to sizeUser
};

#endif