#pragma once
#include<iostream>
#include<string>
#include"manager.h"
using namespace std;

manager::manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;

}

void manager::showinfo()
{
	cout << "ְ�����" << m_Id
		<< "\tְ������" << m_Name
		<< "\t��λ: " << getDeptname()
		<< "\tְ����: ����ϰ彻�������񣬲��·���Ա��" << endl;
}

string manager::getDeptname()
{
	return"����";
}