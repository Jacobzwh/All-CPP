#include<iostream>
#include<ctime>
#include<string>
#include <fstream>
using namespace std;
/*
void test01()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "name and sex" << endl;
	ofs.close();
}*/
void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}
}
int main()

{
	test01();
}