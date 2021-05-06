/*
Name: Ben Puryear
Class: CPSC 122 Section 1
Date Submitted: 2/5/2021
Assignment: Project 5
Description: Uses the Caesar cipher by using 4 files, only 1 needs to be provided, the PTfile.out, and generates the PTEfile.out, CTfile.out and keyFile.out
Notes: 
https://en.cppreference.com/w/cpp/language/ascii for a full ascii chart
https://en.cppreference.com/w/cpp/io/basic_fstream for understanding fstream and &fstream
https://en.cppreference.com/w/cpp/string/basic_string/stol for stoi()
*/

/*
There are three possibilities for the cmd usage:
Generate the key: ./a.out 0 keyFile 
Encrypt plaintext: ./a.out 1 keyFile PTfile CTfile
Decrypt ciphertext: ./a.out 2 keyFile CTfile, PTEfile
All: g++ project5.cpp && ./a.out 0 keyFile.out && ./a.out 1 keyFile.out PTfile.out CTfile.out && ./a.out 2 keyFile.out CTfile.out PTEfile.out
*/

#include <iostream>
#include <fstream>
#include <cstdlib> // necessary for the constant EXIT_FAILURE
#include <string>
#include <time.h> // srand(time(NULL))

using namespace std;

//Function prototypes
void mode0(char *argv[], fstream &keyFile);
void mode1(char *argv[], fstream &keyFile, fstream &PTfile, fstream &CTfile);
void mode2(char *argv[], fstream &keyFile, fstream &CTfile, fstream &PTEfile);
void outputKey(fstream &keyFile); // writes key to file
int keyGen();                     // generates key (this is used inside of outputKey)
char encrypt(char ch, int key);
char decrypt(char ch, int key);
void fileOpen(fstream &file, string name, char mode);
void writeEncryption(char *argv[], fstream &PTfile, fstream &CTfile, int keyInt);  // writes encrypted data to file
void writeDecryption(char *argv[], fstream &CTfile, fstream &PTEfile, int keyInt); // writes decrypted data to file
void wrongInput();                                                                 // function called if the int cmd argument is not 0,1 or 2

int main(int argc, char *argv[])
{
   fstream keyFile, PTfile, CTfile, PTEfile;
   int mode = stoi(argv[1]);
   if (mode == 0) // keygen
      mode0(argv, keyFile);
   else if (mode == 1) // encrypt
      mode1(argv, keyFile, PTfile, CTfile);
   else if (mode == 2) // decrypt
      mode2(argv, keyFile, CTfile, PTEfile);
   else
      wrongInput();
}

/*
Description: uses keyGen, and writes it to the keyFile
Input: argv and the fstream keyFile
Output: Void, but generates a key and writes it to keyFile
*/
void mode0(char *argv[], fstream &keyFile)
{
   fileOpen(keyFile, argv[2], 'w');
   outputKey(keyFile);
   cout << "Successfully finished mode 0 (Key generation)" << endl;
}

/*
Description: generates the cipher text from PTfile and writes it to CTfile
Input: argv and the fstreams keyFile, PTfile, and CTfile
Output: Void, but encrypts PTfile and writes it to CTfile
*/
void mode1(char *argv[], fstream &keyFile, fstream &PTfile, fstream &CTfile)
{
   string key;
   fileOpen(keyFile, argv[2], 'r');
   getline(keyFile, key);
   int keyInt = stoi(key);
   writeEncryption(argv, PTfile, CTfile, keyInt);
   cout << "Successfully finished mode 1 (Encryption)" << endl;
}

/*
Description: decrypts the cipher text in CTfile and outputs it to PTEfile
Input: argv and the fstreams keyFile, CTfile, and PTEfile
Output: Void, but decrypts CTfile and writes it to PTEfile
*/
void mode2(char *argv[], fstream &keyFile, fstream &CTfile, fstream &PTEfile)
{
   string key;
   fileOpen(keyFile, argv[2], 'r');
   getline(keyFile, key);
   int keyInt = stoi(key);
   writeDecryption(argv, CTfile, PTEfile, keyInt);
   cout << "Successfully finished mode 2 (Decryption)" << endl;
}

