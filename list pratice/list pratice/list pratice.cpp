#include<iostream>
#include<string>
#include<ctime>
#include<list>
using namespace std;

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

class Person {
public:
	Person(string name, int age, int height) {
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

public:
	string m_Name;  //����
	int m_Age;      //����
	int m_Height;   //����
};

bool ComparePerson(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return  p1.m_Age < p2.m_Age;
	}

}
void test01() {

	list<Person> L;

	Person p1("����", 35, 175);
	Person p2("�ܲ�", 45, 180);
	Person p3("��Ȩ", 40, 170);
	Person p4("����", 25, 190);
	Person p5("�ŷ�", 35, 160);
	Person p6("����", 35, 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
			<< " ���ߣ� " << it->m_Height << endl;
	}

	cout << "---------------------------------" << endl;
	L.sort(ComparePerson); //����

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
			<< " ���ߣ� " << it->m_Height << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}