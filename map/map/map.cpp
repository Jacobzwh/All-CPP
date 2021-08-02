#include<iostream>
#include<ctime>
#include<string>
#include<map>
using namespace std;
/*
void printmap(multimap<int, int, Mycompare>& n)
{
	for (map<int, int,Mycompare>::iterator it = n.begin(); it != n.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}*/
class Mycompare
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
void test01()
{
	multimap<int, int,Mycompare>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2,20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(7, 80));
	m.insert(pair<int, int>(6, 900));

	//printmap(m);
	for (map<int, int, Mycompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	
}
int main()
{
	test01();
}