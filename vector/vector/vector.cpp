
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
void test01()
{
	ofstream ofs;
	ofs.open("Info.txt", ios::out);
	ofs << "1" << " " << "всн╛" << " " << "98" << endl;

}
void test02()
{
	char buf[10000] = { 0 };
	ifstream ifs;
	ifs.open("Info.txt", ios::in);
	
	int id;
	string name;
	int did;

	int id_2;
	string name_2;
	int did_2;
	int age_2;

	int id_3;
	string name_3;
	int did_3;

	while (ifs.getline(buf, 10000))
	{
		
		if (buf[0]=='1')
		{
			ofstream other_ofs;
			other_ofs.open("other_file.txt", ios::out);
			other_ofs << buf << endl;
			ifstream other_ifs;
			other_ifs.open("other_file.txt", ios::in);
			while (other_ifs >> id && other_ifs >> name && other_ifs >> did)
			{
				cout << name << endl;
			}
		}
		else if(buf[0] == '2')
		{
			ofstream other_ofs;
			other_ofs.open("other_file_2.txt", ios::out);
			other_ofs << buf << endl;
			ifstream other_ifs;
			other_ifs.open("other_file_2.txt", ios::in);
			while (other_ifs >> id_2 && other_ifs >> name_2 && other_ifs >> did_2&& other_ifs >>age_2)
			{
				cout << name_2 << endl;
			}
		}
		else if (buf[0] == '3')
		{
			ofstream other_ofs;
			other_ofs.open("other_file_3.txt", ios::out);
			other_ofs << buf << endl;
			
		/*
			ifstream other_ifs;
			other_ifs.open("other_file_3.txt", ios::in);
			while (other_ifs >> id_3 && other_ifs >> name_3 )
			{
				cout << name_3 << endl;
			}
		*/
		}
		
	}

}
int main()
{
	
	test02();
}