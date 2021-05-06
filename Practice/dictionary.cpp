#include <array>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <regex>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void openFile(ifstream &inputFile);
bool checkWord(string word, regex r);

int main()
{
   regex r{"[gkmqvwxz]"};

   ifstream inputFile;
   openFile(inputFile); // Opens the file

   vector<string> words;

   while (!inputFile.eof())
   { // Starts the loop to read in the files
      string word = "";
      getline(inputFile, word);
      words.push_back(word);
   }

   string longestWord = "";

   for (int i = 0; i < words.size(); i++)
   {
      if (checkWord(words.at(i), r))
      {
         if (words.at(i).length() >= longestWord.length())
         {
            longestWord = words.at(i);
         }
      }
   }
   cout << longestWord << endl;
}

void openFile(ifstream &inputFile)
{
   inputFile.open("english3.txt"); //opens the file
   if (inputFile.is_open())
   { // checks if the file is open
      cout << "successfully opened input file" << endl;
   }
   else
   {
      cout << "failed to open input file" << endl;
      exit(-1);
   }
}

bool checkWord(string word, regex r)
{
   for (int i = 0; i < word.length(); i++)
   {

      if (regex_search(word, r))
      {
         return false;
      }
   }
   return true;
}