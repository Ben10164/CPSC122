#include "testpadFunctions.cpp"

int main(int argc, char *argv[])
{
   int amt = 5;
   if (argc > 1)
      amt = stoi(argv[1]);
   //bogosort(amt);
   int test[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
   cout << amt << " is located at " << binSearch(test, amt, 0, (sizeof(test) / sizeof(test[0]))) << endl;

   cout << fibr(amt) << endl;
}