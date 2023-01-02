#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include"SHA1.h"
//#define Out_FileName "output.txt"
using namespace std;

void Encrypt(char* plaintext, int len, char* key);
void Decrypt(char* ciphertext, int len, char* key);
char* ReadFile(string In_FileName, int& fileSize);
void WriteFile(string Out_FileName, char* content, int fileSize);
void File_ENCRYPT(string In_FileName, char* key);
void File_DECRYPT(string In_FileName, char* key);

