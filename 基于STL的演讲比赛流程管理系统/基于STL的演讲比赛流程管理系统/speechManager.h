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
	//创造12个比赛选手
	void createSpeaker();
	//成员属性，保存第一轮比赛选手编号，12。
	//control the compitition
	void startSpeech();
	//chouqian
	void speechDraw();
	//bisai
	void speechContest();
	//显示
	void showscore();
	//保存记录
	void savescore();
	//读取记录
	void loadrecord();
	//产看记录
	void showrecord();
	//清空记录
	void clearrecord();
	vector<int>v1;
	vector<int>v2;
	vector<int>vVictory;
	map<int, Speaker>m_Speaker;
	int m_Index;
	bool fileisempty;
	map<int, vector<string>>m_Record;

};