/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: April 9th, 2021
Assignment: Project 12
Description: Part 1 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>

//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

/*
   char *inFix;   //null-terminated string that holds infix expression
   int *valueTbl; //pointer to an array holding variable and expression values
   int valueIdx;  //index of the next available position in valueTbl
   Stack *stk;
*/
Calc::Calc(char *argvIn)
{
   stk = new Stack;

   inFix = new char[strlen(argvIn) + 1];
   strcpy(inFix, argvIn);

   if (!CheckParens())
   {
      cout << "Sorry but the parens are not balanced" << endl;
      exit(EXIT_FAILURE);
   }

   // cout << "DisplayInFix() before:" << endl;
   // DisplayInFix();

   if (!CheckTokens())
   {
      cout << "Sorry but the input includes tokens that are not accepted" << endl;
      exit(EXIT_FAILURE);
   }

   MakeValueTbl();

   Parse();

   // cout << "DisplayInFix() after:" << endl;
   // DisplayInFix();
}

Calc::~Calc()
{
   stk->~List();
}

bool Calc::CheckTokens()
{
   int i = 0;
   while (inFix[i] != '\0')
   {
      bool returnVal = false;
      if (isdigit(inFix[i]))
         returnVal = true;
      if ((inFix[i] == '*') || (inFix[i] == '/'))
         returnVal = true;
      if ((inFix[i] == '+') || (inFix[i] == '-'))
         returnVal = true;
      if ((inFix[i] == ')') || (inFix[i] == '('))
         returnVal = true;
      if (!returnVal)
         return false;
      i++;
   }
   return true;
}

void Calc::MakeValueTbl()
{
   valueTbl = new int[26];
   for (int i = 0; i < 26; i++)
   {
      valueTbl[i] = 0;
   }
   valueIdx = 0;
}

void Calc::Parse()
{
   int len = strlen(inFix);
   char *tmp = new char[len + 1];

   int inFixIdx = 0;
   int tmpIdx = 0;

   while (inFix[inFixIdx] != '\0')
   {
      if (isdigit(inFix[inFixIdx]))
      {
         int startIdx = inFixIdx;
         int endIdx = FindLast(startIdx);
         int num = 0;
         while (startIdx < endIdx)
         {
            num += ((inFix[startIdx]) - '0') * pow(10, endIdx - startIdx);
            startIdx++;
         }
         num /= 10;
         //cout << num << endl;

         valueTbl[valueIdx] = num;
         char valueChar = valueIdx + 65;
         valueIdx++;
         tmp[tmpIdx] = valueChar;

         inFixIdx += (endIdx - inFixIdx);
         tmpIdx++;
      }
      else
      {
         tmp[tmpIdx] = inFix[inFixIdx];
         inFixIdx++;
         tmpIdx++;
      }
   }
   //valueIdx; // after the while loop it is 1 over the next value because of how it itterates

   // inFix = (10+(3*20)) (or something like that)
   // tmp = (A+(B*C)) (or something like that)
   // valueTbl = 10, 3, 20

   delete[] inFix;
   inFix = tmp;
   tmp = NULL;
}

bool Calc::CheckParens()
{
   Stack tmp;
   if (inFix[0] != '(')
   {
      return false;
   }
   int i = 0;
   char ch = inFix[i];
   bool bal = true;
   int amount = 0;
   while (bal && (inFix[i] != '\0'))
   {
      if (ch == '(')
      {
         tmp.Push(ch);
         if (amount == 0)
         {
            bal = true;
         }
      }
      else if (ch == ')')
         if (!tmp.IsEmpty())
            tmp.Pop();
         else
            bal = false;
      i++;
      ch = inFix[i];
   }
   if (bal && tmp.IsEmpty())
      return true;
   else
      return false;
}

void Calc::DisplayInFix()
{
   cout << "inFix is " << inFix << endl;
}

int Calc::FindLast(int cur)
{
   int pos = cur;
   while (inFix[pos] >= '0' && inFix[pos] <= '9')
      pos++;
   return pos;
}