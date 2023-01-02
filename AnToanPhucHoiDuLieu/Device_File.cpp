#include "Device_File.h"

// write file
void Write_To_File(string fileName, string content)
{
	fstream file;
	file.open(fileName + ".txt", ios::out);
	file << content;
	file.close();
}

string Read_From_File(string filename)
{
	string content = "";
	ifstream file;

	file.open(filename + ".txt");

	if (file.fail()) {
		cerr << "Error: file not opened." << endl;
		return content;
	}

	string temp;
	while (!file.eof())
	{
		getline(file, temp);
		content += temp;
	}

	file.close();

	return content;
}

//divide content
vector<string> Divided_Content(string content, int count_f)
{
	vector<string> list_content;

	// size of file
	int size = content.length() / (count_f);

	int k = 0;
	// get n-1 data
	for (int i = 0; i < count_f - 1; i++)
	{
		list_content.push_back(content.substr(k, size));
		k += size;
	}

	// check seek file end
	if (k < content.length())
	{
		list_content.push_back(content.substr(k, content.length() - k));
	}

	return list_content;
}

//  create
int Create_Name_File(string fileName, int num)
{
	int result;

	// change char to another char
	// key: a+2num mod 122
	for (int i = 0; i < fileName.length(); i++)
	{
		result = ((int)(fileName[i]) * num * 2 % (122));
	}
	return result;
}

// read file
void Divided(string fileName, int count_f)
{
	string content;
	vector<string> list_content;
	string filename_new = "";

	content = Read_From_File(fileName);
	// lay noi dung file
	list_content = Divided_Content(content, count_f);

	int k;
	for (int i = 2, k = 0; i <= count_f + 1; i++, k++)
	{
		filename_new = to_string(Create_Name_File(fileName, i));
		cout << "file " << k << ":" << filename_new << endl;
		Write_To_File(filename_new, list_content[k]);
	}

}

// merge file
void Join(vector <string> l_NameFile, int count_f)
{
	string content;
	string fileName;
	for (int i = 0; i < count_f; i++)
	{
		content += Read_From_File(l_NameFile[i]);
	}
	cout << "name file joined: ";
	cin >> fileName;
	Write_To_File(fileName + "Join", content);

}