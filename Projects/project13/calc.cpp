/*
Name: Ben Puryear
Class: CPSC 122, Section 1
Date Submitted: 4/14/2021
Assignment: Project 13
Description: Part 2 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/

#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>
#include <math.h> // NEEDED FOR POW()

//Write functions in this order.  Constructor and destructor will be built as the
//functions it invokes are written

Calc::Calc(char *argvIn)
{
   stk = new Stack;

   inFix = new char[strlen(argvIn) + 1];
   postFix = new char[strlen(argvIn) + 1];
   strcpy(inFix, argvIn);

   if (!CheckTokens())
   {
      cout << "Sorry but the input includes tokens that are not accepted" << endl;
      exit(EXIT_FAILURE);
   }

   if (!CheckParens())
   {
      cout << "Sorry but the parens are not balanced" << endl;
      exit(EXIT_FAILURE);
   }

   MakeValueTbl();
   Parse();
   InFixToPostFix();
}

Calc::~Calc()
{
   delete[] inFix;
   delete[] postFix;
   delete[] valueTbl;
   while (stk->GetLength() != 0)
   {
      stk->Pop();
   }
   stk = NULL;
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
      if (isdigit(inFix[inFixIdx])) // Okay cool its a number
      {
         NumberInFixConversion(inFixIdx, tmp, tmpIdx); // This converts a section of numbers to a single number
      }
      else // Uh oh it isnt a number
      {
         tmp[tmpIdx] = inFix[inFixIdx];
         inFixIdx++;
         tmpIdx++;
      }
   }
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
      CheckIfParenValid(ch, tmp, amount, bal);
      i++;
      ch = inFix[i];
   }
   if (bal && tmp.IsEmpty())
   {
      return true;
   }
   else
   {
      return false;
   }
}

void Calc::DisplayInFix()
{
   cout << "inFix is " << inFix << endl;
}

void Calc::InFixToPostFix()
{
   int len = strlen(inFix);
   char *tmp = new char[len + 100]; // This is 100 so no matter what it is larger than the current inFix.
                                    // This  was a problem during debuggin

   for (int i = 0; inFix[i] != '\0'; i++)
   {
      char temp = inFix[i];
      ConversionToPostFix(tmp, temp);
   }

   delete[] postFix;
   postFix = tmp;
   tmp = NULL;
}

void Calc::DisplayPostFix()
{
   cout << "postFix is " << postFix << endl;
}

int Calc::Evaluate()
{
   Stack test;
   int i = 0;
   char ch = postFix[i];
   int result;
   while (postFix[i] != '\0')
   {
      if (ch >= 65 && ch <= (65 + 26))
         test.Push(ch);
      else
      {
         int op2 = valueTbl[test.Peek() - 65];
         test.Pop();
         int op1 = valueTbl[test.Peek() - 65];
         test.Pop();

         DoOperation(ch, result, op1, op2);

         valueTbl[valueIdx] = result;
         char pushVal = valueIdx + 65;
         test.Push(pushVal);
         valueIdx++;
      }
      i++;
      ch = postFix[i];
   }
   return result;
}

int Calc::FindLast(int cur)
{
   int pos = cur;
   while (inFix[pos] >= '0' && inFix[pos] <= '9')
      pos++;
   return pos;
}

void Calc::CheckIfParenValid(char ch, Stack &tmp, int &amount, bool &bal)
{
   if (ch == '(')
   {
      tmp.Push(ch);
      if (amount == 0)
      {
         bal = true;
      }
      amount++;
   }
   else if (ch == ')')
   {
      if (!tmp.IsEmpty())
      {
         tmp.Pop();
      }
      else
      {
         bal = false;
      }
      amount++;
   }
}

void Calc::NumberInFixConversion(int &inFixIdx, char *&tmp, int &tmpIdx)
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

void Calc::DoOperation(char ch, int &result, int op1, int op2)
{
   if (ch == '+')
      result = op1 + op2;
   if (ch == '-')
      result = op1 - op2;
   if (ch == '*')
      result = op1 * op2;
   if (ch == '/')
      result = op1 / op2;
}

void Calc::ConversionToPostFix(char *tmp, char temp)
{
   if (temp >= 65 && temp <= (65 + 26))
      strncat(tmp, &temp, 1);
   if (temp == '(')
      stk->Push(temp);
   if ((temp == '*') || (temp == '/') || (temp == '+') || (temp == '-'))
      stk->Push(temp);
   if (temp == ')')
   {
      while (stk->Peek() != '(')
      {
         char temp2 = stk->Peek();
         strncat(tmp, &temp2, 1);
         stk->Pop();
      }
      stk->Pop();
   }
}