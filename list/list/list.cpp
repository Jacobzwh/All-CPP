#include<iostream>
#include<ctime>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Employee";
		worker.m_Name += nameseed[i];
		worker.m_Salary = rand() % 100000 + 100000;
		v.push_back(worker);
	}

}
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptID = rand() % 3;
		m.insert(make_pair(deptID, (*it)));
	}
}
void shouworkerbygroup(multimap<int, Worker>& m)
{
	cout << "策划部门" << endl;
	multimap<int, Worker>::iterator pos = m.find(0);
	int count = m.count(0);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name" << pos->second.m_Name << "salary"<< pos->second.m_Salary <<endl;
	}
}
int main()
{
	multimap<int, Worker>mWorker;
	vector<Worker>v;
	createWorker(v);
	setGroup(v, mWorker);
	shouworkerbygroup(mWorker);
	system("pause");
	system("cls");
}