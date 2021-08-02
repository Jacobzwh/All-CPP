#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal 构造函数的使用" << endl;
	}

	virtual void speak()
	{}

	virtual ~Animal() = 0;
};

Animal::~Animal()
{
	cout << "Animal 纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_Name = new string(name);
	}
	void speak()
	{
		cout << *m_Name << "小猫在说话"<<endl;
	}
	~Cat()
	{
		cout << "Cat析构函数调用" << endl;
		if (this->m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name;

};

int main()
{


}