#include<iostream>
#include<ctime>
#include<string>
using namespace std;
#include"Worker.h"
//���¼̳��ˣ����Բ���virtual�ˣ�
class boss :public Worker
{
public:
	boss(int id, string name, int did);

	void showinfo();
	string getDeptname();

};


