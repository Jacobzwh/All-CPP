#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class student 
{
public:
	string name;
	int number;
	void getname(string name_1)
	{
		name = name_1;
	}
	void getnumber(int  number_1)
	{
		number = number_1;
	}
	void printinfo()
	{
		cout << "学生的姓名是： " <<name<< endl;
		cout << "学生的学号是： " << number<<endl;
	}


};

int main()
{
	student s1;
	s1.getname("Ziwei Huang");
	s1.getnumber(20);
	s1.printinfo();
	system("pause");
	return 0;

}