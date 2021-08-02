#include<iostream>

#include<string>
using namespace std;

#include <set>

class person
{
public:
	person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;

};

class compareperson
{
public:
	bool operator()(const person& p1, const person& p2) const
	{
		return p1.m_Age > p2.m_Age;
	}
};

void test01()
{
	set<person, compareperson> s1;
	person p1("����", 23);
	person p2("����", 27);
	person p3("�ŷ�", 25);
	person p4("����", 21);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<person, compareperson>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}