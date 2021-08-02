#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;
//全局函数，管理员的子菜单
//我的理解是，Identity* person = new manager(name,pwd)
//堆区确实开辟了不同与父类内存大小的一片关于子类manager的一片区域
//同过manager->的方法只能访问子类父类中共有的那部分
//要强行把指向子类对象的父类指针转换成子类指针，地址还是这个地址
//但权限不一样了，可以通过man->的形式访问子类所有成员和函数
void managerMenu(Identity* &manager)//manager是一个指针
{
	while (true) 
	{
		manager->openmenu();

		Manager* man = (Manager*)manager;//manager是一个父类指针传入
		int select = 0;
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;//遇到return，return所在的函数就结束了
		}
	}
}

//全局函数，学生的子菜单
void studentMenu(Identity* &student)//manager是一个指针
{
	while (true)
	{
		student->openmenu();

		Student* stu = (Student*)student;//manager是一个父类指针传入
		int select = 0;
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			cout << "查看自身预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			cout << "产看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;//遇到return，return所在的函数就结束了
		}
	}
}

//全局函数，教师的子菜单
void TeacherMenu(Identity* &teacher)
{
	while (true)
	{
		teacher->openmenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录功能  参数1 操作文件名，参数2 人员类型
void LoginIn(string Filename, int type)
{
	//父类指针用于指向子类对象
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(Filename, ios::in);
	//判断文件是否存在的三步骤写法
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;
		string fName;
		string fPwd;
		//这种方法有一个特点就是会一行一行读去扫描
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				// cout<<fID<<fName<<fPwd<<endl;
				cout << "学生验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);//用break退出也行
				studentMenu(person);
				return;//遇到return 就退出当前的函数
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;//遇到return 就退出当前的函数
			}
		}

	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager (name, pwd);
				managerMenu(person);
				return;//遇到return 就退出当前的函数
			}
		}
	}
	cout << "验证登陆失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "=========================== 欢迎来到机房预约系统 ==========================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t ---------------------------------------\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|               1.学生代表              |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|               2.老    师              |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|               3.管 理 员              |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|               0.退    出              |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t ---------------------------------------\n";

		cin >> select;
		switch (select)
		{
		case 1:LoginIn(STUDENT_FILE, 1);
			break;
		case 2:LoginIn(TEACHER_FILE, 2);
			break;
		case 3:LoginIn(ADMIN_FILE, 3);
			break;
		case 0:cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;//遇到return 0， main主函数结束3
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}