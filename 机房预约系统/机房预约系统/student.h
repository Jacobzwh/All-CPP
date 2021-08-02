#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include"identity.h"
#include"computerRoom.h"
#include<vector>
#include<algorithm>
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
using namespace std;

class Student : public Identity
{
public:

	Student();//无参析构

	Student(int id, string name, string pwd);//有参析构

	void openmenu();//重写

	void applyOrder();//申请预约

	void showMyOrder();//查看我的预约

	void showAllOrder();//查看所有预约

	void cancelOrder();//取消预约
	
	int m_Id;//学生特有的学号

	//机房
	vector<ComputerRoom> vCom;

};