#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include"SHA1.h"
#include"Encrypt.h"
#include"Device_File.h"

//#define Out_FileName "output.txt"
using namespace std;
void Encrypt()
{
	string FileName = "input";
	string key;

	int cn = 0;

	do
	{
		system("cls");
		cout << " \n\n1: Ma hoa file" << endl;
		cout << "2: Giai ma file " << endl;
		cout << "-1: back" << endl;
		cout << "\tchon chuc nang: ";
		cin >> cn;

		if (cn == -1)
		{
			break;
		}
		switch (cn)
		{
		case 1:
		{
			////// encrypt
			cout << "nhap ten file: ";
			cin >> FileName;

			cout << "nhap khoa: ";
			cin >> key;
			char* k = new char[sha1(key).size() + 1];
			strcpy_s(k, strlen(k), sha1(key).c_str());
			cout << " Key duoc hash: " << k << endl;
			File_ENCRYPT(FileName, k);
			break;
		}
		case 2:
		{
			//////decrypt
			cout << "nhap ten file: ";
			cin >> FileName;

			cout << "nhap khoa: ";
			cin >> key;
			char* k = new char[sha1(key).size() + 1];

			strcpy_s(k, strlen(k), sha1(key).c_str());
			cout << " Key duoc hash: " << k << endl;

			File_DECRYPT(FileName, k);
			break;
		}
		default:
		{
			cout << "Ban khong chon chuc nang!" << endl;
			cout << "Ket thuc chuong trinh" << endl;
			break;
		}
		}
	} while (1);
}

void Devide_Join_file()
{
	int cn = 0;

	do
	{
		system("cls");
		cout << " \n\n1: chia file" << endl;
		cout << "2: gop file " << endl;
		cout << "-1: back" << endl;
		cout << "\tchon chuc nang: ";
		cin >> cn;

		if (cn == -1)
		{
			break;
		}
		switch (cn)
		{
		case 1:
		{
			string filename;
			int num_file;

			cout << "nhap ten file: ";
			cin >> filename;
			cout << "nhap so luong file can chia: ";
			cin >> num_file;

			Divided(filename, num_file);
			break;
		}
		case 2:
		{
			string filename;
			int num_file;
			vector <string> l_NameFile;
			cout << "nhap so luong file can gop: ";
			cin >> num_file;

			for (int i = 0; i < num_file; i++) {
				cout << "Nhap ten file " << i << ": ";
				cin >> filename;
				l_NameFile.push_back(filename);
			}
			Join(l_NameFile, num_file);
			break;
		}
		default:
		{
			cout << "Ban khong chon chuc nang!" << endl;
			cout << "Ket thuc chuong trinh" << endl;
			break;
		}
		}
	} while (1);
}


int main()
{
	int cn = 0;
	do
	{
		system("cls");
		cout << " \n\n1: Chia/Gop file" << endl;
		cout << "2: Ma hoa/Giai ma file " << endl;
		cout << "-1: ket thuc" << endl;
		cout << "\tchon chuc nang: ";
		cin >> cn;

		if (cn == -1)
		{
			break;
		}
		switch (cn)
		{
		case 1:
		{
			Devide_Join_file();
			break;
		}
		case 2:
		{
			Encrypt();
			break;
		}
		default:
		{
			cout << "Ban khong chon chuc nang!" << endl;
			cout << "Ket thuc chuong trinh" << endl;
			break;
		}
		}
	} while (1);

	return 0;
}