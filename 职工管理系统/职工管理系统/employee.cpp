#pragma once
#include<iostream>
#include<string>
#include"employee.h"
using namespace std;

Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;

}

void Employee::showinfo()
{
	cout << "ְ�����" << m_Id
		<< "\tְ������" << m_Name
		<< "\t��λ: " << getDeptname()
		<< "\tְ����: ��ɾ�����������" << endl;
}

string Employee::getDeptname()
{
	return"Ա��";
}