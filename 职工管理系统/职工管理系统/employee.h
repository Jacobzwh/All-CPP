#include<iostream>
#include<ctime>
#include<string>
using namespace std;
#include"worker.h"
//���¼̳��ˣ����Բ���virtual�ˣ�
class Employee :public Worker
{
public:
	Employee(int id, string name, int did);
	Employee();
	void showinfo();
	string getDeptname();

};


