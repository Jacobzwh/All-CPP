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
		cout << "选手编号: " << it->first<<" "
			<< "姓名: " << it->second.m_Name<<" "
			<< "成绩1: " << it->second.m_Score[0]  
			<< "成绩2: " << it->second.m_Score[1] << endl;
	}
	int choice=0;
	while (true)
	{
		sm.show_menu();
		cout << "请输入您的选项：" << endl;
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