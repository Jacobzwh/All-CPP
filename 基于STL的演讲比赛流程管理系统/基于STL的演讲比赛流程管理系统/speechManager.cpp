#include"speechManager.h"
#include<string>

SpeechManager::SpeechManager()
{
	//初始化容器
	this->initSpeech();
	//初始化12位选手，名字还有数字。放到V1和Map中
	this->createSpeaker();
	//加载往届记录
	this->loadrecord();
}

void SpeechManager::show_menu()
{
	cout << "****************************************" << endl;
	cout << "*************欢迎参加演讲比赛***********" << endl;
	cout << "**************1.开始演讲比赛************" << endl;
	cout << "**************2.查看往届记录************" << endl;
	cout << "**************3.清空比赛记录************" << endl;
	cout << "**************0.退出比赛程序************" << endl;
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
//把v1容器扩充成12个
void SpeechManager::createSpeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "选手";
		name += nameseed[i];

		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//创建选手编号，放入到V1容器中
		//vector 是用push_back,map是用insert插入(Key,value)
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
//控制比赛流程
void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示晋级结果
	this->showscore();
	//第二轮比赛
	this->m_Index++;
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示最终结果
	this->showscore();
	//4.保存分数
	this->savescore();

	///////////重置
	//因为初始化时候m_Record会去读文本文件，如果里面有3行就都会放入里面
	//现在比赛完一轮了，内容通过saverecord追加到新的一行了，但是还是要调用initspeech把index从2变成1
	//然后再用loadrecord把前四行重新放入m_record容器中，这样再去进行case2才可以及时更新。
	//初始化容器
	this->initSpeech();
	//初始化12位选手，名字还有数字。放到V1和Map中
	this->createSpeaker();
	//加载往届记录
	this->loadrecord();

	cout << "本届比赛完毕：" << endl;
	system("pause");
	system("cls");
}
//
void SpeechManager::speechDraw()
{
	cout << "第" << "<<"<<this->m_Index<<">>"<< "轮比赛选手正在抽签" << endl;
	cout << "---------------------------" << endl;
	cout << "抽签后演讲顺序如下" << endl;
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
	cout << "第" <<"<<"<<this->m_Index<<">>"<<"轮比赛正式开始"<< endl;
	//临时map,在容器中按照分数降序排列
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
	}//遍历所有选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
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
		//cout << "编号: " << *it << "姓名: " << this->m_Speaker[*it].m_Name <<
			//"平均分是:  " << avg << endl;

		//初始化的时候map容器中的m_Name已经初始化写进去了，这里写的是分数
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//it是vector1的指针，vector1中存放的当然是选手的编号
		groupscore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名词：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupscore.begin(); it != groupscore.end(); it++)
			{
				//it。first是平均分，it。second是编号
				//speaker是map，key值是编号，可以按照编号检索
				cout << "编号: " << it->second << "姓名: " <<
					this->m_Speaker[it->second].m_Name << "分数: "
					<< this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			//取走前三名
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
	//遍历完12个在打印这个
	//cout << endl;
	cout << "第" << this->m_Index << "轮比赛完毕！" << endl;
	system("pause");
}

void SpeechManager::showscore()
{
	cout << "第" <<this->m_Index<< "轮晋级选手信息如下" << endl;
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
		cout << "选手编号：" << *it << "姓名：" << this->m_Speaker[*it].m_Name <<
			"得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("cls");

}
//保存记录
void SpeechManager::savescore()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	//追加的方式写文件
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "记录已经保存" << endl;
	this->fileisempty = false;
}
void SpeechManager::loadrecord()
{
	ifstream ifs("speech.csv",ios::in);
	if (!ifs.is_open())
	{
		this->fileisempty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;//为什么要return啊
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileisempty = true;
		ifs.clear();
		return;
	}
	this->fileisempty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	//这种方法是一次读取一行，data是一行数据的内容
	while (ifs >> data)
	{
		cout << data << endl;
		//解析数据
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
	//	cout << it->first << "冠军编号：" << it->second[0] << "分数：" << it->second[1] << endl;
	//}
}

void SpeechManager::showrecord()
{
	if (this->fileisempty)
	{
		cout << "文件不存在，或记录为空！" << endl;
	}
	//一上来就会调用析构函数，析构函数中有三个函数，m_Record里面就有内容了。
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届" << "冠军编号：" << this->m_Record[i][0] << "得分：" << this->m_Record[i][1] << " " << endl;
		cout << "第" << i + 1 << "届" << "亚军编号：" << this->m_Record[i][2] << "得分：" << this->m_Record[i][3] << " " << endl;
		cout << "第" << i + 1 << "届" << "季军编号：" << this->m_Record[i][4] << "得分：" << this->m_Record[i][5] << " " << endl;

	}
	system("pause");
	system("cls");
}

void SpeechManager::clearrecord()
{
	cout << "确认清空" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//ios::trunc就是找到了这个文件就把他删掉
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化容器
		this->initSpeech();
		//初始化12位选手，名字还有数字。放到V1和Map中
		this->createSpeaker();
		//加载往届记录
		this->loadrecord();

		cout << "清空成功！" << endl;
	}
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

SpeechManager::~SpeechManager()
{

}