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

	Teacher();//Ĭ�Ϲ���

	Teacher(int id, string name, string pwd);//�вι���

	void openmenu();//�˵�����

	void showAllOrder();//�鿴����ԤԼ

	void validOrder();//���ԤԼ

	int m_EmpId;//��ʦ���
};