/*
Name: Ben Puryear
Class: CPSC 122 Section 1
Date Submitted: 2/19/2021 (completed 2/18/2021)
Assignment: Project 7
Description: Uses the transposition Cipher to either encrypt, decrypt, or generate a key for said encryption and decryption
Notes: 
cmd used to test "g++ project7.cpp && ./a.out 0 key.out && ./a.out 1 key.out input.in encrypt.out && ./a.out 2 key.out encrypt.out decrypt.out"
https://en.cppreference.com/w/cpp/language/ascii for a full ascii chart
https://en.cppreference.com/w/cpp/string/basic_string/stol for stoi()
https://docs.microsoft.com/en-us/cpp/cpp/program-termination?view=msvc-160 help with EXIT function
https://stackoverflow.com/questions/5343173/returning-to-beginning-of-file-after-getline 
*/

#include <iostream>
#include <fstream>
#include <cstdlib> // necessary for the constant EXIT_FAILURE
#include <string>
#include <time.h> // srand(time(NULL))

using namespace std;

void keyGen(string keyFile);
void generateKey(int nums[]);
void fileOpen(fstream &file, string name, char mode);
void copyArray(int og[], int copy[]);
void generateDecryptKey(int nums[], int copy[]);
int findIndexOf(int num, int encrypt[]);
void mode0(char *argv[], fstream &keyFile);
void mode1(fstream &keyFileStream, fstream &inFileStream, fstream &outFileStream);
void mode2(fstream &keyFileStream, fstream &inFileStream, fstream &outFileStream);
void wrongInput();
char transform(char ch, int encDec[]);
void getKeyInfo(int encrypt[], int decrypt[], fstream &keyFileStream);
void fileControl(string keyFile, string inFile, string outFile, int mode);

const int alpha = 26;

int main(int argc, char *argv[])
{
   srand(time(NULL));

   fstream keyFile, inFile, outFile;
   string keyFileString;
   string inFileString;
   string outFileString;
   if (argc == 1) // no cmd line inputs
      wrongInput();
   int mode = stoi(argv[1]);
   if (mode == 0)
      mode0(argv, keyFile); // keygen
   else
   {
      keyFileString = argv[2];
      inFileString = argv[3];
      outFileString = argv[4];
      fileControl(keyFileString, inFileString, outFileString, mode);
   }
}

/*
Description: Opens key file for writing.  Generates and stores encrypt and decrypt keys in the key file.   This can be stored any way that you like as long as two arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 
*/
void keyGen(string keyFile)
{
   fstream keyFileStream;
   fileOpen(keyFileStream, keyFile, 'w');

   int encrypt[alpha], decrypt[alpha];
   generateKey(encrypt);
   generateDecryptKey(encrypt, decrypt);

   for (int i = 0; i < alpha; i++)
      keyFileStream << encrypt[i] << endl;
   keyFileStream << endl;
   for (int i = 0; i < alpha; i++)
      keyFileStream << decrypt[i] << endl;
}

/*
Description: Copies an array from one to the other
Input: original array, and the array to be coppied to
Returns: void (2 copies of the original array)
*/
void copyArray(int og[], int copy[])
{
   for (int i = 0; i < alpha; i++)
      copy[i] = og[i];
}

/*
Description: Generates the decryption key
Input: encryption array, as well as a blank array titled decrypt
Returns: void (returns decrypt[] as the decryption array)
*/
void generateDecryptKey(int encrypt[], int decrypt[])
{
   copyArray(encrypt, decrypt);
   int tempArray[alpha];
   for (int i = 0; i < alpha; i++)
      decrypt[i] = findIndexOf(i, encrypt);
}

/*
Description: Finds the index of a given number in an array
Input: number to find, array to look in
Returns: index where the array is the number searched for
*/
int findIndexOf(int num, int encrypt[])
{
   for (int i = 0; i < alpha; i++)
      if (encrypt[i] == num)
         return i;
   return -1;
}

/*
Description: Generates the encryption key
Input: array nums to be changed into the new encryption array
Returns: void (an array that contains the encryption pattern)
*/
void generateKey(int nums[])
{
   bool validate[alpha];
   for (int i = 0; i < alpha; i++)
      validate[i] = false; // sets everything to false

   for (int i = 0; i < alpha; i++)
   {
      while (true)
      {
         int random = rand() % alpha;
         if (validate[random] == false)
         {
            nums[i] = random;
            validate[random] = true;
            break;
         }
      }
   }
}

