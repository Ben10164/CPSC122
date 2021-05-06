#include <iostream>
#include "4-ListD.cpp"

using namespace std;

int main(int argc, char *argv[])
{
   int sortVal = stoi(argv[1]);
   ListD<int> *lst = new ListD<int>;


   for (int i = 1; i < sortVal; i++)
   {
      lst->Insert((rand() % sortVal + 1), i + 1 - sortVal);
   }

   //lst->PrintForward();
   cout << "Currently sorting" << endl;
   lst->Sort();
   lst->PrintForward();

   return 0;
}
