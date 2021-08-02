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

	Student();//�޲�����

	Student(int id, string name, string pwd);//�в�����

	void openmenu();//��д

	void applyOrder();//����ԤԼ

	void showMyOrder();//�鿴�ҵ�ԤԼ

	void showAllOrder();//�鿴����ԤԼ

	void cancelOrder();//ȡ��ԤԼ
	
	int m_Id;//ѧ�����е�ѧ��

	//����
	vector<ComputerRoom> vCom;

};