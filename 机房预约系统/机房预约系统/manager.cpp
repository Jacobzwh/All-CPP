#include"manager.h"
using namespace std;

Manager::Manager()
{
	
}

Manager::Manager(string name,string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;
	ifs.close();

}

void Manager::openmenu()
{	
	cout << "欢迎管理员" << " " << this->m_Name << "登录!" << endl;
	cout << "\t\t--------------------------------\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           1.添加账号          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           2.查看账号          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           3.查看机房          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           4.清空预约          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           0.注销登录          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
}

void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string filename;
	string tip;
	string errorTip;
	ofstream ofs;


	int select = 0;
	cin >> select;
	while (true)
	{
		if (select == 1)
		{
			filename = STUDENT_FILE;
			tip = "请输入学号: ";
			errorTip = "学号重复，请重新输入";
			break;
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			tip = "请输入职工编号: ";
			errorTip = "职工号重复，请重新输入";
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret=checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}	
	}

	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	//文件写入方式就是这样
	ofs << id << " " << name << " " << pwd <<" "<< endl;
	cout << "添加成功" << endl;
		 
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();

}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId <<" "<< "机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//仿函数,for_each 没懂
void printStudent(Student & s)//看(*v.begin)是什么类型的，仿函数的参数就是什么类型
{
	cout << "学号：" << s.m_Id<<" " << "姓名：" << " " << s.m_Name << "密码：" << " " << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "学号：" << t.m_EmpId << " " << "姓名：" << " " << t.m_Name << "密码：" << " " << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "请选择产看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有内容" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(VStu.begin(), VStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下：" << endl;
		for_each(VTea.begin(), VTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//清空预约
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	//读取学生文件中的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "学生文件读取失败" << endl;
		system("pause");
		return;
	}
	VStu.clear();
	VTea.clear();

	int sid;
	string sname;
	string spwd;
	while (ifs >> sid && ifs >> sname && ifs >> spwd)
	{
		Student s(sid, sname, spwd);
		VStu.push_back(s);
	}
	
	cout << "当前学生数量：" << VStu.size()<<endl;
	ifs.close();

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "老师文件读取失败" << endl;
		system("pause");
		return;
	}
	int tid;
	string tname;
	string tpwd;

	while (ifs >> tid && ifs >> tname && ifs >> tpwd)
	{
		Teacher t(tid, tname, tpwd);
		VTea.push_back(t);
	}
	cout << "当前老师数量：" << VTea.size() << endl;
	ifs.close();
	//this->initVector();

}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = VStu.begin(); it != VStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = VTea.begin(); it != VTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}

	return false;
}