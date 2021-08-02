#include<iostream>
#include<ctime>
#include<string>
#include<deque>
#include <algorithm>
using namespace std;

void printdeque(deque<int>& v)
{
	for (deque<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
void test01()
{
	deque<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printdeque(v1);
	deque<int>v2;
	v2 = v1;
	printdeque(v2);
	v2.assign(v1.begin() + 2, v1.end() - 1);
	printdeque(v2);
	cout << v2.empty() << endl;
	cout << v2.size() << endl;
	v2.resize(15, 2);
	printdeque(v2);
	v2.resize(5);
	printdeque(v2);
}*/
void test01()
{
	deque<int>d;
	d.push_back(10);
	d.push_back(30);
	d.push_back(30);
	d.push_back(50);
	d.push_back(40);
	printdeque(d);
	sort(d.begin(), d.end());
	printdeque(d);

}
int main()
{
	test01();
	system("pause");
	system("cls");
}