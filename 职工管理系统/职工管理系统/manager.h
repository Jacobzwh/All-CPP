#include<iostream>
#include<ctime>
#include<string>
using namespace std;
#include"Worker.h"
//重新继承了，可以不加virtual了，
class manager :public Worker
{
public:
	manager(int id, string name, int did);

	void showinfo();
	string getDeptname();

};


