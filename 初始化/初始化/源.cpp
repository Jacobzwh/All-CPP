#include <iostream>
#include <ctime>
#include <string>
using namespace std;
/*
class Person
{
public:
		Person(int a, int b, int c)
	{
			m_a = a;
			m_b = b;
			m_c = c;
	}
		void printinfo()
		{
			cout << m_a << endl;
			cout << m_b << endl;
			cout << m_c << endl;
		}

private:
	int m_a;
	int m_b;
	int m_c;
};

int main()
{
	Person p(10, 20, 390);
	p.printinfo();
}*/
/////////
// ////
//this is the constructor of different cases
///////
//////
/*
class Phone
{
public:
	Phone()
	{}
	Phone(string name, int b)
	{
		m_Phonename = name;
		age = b;
		cout << "phone create" << endl;
	}

	~Phone()
	{
		cout << "xigou" << endl;
	}
	string m_Phonename;
	int age;
};

class Person
{
public:
	Person(string name, string pName, int b):m_Name(name),m_Phone(pName,b)
	{
		cout << "Person gouzao" << endl;
		//m_Name = name;
		//m_Phone= pName;
		//m_Phone = b;
	}
	~Person()
	{
		cout << "Person xigou" << endl;
	}
	void playgame()
	{
		cout<<m_Phone.m_Phonename<<endl;//类中的变量用点来访问就可以了
	}
	string m_Name;
	Phone m_Phone;
};

int main()
{
	Person p("ZhangSan","AppleX",20);
	p.playgame();
	system("pause");
	return 0;
}
*/
//The information of student
/*
class student
{
public:
	student();
	student(int a, string b) :num(a), name(b) {}
	void stduent_display();

protected:
	int num;
	string name;
};

void student::stduent_display()
{
	cout << "The name is" << name << "and the num is" << num << endl;
}
// The information of teacher
class teacher: public student
{
public:
	friend void parent::display();
	teacher();
	teacher(int a, string b, int c) :student(a, b), age(c) {}

private:
	int age;
};

class parent:public teacher
{
public:
	parent(int a, string b,int c, string d, int f) :marry_year(a), addr(b),teacher(c,d,f) {}
	void display()
	{
		cout << num << endl;
		cout << name << endl;
		cout << age << endl;
		cout << marry_year << endl;
		cout << addr << endl;
	}
public:
		int marry_year;
		string addr;
};

void test01()
{
	parent a(32, "haha", 12, "tyty", 98);


int main()
{
	test01()

}
*/
class student
{
public:
	student();
	student(int a, string b) :age(a), name(b) {}
	void display()
	{
		cout << "The student name is" << name << "The age of the student is" << age << endl;
	}

public:
	int age;
	string name;

};
//子类调用父类的构造函数
class monitor:public student
{
public:
	monitor(int a, string b, string c) :student(a,b), addr(c) {}
	
	

public:
	string addr;
};

void test01()
{
	monitor c(23, "ziwei", "Yannan Road");
	c.display();
}
int main()
{
	test01();
	system("pause");
	return 0;
}