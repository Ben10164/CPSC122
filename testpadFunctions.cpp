#include <cstdlib>
#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

const int R = 5;
const int C = 2;

int fact(int n);
int factv2(int n);
bool isPrime(int num);
bool isPrimeVector(int num, vector<int> primes);
void displayVector(vector<int> primes, int amount);
void calculatePrimes(int amount);
void linearSort(int amount);
bool inOrder(vector<int> nums);
int *getData(int size);
void load(int **ex);
void dynamicArray(int size);
void display(int **ex);
void dynamicArray2D();
void bogosort(int amount);
void shuffle(vector<int> &a, int &tries);
void showpq(priority_queue<int> gq);
void prioqmax();
void showpq(priority_queue<int, vector<int>, greater<int>> gq);
void prioqmin();
int gcdI(int m, int n);
int gcdR(int m, int n);
void pr(char *str);
void prR(char *str);
int binSearch(int stuff[], int key, int top, int bottom);
int fibl(int nth);
int fibr(int num);

// Definitions
int fact(int n)
{
   if (n == 0)
   {
      return 1;
   }
   return (n * fact(n - 1));
}
int factv2(int n)
{
   if (n > 0)
   {
      return (n * fact(n - 1));
   }
   return 1;
}
bool isPrime(int num)
{
   for (int i = 3; i <= num / 2; i += 2)
   {
      if (num % i == 0)
      {
         return false;
      }
   }
   return true;
}
bool isPrimeVector(int num, vector<int> primes)
{
   for (long i = 0; primes.at(i) <= sqrt(num); i++)
   {
      if (num % primes.at(i) == 0)
      {
         return false;
      }
   }
   return true;
}
void displayVector(vector<int> primes, int amount)
{
   for (int i = 0; i < amount; i++)
   {
      cout << primes.at(i) << endl;
   }
}
void calculatePrimes(int amount)
{
   vector<int> primes(0);
   primes.push_back(2);
   int amountOfPrimes = 1;
   int num = 3;

   for (int num = 3; amountOfPrimes != amount; num += 2)
   {
      if (isPrimeVector(num, primes))
      {
         primes.push_back(num);
         amountOfPrimes++;
      }
   }
   displayVector(primes, amount);
}
void linearSort(int amount)
{
   vector<int> nums;
   int k = 0, tries = 1;
   srand(time(NULL));
   for (int i = 0; i < amount; i++)
      nums.push_back(rand() % 98 + 1);
   for (int i = 0; i < nums.size(); i++)
      //cout << nums[i] << endl;
      while (!inOrder(nums))
      {
         //cout << "Attempt " << tries << endl;
         for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] > nums[i + 1])
            {
               int temp = nums[i + 1];
               nums[i + 1] = nums[i];
               nums[i] = temp;
            }
         for (int i = 0; i < nums.size(); i++)
            //cout << nums[i] << endl;
            tries++;
      }
   cout << "It took " << tries << " tries" << endl;
}
bool inOrder(vector<int> nums)
{
   for (int i = 0; i < nums.size() - 1; i++)
      if (nums[i] > nums[i + 1])
         return false;
   return true;
}
int *getData(int size)
{
   int *arrayStuff = new int[size];

   for (int i = 0; i < size; i++)
      arrayStuff[i] = i;
   return arrayStuff;
}
void load(int **ex)
{
   for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
         ex[i][j] = i;
}
void dynamicArray(int size)
{
   int *test = getData(size);

   for (int i = 0; i < size; i++)
      cout << test[i] << endl;
}
void display(int **ex)
{
   for (int i = 0; i < R; i++)
   {
      for (int j = 0; j < C; j++)
         cout << ex[i][j] << " ";
      cout << endl;
   }
}
void dynamicArray2D()
{
   int **example = new int *[R]; //declare an array of R pointers to int
   for (int i = 0; i < R; i++)   //R int arrays, each of size C
      example[i] = new int[C];

   load(example);
   display(example);
}
void bogosort(int amount)
{
   vector<int> nums;
   int k = 0, tries = 1;
   srand(time(NULL));
   for (int q = 1; q <= amount; q++)
   {
      nums.clear();
      tries = 1;
      for (int i = 1; i <= q; i++)
         nums.push_back(i);
      shuffle(nums, k);
      while (!inOrder(nums))
         shuffle(nums, tries);
   }
   cout << "It took " << tries << " tries" << endl;
}
void shuffle(vector<int> &a, int &tries)
{
   for (int i = 0; i < a.size(); i++)
      swap(a[i], a[rand() % a.size()]);
   tries++;
}
void showpq(priority_queue<int> gq)
{
   priority_queue<int> g = gq;
   while (!g.empty())
   {
      cout << '\t' << g.top();
      g.pop();
   }
   cout << '\n';
}
void prioqmax()
{
   priority_queue<int> gquiz;
   gquiz.push(10);
   gquiz.push(30);
   gquiz.push(20);
   gquiz.push(5);
   gquiz.push(1);

   cout << "The priority queue gquiz is : ";
   showpq(gquiz);

   cout << "\ngquiz.size() : " << gquiz.size();
   cout << "\ngquiz.top() : " << gquiz.top();

   cout << "\ngquiz.pop() : ";
   gquiz.pop();
   showpq(gquiz);
}
void showpq(priority_queue<int, vector<int>, greater<int>> gq)
{
   priority_queue<int, vector<int>,
                  greater<int>>
       g = gq;
   while (!g.empty())
   {
      cout << '\t' << g.top();
      g.pop();
   }
   cout << '\n';
}
void prioqmin()
{
   priority_queue<int, vector<int>, greater<int>> gquiz;
   gquiz.push(10);
   gquiz.push(30);
   gquiz.push(20);
   gquiz.push(5);
   gquiz.push(1);

   cout << "The priority queue gquiz is : ";
   showpq(gquiz);

   cout << "\ngquiz.size() : " << gquiz.size();
   cout << "\ngquiz.top() : " << gquiz.top();

   cout << "\ngquiz.pop() : ";
   gquiz.pop();
   showpq(gquiz);
}
int gcdI(int m, int n)
{
   int r = m % n;
   while (r > 0)
   {
      m = n;
      n = r;
      r = m % n;
   }
   return n;
}
int gcdR(int m, int n)
{
   if (m % n == 0)
   {
      return n;
   }
   return (gcdR(n, m % n));
}
void pr(char *str)
{
   int i = 0;
   while (str[i] != '\0')
   {
      cout << str[i] << endl;
      i++;
   }
}
void prR(char *str)
{
   if (*str != '\0')
   {
      cout << *str << endl;
      str++;
      prR(str);
   }
}

int binSearch(int stuff[], int key, int top, int bottom)
{
   int middle = int((top + bottom) / 2);
   if (top > bottom)
      return -1;
   if (key > middle)
      return binSearch(stuff, key, (middle + 1), bottom);
   if (key < middle)
      return binSearch(stuff, key, top, (middle - 1));
   if (key == stuff[middle])
      return middle;
   return -1;
}

int fibl(int nth)
{
   if (nth == 0 || nth == 1)
      return nth;

   //0th and 1st Fibonacci number
   int fn_minus_2 = 0;
   int fn_minus_1 = 1;
   int fn = 0;
   while (nth > 1)
   {
      fn = fn_minus_2 + fn_minus_1; //2nd ... nth Fibonacci numbers
      fn_minus_2 = fn_minus_1;      //advance fib-2
      fn_minus_1 = fn;              //advance fib-1
      --nth;
   }
   return fn;
}

int fibr(int num)
{
   if (num < 2)
      return num;
   return (fibr(num - 2) + fibr(num - 1));
}
