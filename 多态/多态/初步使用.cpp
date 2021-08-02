#include <iostream>
#include <ctime>
#include <string>
using namespace std;
//多态重写主函数,父类的引用
/*
class Animal 
{
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};
class cat :public Animal
{
public:
	void speak()
	{
		cout << "cat is talking now" << endl;
	}

};
class dog :public Animal
{
public:
	void speak()
	{
		cout << "dog is talking now" << endl;
	}
};
void dospeak(Animal& animal)
{
	animal.speak();
}
int main()
{
	cat a;
	dospeak(a);
	system("pause");
	return 0;

}
*/
//父类的指针
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

class AddCalculator : public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
		 
};

class SubCaculator : public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

class MulCaculator : public AbstractCalculator
{
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};
void test01(AbstractCalculator & calculator)
{
	calculator.m_Num1 = 10;
	calculator.m_Num2 = 1;
	cout << calculator.getResult() << endl;
}

int main()
{	//father * a = new son
	//a  
	//SubCaculator a;
	//test01(a);
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 19;
	abc->m_Num2 = 20;
	cout << abc->getResult() << endl;
	//delete abc;

	system("pause");
	return 0;
}