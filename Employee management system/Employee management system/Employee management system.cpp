#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
//base class :0-employee, 1-manager, 2-boss
class worker
{
public:
	virtual void showinfo() = 0;
	int m_Id;
	string m_Name;
	int m_DeptId;

};
///////////////son class////////////////
//employee class: only has age attribute.
class employee :public worker
{
public:
	employee(int id, string name, int did)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_DeptId = did;
	}
	void showinfo()
	{
		cout << "ְ�����: " << m_Id
			<< "\tְ������: " << m_Name
			<< "\t��λ: " << "Ա��"
			<< "\tְ����: ��ɾ�����������" << endl;
	}

};
//manager class: has department attribute,and a special function
class manager :public worker
{
public:
	manager(int id, string name, int did)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_DeptId = did;
	}
	void showinfo()
	{
		cout << "ְ�����: " << m_Id
			<< "\tְ������: " << m_Name
			<< "\t��λ: " << "����"
			<< "\tְ����: ����ϰ彻�������񣬲��·���Ա��" << endl;
	}
};
//boss class
class boss :public worker
{
public:
	boss(int id, string name, int did)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_DeptId = did;
	}
	void showinfo()
	{
		cout << "ְ�����: " << m_Id
			<< "\tְ������: " << m_Name
			<< "\t��λ: " << "�ܲ�"
			<< "\tְ����: ����˾����" << endl;
	}

};
// class e_m_b: store the address of address array and record the number of the address
class e_m_b
{
public:
	e_m_b();
	void Show_Menu();
	void exit_system();
	void save_info();// store info
	int get_EmpNum();
	void init_emp();
	void show_emp();
	void del_emp();
	void mod_emp();
	void Find_emp();
	void sort_emp();
	void Clean_File();
	int IsExist(int id);
	~e_m_b();
	void Add_Emp();
	bool m_FileIsEmpty;
	int m_EmpNum;
	worker** m_EmpArray;
};
//function
void e_m_b::Show_Menu()
{
		cout << "***************************************" << endl;
		cout << "**********��ӭʹ��ְ������ϵͳ*********" << endl;
		cout << "************0.�˳��������*************" << endl;
		cout << "************1.����ְ����Ϣ*************" << endl;
		cout << "************2.��ʾְ����Ϣ*************" << endl;
		cout << "************3.ɾ����ְְ��*************" << endl;
		cout << "************4.�޸�ְ����Ϣ*************" << endl;
		cout << "************5.����ְ����Ϣ*************" << endl;
		cout << "************6.���ձ������*************" << endl;
		cout << "************7.��������ĵ�*************" << endl;
		cout << "***************************************" << endl;
		cout << endl;
}
//init the array, read the file
void e_m_b::init_emp()
{
	ifstream ifs;
	ifs.open("Info.txt", ios::in);
	int id;
	string name;
	int did;
	int index=0;
	while(ifs>>id && ifs>>name && ifs>>did)\
	{
		worker* worker_array;
		if (did == 1)
			worker_array = new employee(id, name, did);
		else if (did == 2)
			worker_array = new manager(id, name, did);
		else
			worker_array = new boss(id, name, did);
		this->m_EmpArray[index] = worker_array;
		index++;
	}
}
int e_m_b::get_EmpNum()
{
	ifstream ifs;
	ifs.open("Info.txt", ios::in);
	int count = 0;
	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		count++;
	}
	return count;
}
e_m_b::e_m_b()
{
	ifstream ifs;
	char ch;
	ifs.open("Info.txt", ios::in);
	ifs >> ch;
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_FileIsEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = 0;
		ifs.close();
	}
	else if (ifs.is_open() && ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}
	else
	{
		cout << "ְ��������Ϊ: " << this->get_EmpNum()<<endl;
		this->m_EmpNum = this->get_EmpNum();
		this->m_EmpArray = new worker * [this->m_EmpNum];
		this->init_emp();
	}
}
//show info
void e_m_b::show_emp()
{
	if (m_FileIsEmpty)
	{
		cout << "no this file" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}
//save info 
void e_m_b::save_info()
{
	ofstream ofs;
	ofs.open("Info.txt", ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{	
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

}
//exist??
int e_m_b::IsExist(int id)
{
	int location = -1;
	for (int i = 0; i < this->get_EmpNum(); i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			location = i;
			break;
		}
	}
	return location;
}
// exit 
void e_m_b::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

int main()
{

	while (true)
	{
		
		e_m_b wm;
		int choice;
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:wm.exit_system(); break;
		case 1:Add_Emp(); break;
		case 2:show_emp(); break;
		case 3:del_emp(); break;
		case 4:mod_emp(); break;
		case 5:Find_emp(); break;
		case 6:sort_emp(); break;
		case 7: break;
		default:
			system("cls");
			break;
		}

}