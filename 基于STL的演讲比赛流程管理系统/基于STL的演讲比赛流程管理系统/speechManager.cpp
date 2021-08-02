#include"speechManager.h"
#include<string>

SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeech();
	//��ʼ��12λѡ�֣����ֻ������֡��ŵ�V1��Map��
	this->createSpeaker();
	//���������¼
	this->loadrecord();
}

void SpeechManager::show_menu()
{
	cout << "****************************************" << endl;
	cout << "*************��ӭ�μ��ݽ�����***********" << endl;
	cout << "**************1.��ʼ�ݽ�����************" << endl;
	cout << "**************2.�鿴�����¼************" << endl;
	cout << "**************3.��ձ�����¼************" << endl;
	cout << "**************0.�˳���������************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

void SpeechManager::initSpeech()
{
	//set zero
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	//the times of the round of the competitiomn
	this->m_Index = 1;
	this -> m_Record.clear();
}
//��v1���������12��
void SpeechManager::createSpeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "ѡ��";
		name += nameseed[i];

		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//����ѡ�ֱ�ţ����뵽V1������
		//vector ����push_back,map����insert����(Key,value)
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
//���Ʊ�������
void SpeechManager::startSpeech()
{
	//��һ�ֱ���
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ�������
	this->showscore();
	//�ڶ��ֱ���
	this->m_Index++;
	//1.��ǩ
	this->speechDraw();
	//2.����
	this->speechContest();
	//3.��ʾ���ս��
	this->showscore();
	//4.�������
	this->savescore();

	///////////����
	//��Ϊ��ʼ��ʱ��m_Record��ȥ���ı��ļ������������3�оͶ����������
	//���ڱ�����һ���ˣ�����ͨ��saverecord׷�ӵ��µ�һ���ˣ����ǻ���Ҫ����initspeech��index��2���1
	//Ȼ������loadrecord��ǰ�������·���m_record�����У�������ȥ����case2�ſ��Լ�ʱ���¡�
	//��ʼ������
	this->initSpeech();
	//��ʼ��12λѡ�֣����ֻ������֡��ŵ�V1��Map��
	this->createSpeaker();
	//���������¼
	this->loadrecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}
//
void SpeechManager::speechDraw()
{
	cout << "��" << "<<"<<this->m_Index<<">>"<< "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------------" << endl;
	cout << "��ǩ���ݽ�˳������" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
			cout << endl;
		}
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
			cout << endl;
		}
	}
	cout << "----------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechContest()
{
	cout << "��" <<"<<"<<this->m_Index<<">>"<<"�ֱ�����ʽ��ʼ"<< endl;
	//��ʱmap,�������а��շ�����������
	multimap<double, int, greater<double>>groupscore;
	int num = 0;
	vector<int>v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}//��������ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = rand() % 41 + 60.00;
			//cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater <double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0);
		double avg = sum/(double)d.size();
		//cout << "���: " << *it << "����: " << this->m_Speaker[*it].m_Name <<
			//"ƽ������:  " << avg << endl;

		//��ʼ����ʱ��map�����е�m_Name�Ѿ���ʼ��д��ȥ�ˣ�����д���Ƿ���
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//it��vector1��ָ�룬vector1�д�ŵĵ�Ȼ��ѡ�ֵı��
		groupscore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������ʣ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)
			{
				//it��first��ƽ���֣�it��second�Ǳ��
				//speaker��map��keyֵ�Ǳ�ţ����԰��ձ�ż���
				cout << "���: " << it->second << "����: " <<
					this->m_Speaker[it->second].m_Name << "����: "
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end() && count < 3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			cout << endl;
			groupscore.clear();
		}

	}
	//������12���ڴ�ӡ���
	//cout << endl;
	cout << "��" << this->m_Index << "�ֱ�����ϣ�" << endl;
	system("pause");
}

void SpeechManager::showscore()
{
	cout << "��" <<this->m_Index<< "�ֽ���ѡ����Ϣ����" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << "������" << this->m_Speaker[*it].m_Name <<
			"�÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("cls");

}
//�����¼
void SpeechManager::savescore()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	//׷�ӵķ�ʽд�ļ�
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
	this->fileisempty = false;
}
void SpeechManager::loadrecord()
{
	ifstream ifs("speech.csv",ios::in);
	if (!ifs.is_open())
	{
		this->fileisempty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;//ΪʲôҪreturn��
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileisempty = true;
		ifs.clear();
		return;
	}
	this->fileisempty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	//���ַ�����һ�ζ�ȡһ�У�data��һ�����ݵ�����
	while (ifs >> data)
	{
		cout << data << endl;
		//��������
		//10002,86,10009
		vector<string>v;//////////
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);//5
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index,v));
		index++;
	}
	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	//{
	//	cout << it->first << "�ھ���ţ�" << it->second[0] << "������" << it->second[1] << endl;
	//}
}

void SpeechManager::showrecord()
{
	if (this->fileisempty)
	{
		cout << "�ļ������ڣ����¼Ϊ�գ�" << endl;
	}
	//һ�����ͻ������������������������������������m_Record������������ˡ�
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "��" << i + 1 << "��" << "�ھ���ţ�" << this->m_Record[i][0] << "�÷֣�" << this->m_Record[i][1] << " " << endl;
		cout << "��" << i + 1 << "��" << "�Ǿ���ţ�" << this->m_Record[i][2] << "�÷֣�" << this->m_Record[i][3] << " " << endl;
		cout << "��" << i + 1 << "��" << "������ţ�" << this->m_Record[i][4] << "�÷֣�" << this->m_Record[i][5] << " " << endl;

	}
	system("pause");
	system("cls");
}

void SpeechManager::clearrecord()
{
	cout << "ȷ�����" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//ios::trunc�����ҵ�������ļ��Ͱ���ɾ��
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->initSpeech();
		//��ʼ��12λѡ�֣����ֻ������֡��ŵ�V1��Map��
		this->createSpeaker();
		//���������¼
		this->loadrecord();

		cout << "��ճɹ���" << endl;
	}
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{

}