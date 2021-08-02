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

//һ�����͵��ù��캯��������Ŀ�ģ�1.�ж��ļ��治���ڣ�������ڼ����ж����У�ÿһ�ж��Ƕ�̬�����һ���������
//�ж�ÿһ�������ֶ�̬��Ȼ��������٣��ٿ���һ�������ŵ�ַ����ʼ��m_EmpArray
WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open("Info.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}
	//�ļ����ڣ���������û������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
	}
	//�ļ����ڣ���������Ҳ������
	//�ȵõ��ж����У��ڽ���Worker*�����ж��m_EmpArray��������Ź̶�����Ȼ�����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ" << num<<endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//Ȼ���ʼ��m_EmpArray��ָ�������,����ļ��е���������
	this->init_emp();
}

void WorkerManager::show_emp()
{
	if (this->m_FileIsEmpty == NULL)
	{
		cout << "�ļ�������" << endl;
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
		cout << "ְ��������" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա�����" << endl;
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
			cout << "�ɹ�ɾ��Ա��" <<endl;
		}
		else
		{
			cout << "�Ҳ�������Ա��" << endl;
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
		cout << "�ļ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ�ְ�����" << endl;
		int mod_id;
		cin >> mod_id;
		if (this->IsExist(mod_id) != -1)
		{
			int number = this->IsExist(mod_id);
			delete this->m_EmpArray[number];
			int id;
			string name;
			int did;
			cout << "�������µ�ְ�����" << endl;
			cin >> id;
			cout << "�������µ�ְ������" << endl;
			cin >> name;
			cout << "�������µ�ְ��������λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.��˾�ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڼ�¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.���ձ�Ų���" << endl;
		cout << "2.������������" << endl;
		int search_way;
		cin >> search_way;
		if (search_way == 1)
		{
			cout << "������Ҫ���ҵ�Ա�����" << endl;
			int id;
			cin >> id;
			if (this->IsExist(id) != -1)
			{
				cout << "�ɹ��ҵ�����" << endl;
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
				cout << "�鲻�������" << endl;
			}
		}
		else if (search_way == 2)
		{
			cout << "������Ҫ���ҵ�Ա������" << endl;
			string name;
			cin >> name;
			bool flag=false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "�ҵ�������" << endl;
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
				cout << "�鲻�������" << endl;
			}
		}
		else
		{
			cout << "���뷽ʽ����" << endl;
		}

	}
	system("pause");
	system("cls");
}

void WorkerManager::sort_emp()
{
	cout << "����������ѡ��Ϊ������ʽ" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
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
			cout << "�����������" << endl;
		}
		//�������У���������ǰ��
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
			cout << "�����������" << endl;
		}
	}
	else
	{
		cout << "û���κ��˵���Ϣ����������" << endl;
	}
	system("pause");
	system("cls");
}
; void WorkerManager::exit_system()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Show_Menu()
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
void WorkerManager::Add_Emp()
{
	cout << "����������Ҫ���������" << endl;
	int number;
	int id;
	string name;
	int did;
	int real_number;
	cin >> number;
	if (number > 0)
	{
		Worker** newspace = new Worker * [this->m_EmpNum+number];//����ָ�������С
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
			cout << "�������" << i + 1 << "��Ҫ��ӵ���" << endl;
			cout << "�������ţ�" << endl;
			cin >> id;
			cout << "������������ " << endl;
			cin >> name;
			cout << "�����빤����λ��" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> did;

			real_number = number;
			//int *p=array[10]
			//p[2]��������Ҳ����
			
			if (did != 1 && did != 2 && did != 3)
			{
				if (i == number - 1)
				{
					cout << "���һ�����ʧ��" << endl;
					real_number = real_number - 1;
				}
				else 
				{
					cout << "û��������������ʧ�ܣ�����������һ��" << endl;
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
		delete[]m_EmpArray;//delete��m_EmpArray��ָ����ǿ��ڴ�����
		this->m_EmpNum = this->m_EmpNum + number;
		this->m_EmpArray = newspace;
		cout << "�ɹ����" << real_number <<"����Ա"<<endl;
		this->save();
	}
	else
	{
		cout << "û������κ�����Ϣ" << endl;
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
	cout << "ȷ�����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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
		cout << "�Ѿ��ɹ����" << endl;
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
