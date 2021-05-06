#include <iostream>
#include <cstdlib>
using namespace std;

int *getData(int);

int main(int argc, char *argv[])
{
   int size = atoi(argv[1]);

   int *test = getData(size);

   for (int i = 0; i < size; i++)
      cout << test[i] << endl;
}

//add 10 to each of the parameters
int *getData(int size)
{
   int *arrayStuff = new int[size];

   for (int i = 0; i < size; i++)
      arrayStuff[i] = i;
   return arrayStuff;
}
