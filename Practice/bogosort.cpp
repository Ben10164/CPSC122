#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool inOrder(vector<int> nums);
void shuffle(vector<int> &a, int &tries);

int main(int argc, char *argv[])
{
   ofstream outputFile;
   vector<int> nums;
   int k = 0, tries = 1, amount = atoi(argv[1]);
   srand(time(NULL));
   outputFile.open("outputBogo.out");
   for (int q = 1; q <= amount; q++)
   {
      nums.clear();
      tries = 1;
      for (int i = 1; i <= q; i++)
         nums.push_back(i);
      shuffle(nums, k);
      while (!inOrder(nums))
         shuffle(nums, tries);
      outputFile << "For q = " << q << " it took " << tries << " tries" << endl;
   }
   outputFile.close();
}

bool inOrder(vector<int> nums)
{
   for (int i = 0; i < nums.size() - 1; i++)
      if (nums[i] > nums[i + 1])
         return false;
   return true;
}

void shuffle(vector<int> &a, int &tries)
{
   for (int i = 0; i < a.size(); i++)
      swap(a[i], a[rand() % a.size()]);
   tries++;
}