/*
Description: function opens a file
Input: file stream object reference, name of the file, mode of open
Output: input file name is opened. 
*/
void fileOpen(fstream &file, string name, char mode) // CODE BY DEPALMA FOR PROJECT 5
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
Description: a bunch of cout statements that display if you have no cmd arguments or too many
Returns: void (cout)
*/
void wrongInput()
{
   cout << "Please review your cmd line inputs." << endl;
   cout << "There are three possibilities for the cmd usage: " << endl
        << "Generate the key : ./a.out 0 keyFile.out " << endl
        << "Encrypt plaintext :./ a.out 1 keyFile inFile.out outFile.out " << endl
        << "Decrypt ciphertext :./ a.out 2 keyFile.out inFile.out outFile.out " << endl;
   exit(EXIT_FAILURE);
}

/*
Description: puts the value of the encryption and decryption key into their respective arrays
Input: encrypt array, decrypt array, and keyFile stream
Returns: void (writes the keys to their arrays)
*/
void getKeyInfo(int encrypt[], int decrypt[], fstream &keyFileStream)
{
   for (int i = 0; i < alpha; i++)
   {
      string temp = " f";
      getline(keyFileStream, temp);
      int tempInt = stoi(temp);
      encrypt[i] = tempInt;
   }
   string trash = "";
   getline(keyFileStream, trash);
   for (int i = 0; i < alpha; i++)
   {
      int temp;
      keyFileStream >> temp;
      decrypt[i] = temp;
   }
}

/*
Description: Processes files, invokes function to encrypt/decrypt characters
inside the SUB-FUNCTIONS, this function:
1. Reads key file. Constructs a two arrays, one for encryption, one for decryption.
2. Closes key file
2. Opens the character input file.  This could be plain text or cipher text.
3. Opens the character output file  This could be plain text or cipher text.
4. Reads the input file a character at a time.  Passes transform (see below) the character to be encrypted/decrypted and a reference to  the encrypt or decrypt array, depending on the mode.
5.  Writes a character (encrypted/decrypted/passed over) to the output file.
6. Close the input file and output file
Output: writes a character to the output file
*/
void fileControl(string keyFile, string inFile, string outFile, int mode)
{
   fstream keyFileStream, inFileStream, outFileStream;
   int encrypt[alpha];
   int decrypt[alpha];
   fileOpen(keyFileStream, keyFile, 'r');
   fileOpen(inFileStream, inFile, 'r');
   fileOpen(outFileStream, outFile, 'w');
   if (mode == 1)
      mode1(keyFileStream, inFileStream, outFileStream); // encrypt
   else if (mode == 2)
      mode2(keyFileStream, inFileStream, outFileStream); // decrypt
   else
      wrongInput();
   keyFileStream.close();
   inFileStream.close();
   outFileStream.close();
}

/*
Description: Does "mode0" which is doing the keyGen functions and all its prerequisites 
Input: *argv[] to get the cmd line inputs, &keyFile to be write the key's into 
Returns: void (writes keys into keyFile)
*/
void mode0(char *argv[], fstream &keyFile)
{
   string keyFileString = argv[2];
   keyGen(keyFileString);
   cout << "Successfully finished mode 0 (key generation)" << endl;
}

/*
Description: does mode1, encryption
Input: &keyFileStream to read the key, inFileStream to get the input chars, and outFileStream to output the encrypted chars
Returns: Void (writes the encrypted contents of inFile to outFile)
*/
void mode1(fstream &keyFileStream, fstream &inFileStream, fstream &outFileStream)
{
   // Ecrypt
   int keyE[alpha], keyD[alpha];
   getKeyInfo(keyE, keyD, keyFileStream);
   while (inFileStream.peek() != EOF)
   {
      char ch = inFileStream.get();
      if (isalpha(ch))
         ch = toupper(ch);
      char encryptChar = transform(ch, keyE);
      encryptChar = toupper(encryptChar);
      outFileStream << encryptChar;
   }
   cout << "Finished mode 1 (encryption)" << endl;
}

/*
Description: does mode2, decryption
Input: &keyFileStream to read the key, inFile Stream to get the encrypted chars, and outFileStream to output the decrypted chars
Returns: void (writes the decrypted contents of inFile to outFile)
*/
void mode2(fstream &keyFileStream, fstream &inFileStream, fstream &outFileStream)
{
   int keyE[alpha], keyD[alpha];
   getKeyInfo(keyE, keyD, keyFileStream);
   while (inFileStream.peek() != EOF)
   {
      char ch = inFileStream.get();
      if (isalpha(ch))
         ch = toupper(ch);
      char encryptChar = transform(ch, keyD);
      encryptChar = toupper(encryptChar);
      outFileStream << encryptChar;
   }
   cout << "Finished mode 2 (decryption)" << endl;
}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int encDec[])
{
   if (ch == ' ')
      return ch;
   char temp = 65 + findIndexOf(((int)ch - 65), encDec);
   return temp;
}