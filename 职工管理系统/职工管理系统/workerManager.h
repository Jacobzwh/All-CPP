#pragma once;
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include"worker.h"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	void Show_Menu();
	void exit_system();
	void save();
	int get_EmpNum();
	void init_emp();
	void show_emp();
	void del_emp();
	void mod_emp();
	void Find_emp();
	void sort_emp();
	void Clean_File();
	int IsExist(int id);
	~WorkerManager();
	void Add_Emp();
	bool m_FileIsEmpty;
	int m_EmpNum;
	Worker**m_EmpArray;
	//m_EmpArray���һ����ַ����ַָ��һ��Worker*,����ָ��Ĭ���ǿ�������ģ��ҵ���˼������������int**p=new int*[6];Ȼ��delete[]p
	// ��Ϊ��֪��pָ����ǿ��ڴ�Ķ�����һ������
	//int p= new int[6];delet p;����֪��pָ����ǿ��ڴ�Ķ����������飬����һ���������ѡ�
};
