#include <iostream>
#include <math.h>
using namespace std;

#include "calc.h"

void thing(string input);

int main(int argc, char *argv[])
{
   Calc *C = new Calc(argv[1]);

   //thing("((10+20)*40)");

   delete C;
   return 0;
}

void thing(string input)
{
   List numbers;
   string test = input;
   int i = 0;
   while (i < test.length())
   {
      if (isupper(test.at(i)))
      {
         cout << test.at(i);
         i++;
      }
      else if (isdigit(test.at(i)))
      {
         List num;
         int k = 0;
         while (true)
         {
            if (isdigit(test.at(i + k)))
            {
               int number = test.at(i + k) - '0';
               //cout << number << endl;
               num.PutItemH(number);
               k++;
            }
            else
            {
               break;
            }
         }
         int amount = num.GetLength();
         i += amount;
         int finalNum = 0;
         int templen = num.GetLength();
         for (int i = 0; i < templen; i++)
         {
            int tempNum = num.GetItemH();
            int tempNum2 = tempNum * pow(10, i);
            finalNum += tempNum2;
            num.DeleteItemH();
         }
         numbers.PutItemH(finalNum);
         cout << finalNum;
         // cout << test.at(i);
         // i++;
      }
      else if ((test.at(i) == '/') || (test.at(i) == '*') || (test.at(i) == '+') || (test.at(i) == '-'))
      {
         cout << test.at(i);
         i++;
      }
      else if ((test.at(i) == '(') || (test.at(i) == ')'))
      {
         cout << test.at(i);
         i++;
      }
      else
      {
         cout << " " << endl;
         i++;
      }
   }
   cout << "asdh";
   cout << endl;

   int a = 0, b = 0, c = 0;
   if (numbers.GetLength() == 2)
   {
      b = numbers.GetItemH();
      numbers.DeleteItemH();
      a = numbers.GetItemH();
      numbers.DeleteItemH();
   }
   else if (numbers.GetLength() == 1)
   {
      a = numbers.GetItemH();
      numbers.DeleteItemH();
   }
   else if (numbers.GetLength() == 3)
   {
      c = numbers.GetItemH();
      numbers.DeleteItemH();
      b = numbers.GetItemH();
      numbers.DeleteItemH();
      a = numbers.GetItemH();
      numbers.DeleteItemH();
   }

   cout << "A was " << a << endl;
   cout << "B was " << b << endl;
   cout << "C was " << c << endl;
}
