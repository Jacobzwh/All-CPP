#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<fstream>
using namespace std;

class person
{
public:
	person(string name, int deptnum, int salary)
	{
		this->name = name;
		this->dept = deptnum;
		this->salary = salary;
	}

	string name;
	int dept;
	int salary;

};

class compareperson
{
public:
	bool operator()(const person& p1, const person& p2) const
	{
		return p1.salary > p2.salary;
	}

};

void test01()
{
	ifstream ifs;
	ifs.open("practice.txt", ios::in);
	string part_1, part_2, part_3, part_4, part_5,part_6;
	//int pos = info.find(",");
	//char ch[1024];
	//student:  A,   dept:  20,   salary:  1020
	set<person, compareperson> p_info;
	while (ifs >> part_1 &&  ifs>> part_2 && ifs>> part_3 && ifs>> part_4 && ifs>>part_5 && ifs>>part_6)
	{
		//cout << part_1 << endl;
		//cout << part_2 << endl;
		//cout << part_3 << endl;
		//cout << part_4 << endl;
		//cout << part_5 << endl;
		//cout<< part_6 << endl;
		int pos_1 = part_2.find(",");
		string student_name = part_2.substr(0, pos_1);
		//cout << student_name;

		int pos_2= part_4.find(",");
		string student_dept = part_4.substr(0, pos_2);
		int dept = atoi(student_dept.c_str());
		//cout << dept;

		string salary = part_6;
		int salary_1 = atoi(salary.c_str());

		person p(student_name, dept, salary_1);
		
		p_info.insert(p);

	}

	for (set<person, compareperson>::iterator it = p_info.begin(); it != p_info.end(); it++)
	{
		cout << "name:" << " " << it->name << " dept num: " << it->dept << " salary: " << it->salary << endl;
	}

}

int main()
{
	test01();
	system("pause");
	return 0;

}