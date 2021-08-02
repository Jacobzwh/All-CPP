#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include"globalfile.h"
#include"identity.h"
#include<vector>
#include"teacher.h"
#include"student.h"
#include<algorithm>
#include<functional>
#include "computerRoom.h"
using namespace std;

class Manager :public Identity
{
public:

	Manager();//默认构造

	Manager(string name, string pwd);//有参构造，姓名，密码

	void openmenu();//选择菜单

	void addPerson();//添加学生或老师的账号

	void showPerson();//查看所有账号

	void showComputer();//查看机房信息

	void cleanFile();//清空预约记录

	//初始化获取文件原本内容
	void initVector();
	vector<Student> VStu;
	vector<Teacher> VTea;

	//查重
	bool checkRepeat(int id, int type);

	//机房
	vector<ComputerRoom>vCom;
};