/*
Description: Randomly generates an integer in the range: [1..25]
Input: reference to keyFile
Output: writes a randomly generated integer in the range [1..25] to keyFile 
*/
void outputKey(fstream &keyFile)
{
   int num = keyGen();
   keyFile << num << endl;
}

/*
Description: generates the random number used in outputKey
Input: nothing
Output: random int
*/
int keyGen()
{
   srand(time(0));
   int num = rand() % 25 + 1;
   return num;
}

/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int key)
{
   char newCh;
   if (ch >= 'A' && ch <= 'Z')
   {
      newCh = ch + key;
      if (newCh > 'Z')
         newCh = newCh - 'Z' + 'A' - 1;
   }
   if (ch == ' ')
      return ' ';
   return newCh;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt(char ch, int key)
{
   char newCh;
   if (ch >= 'A' && ch <= 'Z')
   {
      newCh = ch - key;
      if (newCh < 'A')
         newCh = newCh + 'Z' - 'A' + 1;
   }
   if (ch == ' ')
      return ' ';
   return newCh;
}

/*
Description: function opens a file
Input: file stream object reference, name of the file, mode of open
Output: input file name is opened. 
*/
void fileOpen(fstream &file, string name, char mode)
{
   string fileType;
   if (mode == 'r')
      fileType = "input";
   if (mode == 'w')
      fileType = "output";
   if (mode == 'r')
      file.open(name, ios::in); //available thorugh fstream
   if (mode == 'w')
      file.open(name, ios::out); //available through fstream;
   if (file.fail())              //error condition
   {
      cout << "Error opening " << fileType << " file" << endl;
      cout << "Correct usage is ./a.out int num (mode) [string keyFile.out] [string PTfile.out] [string CTfile.out] [string PTEfile.out]";
      exit(EXIT_FAILURE);
   }
   cout << "Opened " << name << endl;
}

/*
Description: Encrypts all the characters of the PTfile and writes them to the CTfile
Input: argv, PTfile, CTfile, and the keyInt
Returns: void
*/
void writeEncryption(char *argv[], fstream &PTfile, fstream &CTfile, int keyInt)
{
   char ch;
   fileOpen(PTfile, argv[3], 'r');
   fileOpen(CTfile, argv[4], 'w');
   while (PTfile.peek() != EOF)
   {
      ch = PTfile.get();
      if (isalpha(ch))
         ch = toupper(ch);
      char encryptChar = encrypt(ch, keyInt);
      CTfile << encryptChar;
   }
}

/*
Description: Decrypts all the characters of the CTfile and writes them to the PTEfile
Input: argv, CTfile, PTEfile, and keyInt
Returns: void
*/
void writeDecryption(char *argv[], fstream &CTfile, fstream &PTEfile, int keyInt)
{
   fileOpen(CTfile, argv[3], 'r');
   fileOpen(PTEfile, argv[4], 'w');
   char ch;
   while (CTfile.peek() != EOF)
   {
      ch = CTfile.get();
      if (isalpha(ch))
         ch = toupper(ch);
      char decryptChar = decrypt(ch, keyInt);
      PTEfile << decryptChar;
   }
}

/*
Description: To make int main look nicer, this is what happens when the integer input from the cmd line is not 0, 1, or 2
Input: nothing
Returns: void
*/
void wrongInput()
{
   cout << "Please review your cmd line inputs." << endl;
   cout << "There are three possibilities for the cmd usage: " << endl
        << "Generate the key : ./a.out 0 keyFile " << endl
        << "Encrypt plaintext :./ a.out 1 keyFile PTfile CTfile " << endl
        << "Decrypt ciphertext :./ a.out 2 keyFile CTfile, PTEfile " << endl;
}