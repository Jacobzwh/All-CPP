#include<iostream>
#include<ctime>
#include<string>
using namespace std;
#include"worker.h"
//重新继承了，可以不加virtual了，
class Employee :public Worker
{
public:
	Employee(int id, string name, int did);
	Employee();
	void showinfo();
	string getDeptname();

};


