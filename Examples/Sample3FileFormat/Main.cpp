#include "area.cpp"

int main()
{
   double input;
   cout << "Please enter a number (double or int): ";
   cin >> input;
   cout << calculateArea(input) << endl;
   return 0;
}