#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

// write file
void Write_To_File(string fileName, string content);

// divide content into multiple sub-contents
vector<string> Divided_Content(string content, int count_f);

// 
int Create_Name_File(string fileName, int num);

// divide file
void Divided(string fileName,int count_f);

// read file
string Read_From_File(string filename);

// merge file
void Join(vector<string> fileName, int count_f);
