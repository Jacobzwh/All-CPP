#pragma once
#include<iostream>
#include<fstream>
#include"speaker.h"
using namespace std;
#include<vector>
#include<map>
#include<deque>
#include<algorithm>
#include<functional>
#include<numeric>
#include<string>
// create class

class SpeechManager
{
public:

	SpeechManager();
	void show_menu();
	void exitSystem();
	~SpeechManager();
	//initiate the class
	void initSpeech();
	//����12������ѡ��
	void createSpeaker();
	//��Ա���ԣ������һ�ֱ���ѡ�ֱ�ţ�12��
	//control the compitition
	void startSpeech();
	//chouqian
	void speechDraw();
	//bisai
	void speechContest();
	//��ʾ
	void showscore();
	//�����¼
	void savescore();
	//��ȡ��¼
	void loadrecord();
	//������¼
	void showrecord();
	//��ռ�¼
	void clearrecord();
	vector<int>v1;
	vector<int>v2;
	vector<int>vVictory;
	map<int, Speaker>m_Speaker;
	int m_Index;
	bool fileisempty;
	map<int, vector<string>>m_Record;

};