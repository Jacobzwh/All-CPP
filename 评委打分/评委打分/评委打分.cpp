#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

class person
{
public:
	person(string name, double score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	double m_Score;

};

void createperson(vector<person> &v)
{
	string nameseed = "ABCDEFGHIJ";
	string name;
	for (int i = 0; i < 10; i++)
	{
		name = "Student: ";
		name += nameseed[i];
		person p(name, 0.0);
		v.push_back(p);

	}
}

void getscore(vector<person>& v)
{
	int time = 0;
	for (vector<person>::iterator it = v.begin() ;it != v.end(); it++)
	{
		

		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = rand() % 41 + 60.0;
			d.push_back(score);
		}

		sort(d.begin(),d.end());
		d.pop_front();
		d.pop_back();

		double sum=0.0;
		for (int j = 0; j < d.size(); j++)
		{
			sum = sum + d[j];
		}

		v[time].m_Score = sum / 8;
		time++;
	}
}

void showperson(vector<person>& v)
{
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->m_Name << " Score: " << it->m_Score << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	
	vector<person> v1;
	 

	createperson(v1);
	getscore(v1);
	showperson(v1);

	system("pause");
	return 0;
}