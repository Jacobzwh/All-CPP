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
	cout << "ְ�����" << m_Id
		<< "\tְ������" << m_Name
		<< "\t��λ: " << getDeptname()
		<< "\tְ����: ����˾��������" << endl;
}

string boss::getDeptname()
{
	return"�ܲ�";
}