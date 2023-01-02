#include "Encrypt.h"


// encrypt text
void Encrypt(char* plaintext, int len, char* key)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	int keylen = strlen(key);
	for (int i = 0, k = 0; i < len; i++, k++)
	{
		if (k == (ltm.tm_min % keylen))
		{
			k = 0;
		}

		plaintext[i] ^= key[k];
	}
}
// decrypt text
void Decrypt(char* ciphertext, int len, char* key)
{
	Encrypt(ciphertext, len, key);
}

// read file
char* ReadFile(string In_FileName, int& fileSize)
{
	char* content;
	ifstream file_in(In_FileName + ".txt", ios::ate | ios::binary);
	if (file_in.fail())
	{
		cout << "khong mo duoc file" << endl;
	}
	else
	{
		fileSize = file_in.tellg();
		file_in.seekg(0, ios::beg);
		content = new char[fileSize];

		if (!content)
		{
			file_in.close();
			cout << "khoi tao that bai" << endl;
		}

		file_in.read((char*)content, fileSize * sizeof(int));
		file_in.close();
		return content;
	}

}
// write file
void WriteFile(string Out_FileName, char* content, int fileSize)
{
	ofstream file_out(Out_FileName + ".txt", ios::binary);
	if (file_out.fail())
	{
		cout << "khong mo duoc file" << endl;
		return;
	}
	file_out.write((char*)content, fileSize);
	file_out.close();

}

void File_ENCRYPT(string In_FileName, char* key)
{

	int fileSize = 0;
	char* content = ReadFile(In_FileName, fileSize);
	Encrypt(content, fileSize, key);

	string Out_FileName = "";
	Out_FileName = In_FileName + "_Encrypt";

	WriteFile(Out_FileName, content, fileSize);
	cout << "\n\tMA HOA THANH CONG" << endl;

}
void File_DECRYPT(string In_FileName, char* key)
{

	int fileSize = 0;
	char* content = ReadFile(In_FileName, fileSize);
	Decrypt(content, fileSize, key);

	string Out_FileName = "";
	Out_FileName = In_FileName + "_Decrypt";

	WriteFile(Out_FileName, content, fileSize);

	cout << "\n\tGIAI MA THANH CONG" << endl;
}