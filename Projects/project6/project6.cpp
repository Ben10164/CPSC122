/*
Name: Ben Puryear
Class: CPSC 122 Section 1
Date Submitted: 2/12/2021 (completed 2/11/2021)
Assignment: Project 6
Description: Uses the Affine Cipher to either encrypt, decrypt, or generate a key for said encryption and decryption
Notes: 
https://en.cppreference.com/w/cpp/language/ascii for a full ascii chart
https://en.cppreference.com/w/cpp/string/basic_string/stol for stoi()
https://docs.microsoft.com/en-us/cpp/cpp/program-termination?view=msvc-160 help with EXIT function
*/
#include <iostream>
#include <fstream>
#include <cstdlib> // necessary for the constant EXIT_FAILURE
#include <string>
#include <time.h> // srand(time(NULL))

using namespace std;

char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int MI[]);
void fileControl(string keyFile, string inFile, string outFile, int mode);
void mode0(char *argv[], fstream &keyFile);
void mode1(fstream &keyFileStream, fstream &inFileStream, fstream &outFileStream);
void mode2(fstream &keyFileStream, fstream &inFileStream, fstream &outFileStream);
void keyGen(string keyFile);
int findAInverse(int a);
void generateInverseArray(int nums[]);
void fileOpen(fstream &file, string name, char mode);
void wrongInput();

int main(int argc, char *argv[])
{
   fstream keyFile, inFile, outFile;
   if (argc == 1) // no cmd line inputs
      wrongInput();
   int mode = stoi(argv[1]);
   if (mode == 0) // keygen
      mode0(argv, keyFile);
   else
   {
      string keyFileString = argv[2];
      string inFileString = argv[3];
      string outFileString = argv[4];
      fileControl(keyFileString, inFileString, outFileString, mode);
   }
}

/*
Description: Encrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values
Returns: encrypted version of ch
*/

char encrypt(char ch, int alpha, int beta)
{
   char chE = ' ';
   if (ch != ' ')
      chE = chE + ((((alpha * (ch - 'A')) + beta) % 26) + 'A');
   return chE;
}

/*
Description: Decrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values. Dictionary of multiplicative inverse values mod 26
Returns: decrypted version of input
*/
char decrypt(char ch, int alpha, int beta, int MI[])
{
   char chD = ' ';
   if (ch != ' ')
      chD = chD + (((MI[alpha] * ((ch + 'A' - beta)) % 26)) + 'A');
   return chD;
}

/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl(string keyFile, string inFile, string outFile, int mode)
{
   fstream keyFileStream, inFileStream, outFileStream;
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
   cout << "Successfully finished mode 0 (Key generation)" << endl;
}

/*
Description: does mode1, encryption
Input: &keyFileStream to read the key, inFileStream to get the input chars, and outFileStream to output the encrypted chars
Returns: Void (writes the encrypted contents of inFile to outFile)
*/
void mode1(fstream &keyFileStream, fstream &inFileStream, fstream &outFileStream)
{
   int alpha, beta;
   string alphaString, betaString;

   getline(keyFileStream, alphaString);
   alpha = stoi(alphaString);
   getline(keyFileStream, betaString);
   beta = stoi(betaString);

   while (inFileStream.peek() != EOF)
   {
      char ch = inFileStream.get();
      if (isalpha(ch))
         ch = toupper(ch);
      char encryptChar = encrypt(ch, alpha, beta);
      encryptChar = toupper(encryptChar);
      outFileStream << encryptChar;
   }
   cout << "Finished mode 1, encryption" << endl;
}

/*
Description: does mode2, decryption
Input: &keyFileStream to read the key, inFile Stream to get the encrypted chars, and outFileStream to output the decrypted chars
Returns: void (writes the decrypted contents of inFile to outFile)
*/
void mode2(fstream &keyFileStream, fstream &inFileStream, fstream &outFileStream)
{
   int alpha, beta;
   string alphaString, betaString;
   int MI[26];
   generateInverseArray(MI);

   getline(keyFileStream, alphaString);
   alpha = stoi(alphaString);
   getline(keyFileStream, betaString);
   beta = stoi(betaString);

   while (inFileStream.peek() != EOF)
   {
      char ch = inFileStream.get();
      if (isalpha(ch))
         ch = toupper(ch);
      char decryptChar;
      decryptChar = decrypt(ch, alpha, beta, MI);
      decryptChar = toupper(decryptChar);
      outFileStream << decryptChar;
   }
   cout << "Finished mode 2, decryption" << endl;
}

/*
Description: Randomly generates and stores alpha and beta values.
The alpha value is randomly drawn from the the set:  {1,3,5,7,11, 17,19,25}
The beta value is randomly drawn from the range: [1..25] 
InputL string keyFile (the name of the keyFile file) 
Output: alpha and beta values on subsequent lines of keyFile
*/
void keyGen(string keyFile)
{
   fstream keyFileStream;
   fileOpen(keyFileStream, keyFile, 'w');
   srand(time(0));
   int alpha, beta;
   int alphaSet[] = {1, 3, 5, 7, 11, 17, 19, 25}; // 8
   int betaSet[25];                               // 25
   for (int i = 0; i < 25; i++)
      betaSet[i] = i + 1;
   int alphaRand = rand() % 7 + 1;
   alpha = alphaSet[alphaRand];
   int betaRand = rand() % 24 + 1;
   beta = betaSet[betaRand];
   keyFileStream << alpha << endl
                 << beta << endl;
}

/*
Description: finds the inverse of an integer
Input: integer a
Returns: the inverse of a
*/
int findAInverse(int a)
{
   int aInv = 0;
   for (int i = 0; i < 26; i++)
      if ((a * i) % 26 == 1)
         return i;
   return 0; // fail
}

/*
Description: generates an inverse array
Input: integer array nums 
Returns: a changed integer array nums that has the integer inverses from 0 - 25 in their respective indexes
*/
void generateInverseArray(int nums[])
{
   for (int i = 0; i < 26; i++)
      nums[i] = findAInverse(i);
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