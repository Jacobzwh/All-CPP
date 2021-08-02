#pragma once
#include<iostream>
#include<string>
#include"boss.h"
using namespace std;

boss::boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;

}

void boss::showinfo()
{
	cout << "职工编号" << m_Id
		<< "\t职工姓名" << m_Name
		<< "\t岗位: " << getDeptname()
		<< "\t职责是: 管理公司所有事物" << endl;
}

string boss::getDeptname()
{
	return"总裁";
}