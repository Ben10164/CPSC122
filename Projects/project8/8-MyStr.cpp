#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>

//Constructor function
MyString::MyString(char const *strIn)
{
   int i = 0;
   while (strIn[i] != '\0')
   {
      i++;
   }
   length = i;
   str = new char[length + 1];
   i = 0;
   while (i < (length + 1))
   {
      str[i] = strIn[i];
      i++;
   }
}

//Destructor function
MyString::~MyString()
{
   delete[] str;
}

/*
   Desc: Displays the contents of MyString 
   Pre: None
   Post: Contents of MyString are displayed on the screen 
   */
void MyString::myDisplay()
{
   cout << str << endl;
}

/*
   Desc: Overwrites contents of MyString.str with what strIn points to 
   Pre: strIn is a null-terminated string 
   Post: contents of strIn replaces MyString 
   */
void MyString::myStrcpy(char const *strIn)
{
   int i = 0;
   while (strIn[i] != '\0')
   {
      i++;
   }
   length = i;
   str = new char[length + 1];
   i = 0;
   while (i < (length + 1))
   {
      str[i] = strIn[i];
      i++;
   }
}

/*
   Desc: Used to determine the length of MyString.str
   Pre:  An instance of MyString exists
   Post: Returns the number of characters, excluding the null character
         in MyString. 
   */
int MyString::myStrlen()
{
   int i = 0;
   while (str[i] != '\0')
   {
      i++;
   }
   return i;
}

/*
   Desc: Determines if MyString.str is equivalent to an input C-String 
   Pre:  An instance of MyString exists. strIn is a null-terminated
         string.
   Post: Returns true if the strings are equivalent, false otherwise 
   */
bool MyString::isEqual(char const *strIn)
{
   int i = 0;
   while (i < length + 1)
   { // the +1 makes sure we are counting the '\0' so both strings end at the same time
      if (str[i] != strIn[i])
      {
         return false;
      }
      i++;
   }
   return true;
}

/*
   Desc: Searches for a substring within MyString 
   Pre:  An instance of MyString exists
   Post: If strIn is a substring of MyString.str, returns
         the index of its starting position, -1 otherwise
   */
int MyString::find(char const *strIn)
{
   //get length of strIn
   int strInLen = 0;
   while (strIn[strInLen] != '\0')
   {
      strInLen++;
   }
   if (strInLen > length)
   { // strIn is larger than str
      return -1;
   }
   if (strInLen == length)
   { // they are the same length
      if (isEqual(strIn))
      { // check if they are equal
         return 0;
      }
      else
      {
         return -1;
      }
   }
   for (int i = 0; i < length - strInLen + 1; i++)
   {
      if (isSub(strIn, i))
      {
         return i;
      }
   }
   return -1;
}

/*
   Desc: Concatenates strIn with MyString 
   Pre:  An instance of MyString exists. strIn is a null-terminated string
   Post: strIn is concatenated with MyString.str.  Ex.
         MyString.str is ABC. strIn is DEF.  MyString is still a null-terminated
	 string, but contains: ABCDEF. 
   */
void MyString::concat(char const *strIn)
{
   //get length of strIn
   int strInLen = 0;
   while (strIn[strInLen] != '\0')
   {
      strInLen++;
   }
   char *tmp = new char[length + strInLen + 1];
   for (int i = 0; i < length; i++)
   {
      tmp[i] = str[i];
   }
   for (int i = 0; i < strInLen; i++)
   {
      tmp[length + i] = strIn[i];
   }
   str = tmp;
   length = length + strInLen;
}

/*
   Desc: Used in conjunction with the function, find. Loops through MyString starting
         with idx looking for strIn.
   pre: idx is the first character of MyString.str that matches the substring, strIn
   post: returns true if strIn is a substring of str, false otherwise. 
         Used by find()
   */
bool MyString::isSub(char const *strIn, int idx)
{
   //get length of strIn
   int strInLen = 0;
   while (strIn[strInLen] != '\0')
   {
      strInLen++;
   }
   for (int i = 0; i < strInLen; i++)
   {
      if (str[idx + i] != strIn[i])
      {
         return false;
      }
   }
   return true;
}