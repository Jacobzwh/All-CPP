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
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
	ifs.close();

}

void Manager::openmenu()
{	
	cout << "��ӭ����Ա" << " " << this->m_Name << "��¼!" << endl;
	cout << "\t\t--------------------------------\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           1.����˺�          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           2.�鿴�˺�          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           3.�鿴����          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           4.���ԤԼ          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t|           0.ע����¼          |\n" << endl;
	cout << "\t\t|                               |\n" << endl;
	cout << "\t\t-------------------------------\n" << endl;
}

void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

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
			tip = "������ѧ��: ";
			errorTip = "ѧ���ظ�������������";
			break;
		}
		else if (select == 2)
		{
			filename = TEACHER_FILE;
			tip = "������ְ�����: ";
			errorTip = "ְ�����ظ�������������";
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
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

	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	//�ļ�д�뷽ʽ��������
	ofs << id << " " << name << " " << pwd <<" "<< endl;
	cout << "��ӳɹ�" << endl;
		 
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();

}

void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId <<" "<< "�������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//�º���,for_each û��
void printStudent(Student & s)//��(*v.begin)��ʲô���͵ģ��º����Ĳ�������ʲô����
{
	cout << "ѧ�ţ�" << s.m_Id<<" " << "������" << " " << s.m_Name << "���룺" << " " << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ѧ�ţ�" << t.m_EmpId << " " << "������" << " " << t.m_Name << "���룺" << " " << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "��ѡ��������ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴��������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(VStu.begin(), VStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(VTea.begin(), VTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}
//���ԤԼ
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	//��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "ѧ���ļ���ȡʧ��" << endl;
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
	
	cout << "��ǰѧ��������" << VStu.size()<<endl;
	ifs.close();

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ���ȡʧ��" << endl;
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
	cout << "��ǰ��ʦ������" << VTea.size() << endl;
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