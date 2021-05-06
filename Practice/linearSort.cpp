#include <iostream>
#include <vector>
using namespace std;
bool inOrder(vector<int> nums);
int main(int argc, char *argv[])
{
   vector<int> nums;
   int k = 0, tries = 1;
   if (argc < 2)
   {
      cout << "please add a cmd argument" << endl;
      return 0;
   }
   int amount = atoi(argv[1]);
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