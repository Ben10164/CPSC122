#include "benVector.cpp"

int main(int argc, char *argv[])
{
   int size = atoi(argv[1]);

   benVector hitest;

   cout << "Demonstration of createArray(" << size << ");" << endl;
   hitest.createArray(size);
   //hitest.display();
   cout << "Size of array is " << hitest.getSize() << endl;

   cout << "Demonstration of insert(" << (size - 1) << ", 10);" << endl;
   hitest.insert(size - 1, 10);
   //hitest.display();
   cout << "Size of array is " << hitest.getSize() << endl;

   cout << "Demonstration of pushBack(20);" << endl;
   hitest.pushBack(20);
   //hitest.display();
   cout << "Size of array is " << hitest.getSize() << endl;

   cout << "Demonstration of shuffle();" << endl;
   hitest.shuffle();
   //hitest.display();
   //cout << "Size of array is " << hitest.getSize() << endl;

   cout << "Demonstration of popBack(2);" << endl;
   hitest.popBack(2);
   //hitest.display();
   cout << "Size of array is " << hitest.getSize() << endl;

   cout << "Demonstration of at(0);" << endl;
   cout << hitest.at(0) << endl;
   //hitest.display();
   cout << "Size of array is " << hitest.getSize() << endl;
}