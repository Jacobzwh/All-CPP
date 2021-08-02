#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name=m_Name;
		this->m_Score=score;
	}

	string m_Name;
	int m_Score;
};
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name = +nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}
void setscore(vector<Person>& v)
{
	
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		cout << "选手" << (*it).m_Name<<"得分为:"<<endl;

		for (deque<int>::iterator did = d.begin(); did != d.end(); did++)
		{
			cout << (*did) << " " ;
		}
		cout << endl;

		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator did = d.begin(); did != d.end(); did++)
		{
			sum = sum + (*did);
		}
		int avg = sum / d.size();
		(*it).m_Score = avg;
	}
	


}
void showscore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手" << (*it).m_Name << "的最终平均分是：" << (*it).m_Score << endl;
	}
}
int main()
{
	vector<Person>v;
	createPerson(v);
	setscore(v);
	showscore(v);
	system("pause");
	system("cls");
}