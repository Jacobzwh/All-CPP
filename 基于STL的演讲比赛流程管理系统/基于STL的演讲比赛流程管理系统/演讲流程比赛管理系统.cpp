#include<iostream>
using namespace std;
#include"speechManager.h"
#include<string>
#include <ctime>
int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	//test
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ��: " << it->first<<" "
			<< "����: " << it->second.m_Name<<" "
			<< "�ɼ�1: " << it->second.m_Score[0]  
			<< "�ɼ�2: " << it->second.m_Score[1] << endl;
	}
	int choice=0;
	while (true)
	{
		sm.show_menu();
		cout << "����������ѡ�" << endl;
		cin >> choice;

		switch (choice)
		{
			//start the competition
		case 1:sm.startSpeech();
			break;
			// search records
		case 2:sm.showrecord();
			break;
			//delete record;
		case 3:sm.clearrecord();
			break;
			//break out the system
		case 0:sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}