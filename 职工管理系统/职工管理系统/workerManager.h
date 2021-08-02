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
	//m_EmpArray存放一个地址，地址指向一个Worker*,二级指针默认是可以数组的，我的意思是类似这样：int**p=new int*[6];然后delete[]p
	// 因为你知道p指向的那块内存的东西是一块数组
	//int p= new int[6];delet p;，你知道p指向的那块内存的东西不是数组，就是一个东西而已。
};
