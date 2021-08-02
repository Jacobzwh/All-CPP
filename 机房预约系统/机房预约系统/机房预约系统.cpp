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
//ȫ�ֺ���������Ա���Ӳ˵�
//�ҵ�����ǣ�Identity* person = new manager(name,pwd)
//����ȷʵ�����˲�ͬ�븸���ڴ��С��һƬ��������manager��һƬ����
//ͬ��manager->�ķ���ֻ�ܷ������ุ���й��е��ǲ���
//Ҫǿ�а�ָ���������ĸ���ָ��ת��������ָ�룬��ַ���������ַ
//��Ȩ�޲�һ���ˣ�����ͨ��man->����ʽ�����������г�Ա�ͺ���
void managerMenu(Identity* &manager)//manager��һ��ָ��
{
	while (true) 
	{
		manager->openmenu();

		Manager* man = (Manager*)manager;//manager��һ������ָ�봫��
		int select = 0;
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;//����return��return���ڵĺ����ͽ�����
		}
	}
}

//ȫ�ֺ�����ѧ�����Ӳ˵�
void studentMenu(Identity* &student)//manager��һ��ָ��
{
	while (true)
	{
		student->openmenu();

		Student* stu = (Student*)student;//manager��һ������ָ�봫��
		int select = 0;
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			cout << "��������ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;//����return��return���ڵĺ����ͽ�����
		}
	}
}

//ȫ�ֺ�������ʦ���Ӳ˵�
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
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��¼����  ����1 �����ļ���������2 ��Ա����
void LoginIn(string Filename, int type)
{
	//����ָ������ָ���������
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(Filename, ios::in);
	//�ж��ļ��Ƿ���ڵ�������д��
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		//���ַ�����һ���ص���ǻ�һ��һ�ж�ȥɨ��
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				// cout<<fID<<fName<<fPwd<<endl;
				cout << "ѧ����֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);//��break�˳�Ҳ��
				studentMenu(person);
				return;//����return ���˳���ǰ�ĺ���
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;//����return ���˳���ǰ�ĺ���
			}
		}

	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager (name, pwd);
				managerMenu(person);
				return;//����return ���˳���ǰ�ĺ���
			}
		}
	}
	cout << "��֤��½ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;
	while (true)
	{
		cout << "=========================== ��ӭ��������ԤԼϵͳ ==========================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t ---------------------------------------\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|               1.ѧ������              |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|               2.��    ʦ              |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|               3.�� �� Ա              |\n";
		cout << "\t\t|                                       |\n";
		cout << "\t\t|               0.��    ��              |\n";
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
		case 0:cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;//����return 0�� main����������3
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}