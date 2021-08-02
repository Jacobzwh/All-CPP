#pragma once
#include <iostream>
#include <ctime>
#include<string>
using namespace std;

class Worker
{
public:
	virtual void showinfo()=0;
	virtual string getDeptname()=0;
	int m_Id;
	string m_Name;
	int m_DeptId;

};
