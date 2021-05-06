#include <iostream>
#include <cstdlib>
#include <time.h>

#include "benVector.h"

using namespace std;

int *benVector::getArray() // returns the current array
{
   return nums_;
}
int benVector::getSize() // returns the current value of size
{
   return size_;
}
void benVector::insert(int index, int add) // inserts a specific number (add) at a specific index (index)
{
   int *newArray = createEmptyArray(size_ + 1);
   for (int i = 0; i < index; i++)
   {
      newArray[i] = nums_[i];
   }
   newArray[index] = add;
   for (int i = index + 1; i < size_ + 1; i++)
   {
      newArray[i] = nums_[i - 1];
   }
   setArray(newArray, size_ + 1);
}
void benVector::display() // displays the contents of the current array using cout
{
   for (int i = 0; i < size_; i++)
   {
      cout << nums_[i] << endl;
   }
}
int *benVector::createArray(int sizeUser) // creates an array that is 0 - sizeUser in their index, changes the value of size as well as the actual main array
{
   int *arrayStuff = new int[sizeUser];

   for (int i = 0; i < sizeUser; i++)
   {
      arrayStuff[i] = i;
   }
   setArray(arrayStuff, sizeUser);
   return arrayStuff;
}
void benVector::pushBack(int num) // adds a number (num) to the back of the main array
{
   insert(size_, num);
}
void benVector::shuffle() // shuffles the contents of the main array
{
   srand(time(NULL));
   for (int i = 0; i < size_; i++)
   {
      int randNum = rand() % size_;
      //cout << nums_[i] << " " << nums_[randNum] << endl;
      swap(i, randNum);
   }
}
void benVector::popBack(int amount)
{
   int newSize = size_ - amount;
   int *newArray = new int[newSize];
   for (int i = 0; i < newSize; i++)
   {
      //cout << newArray[i] << " is gonna equal " << nums_[i] << endl;
      newArray[i] = nums_[i];
   }
   setArray(newArray, newSize);
}
int benVector::at(int index)
{
   int returnVal = nums_[index];
   return returnVal;
}

int *nums_ = nullptr;
int size_;
void benVector::setArray(int *num, int sizeUser) // sets the main array
{
   if (nums_)
   {
      delete[] nums_;
   }
   nums_ = num;
   size_ = sizeUser;
}
void benVector::swap(int index1, int index2) // swaps the contents of two indexes in the main array
{
   int temp = nums_[index1];
   nums_[index1] = nums_[index2];
   nums_[index2] = temp;
}
int *benVector::createEmptyArray(int sizeUser) // creates an empty array with length sizeUser, also changes the value of size to sizeUser
{
   int *arrayStuff = new int[sizeUser];
   return arrayStuff;
}