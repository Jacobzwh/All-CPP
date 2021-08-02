#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include "identity.h"
#include"computerRoom.h"
#include<vector>
#include<algorithm>
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Teacher :public Identity
{
public:

	Teacher();//默认构造

	Teacher(int id, string name, string pwd);//有参构造

	void openmenu();//菜单界面

	void showAllOrder();//查看所有预约

	void validOrder();//审核预约

	int m_EmpId;//教师编号
};