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
	cout << "职工编号" << m_Id
		<< "\t职工姓名" << m_Name
		<< "\t岗位: " << getDeptname()
		<< "\t职责是: 完成老板交付的任务，并下发给员工" << endl;
}

string manager::getDeptname()
{
	return"经理";
}