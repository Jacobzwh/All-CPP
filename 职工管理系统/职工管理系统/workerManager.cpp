#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"
#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
void WorkerManager::init_emp()
{
	ifstream ifs;
	ifs.open("Info.txt",ios::in);
	int id;
	string name;
	int did;
	int index;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker;
		if (did == 1)
		{
			worker = new Employee(id,name,did);
		}
		if (did == 2)
		{
			worker = new manager(id, name, did);
		}
		if (did == 3)
		{
			worker = new boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open("Info.txt", ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}

//一上来就调用构造函数，两个目的：1.判断文件存不存在，如果存在计算有多少行，每一行都是多态父类的一个具体对象，
//判断每一行是哪种多态，然后堆区开辟，再开辟一个数组存放地址，初始化m_EmpArray
WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open("Info.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}
	//文件存在，但是里面没有内容
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}
	//文件存在，并且里面也有内容
	//先得到有多少行，在建立Worker*数组有多大，m_EmpArray数组个数才固定，不然会出错
	int num = this->get_EmpNum();
	cout << "职工人数为" << num<<endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//然后初始化m_EmpArray所指向的数组,获得文件中的所有数据
	this->init_emp();
}

void WorkerManager::show_emp()
{
	if (this->m_FileIsEmpty == NULL)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::del_emp()
{
	if (this->m_FileIsEmpty = NULL)
	{
		cout << "职工不存在" << endl;
	}
	else
	{
		cout << "请输入要删除的员工编号" << endl;
		int ID;
		int delete_num;
		cin >> ID;
		if (IsExist(ID) != -1)
		{
			delete_num = this->IsExist(ID);
			for (int i = delete_num; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "成功删除员工" <<endl;
		}
		else
		{
			cout << "找不到这名员工" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int location =-1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			location = i;
			break;
		}
	}
	return location;
}

void WorkerManager::mod_emp()
{
	if (this->m_FileIsEmpty == NULL)
	{
		cout << "文件夹为空" << endl;
	}
	else
	{
		cout << "请输入你要修改的职工编号" << endl;
		int mod_id;
		cin >> mod_id;
		if (this->IsExist(mod_id) != -1)
		{
			int number = this->IsExist(mod_id);
			delete this->m_EmpArray[number];
			int id;
			string name;
			int did;
			cout << "请输入新的职工编号" << endl;
			cin >> id;
			cout << "请输入新的职工姓名" << endl;
			cin >> name;
			cout << "请输入新的职工工作岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.公司老板" << endl;
			cin >> did;
			Worker* worker;
			switch (did)
			{
				case 1: worker = new Employee(id, name, did);  break;
				case 2: worker = new manager(id, name, did); break;
				case 3: worker = new boss(id, name, did); break;
				default:break;
			}
			this->m_EmpArray[this->IsExist(mod_id)] = worker;
			this->save();
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1.按照编号查找" << endl;
		cout << "2.按照姓名查找" << endl;
		int search_way;
		cin >> search_way;
		if (search_way == 1)
		{
			cout << "请输入要查找的员工编号" << endl;
			int id;
			cin >> id;
			if (this->IsExist(id) != -1)
			{
				cout << "成功找到此人" << endl;
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					if (this->m_EmpArray[i]->m_Id == id)
					{
						this->m_EmpArray[id]->showinfo();
						cout << endl;
					}
				}
				
			}
			else
			{
				cout << "查不到这个人" << endl;
			}
		}
		else if (search_way == 2)
		{
			cout << "请输入要查找的员工姓名" << endl;
			string name;
			cin >> name;
			bool flag=false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "找到此人了" << endl;
					flag =true;
					break;
				}
			}

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					this->m_EmpArray[i]->showinfo();
					cout << endl;
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查不到这个人" << endl;
			}
		}
		else
		{
			cout << "输入方式有误" << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManager::sort_emp()
{
	cout << "请输入你想选择为的排序方式" << endl;
	cout << "1.降序" << endl;
	cout << "2.升序" << endl;
	int sort_way;
	cin >> sort_way;
	if (this->m_EmpNum == 0)
	{
		if (sort_way == 1)
		{
			Worker* worker;
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[i + 1]->m_Id)
					{
						worker = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[i + 1];
						this->m_EmpArray[i + 1] = worker;
					}
				}
			}
			this->save();
			cout << "升序排序完成" << endl;
		}
		//降序排列，最大的在最前面
		else if (sort_way == 2)
		{
			Worker* worker;
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[i + 1]->m_Id)
					{
						worker = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[i + 1];
						this->m_EmpArray[i + 1] = worker;
					}
				}
			}
			int temp1;
			int temp2;
			Worker* temp3;
			for (int temp1 = 0, temp2 = this->m_EmpNum - 1; temp1 < temp2; temp1++, temp2--)
			{
				temp3 = this->m_EmpArray[temp1];
				this->m_EmpArray[temp1] = this->m_EmpArray[temp2];
				this->m_EmpArray[temp2] = temp3;
			}
			this->save();
			cout << "降序排序完成" << endl;
		}
	}
	else
	{
		cout << "没有任何人的信息，不能排序" << endl;
	}
	system("pause");
	system("cls");
}
; void WorkerManager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Show_Menu()
{
	cout << "***************************************" << endl;
	cout << "**********欢迎使用职工管理系统*********" << endl;
	cout << "************0.退出管理程序*************" << endl;
	cout << "************1.增加职工信息*************" << endl;
	cout << "************2.显示职工信息*************" << endl;
	cout << "************3.删除离职职工*************" << endl;
	cout << "************4.修改职工信息*************" << endl;
	cout << "************5.查找职工信息*************" << endl;
	cout << "************6.按照编号排序*************" << endl;
	cout << "************7.清空所有文档*************" << endl;
	cout << "***************************************" << endl;
	cout << endl;
}
void WorkerManager::Add_Emp()
{
	cout << "请输入你们要输入的人数" << endl;
	int number;
	int id;
	string name;
	int did;
	int real_number;
	cin >> number;
	if (number > 0)
	{
		Worker** newspace = new Worker * [this->m_EmpNum+number];//必须指明数组大小
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				*(newspace + i) = *(this->m_EmpArray + i);
				//newspace[i]=m_EmpArray[i];
			}
		}
		for (int i = 0; i < number; i++)
		{
			cout << "请输入第" << i + 1 << "个要添加的人" << endl;
			cout << "请输入编号：" << endl;
			cin >> id;
			cout << "请输入姓名： " << endl;
			cin >> name;
			cout << "请输入工作岗位：" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> did;

			real_number = number;
			//int *p=array[10]
			//p[2]这样访问也可以
			
			if (did != 1 && did != 2 && did != 3)
			{
				if (i == number - 1)
				{
					cout << "最后一个添加失败" << endl;
					real_number = real_number - 1;
				}
				else 
				{
					cout << "没有这种情况，添加失败，接着输入下一个" << endl;
					real_number = real_number - 1;
				}
			}
			else
			{
				Worker* a = NULL;
				switch (did)
				{
				case 1:	 a = new Employee(id, name, did); break;
				case 2:	 a = new manager(id, name, did);break;
				case 3:	 a = new boss(id, name, did);break;
				default:break;
				}
				*(newspace + this->m_EmpNum + i) = a;
			}
			
		}
		delete[]m_EmpArray;//delete掉m_EmpArray所指向的那块内存内容
		this->m_EmpNum = this->m_EmpNum + number;
		this->m_EmpArray = newspace;
		cout << "成功添加" << real_number <<"名成员"<<endl;
		this->save();
	}
	else
	{
		cout << "没有添加任何人信息" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open("Info.txt", ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
}
void WorkerManager::Clean_File()
{
	cout << "确认清空" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("Info.txt", ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
			}
			delete[]m_EmpArray;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}
		cout << "已经成功清除" << endl;
	}


}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete m_EmpArray[i];
		}
		delete[]m_EmpArray;
		this->m_EmpArray = NULL;

	}
}
