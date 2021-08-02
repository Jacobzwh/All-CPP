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

	Manager();//Ĭ�Ϲ���

	Manager(string name, string pwd);//�вι��죬����������

	void openmenu();//ѡ��˵�

	void addPerson();//���ѧ������ʦ���˺�

	void showPerson();//�鿴�����˺�

	void showComputer();//�鿴������Ϣ

	void cleanFile();//���ԤԼ��¼

	//��ʼ����ȡ�ļ�ԭ������
	void initVector();
	vector<Student> VStu;
	vector<Teacher> VTea;

	//����
	bool checkRepeat(int id, int type);

	//����
	vector<ComputerRoom>vCom;
};