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
	cout << "职工编号" << m_Id
		<< "\t职工姓名" << m_Name
		<< "\t岗位: " << getDeptname()
		<< "\t职责是: 完成经理交付的任务" << endl;
}

string Employee::getDeptname()
{
	return"员工";
}