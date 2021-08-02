#include<iostream>
#include<ctime>
#include<string>
using namespace std;

class abstractdrink
{
public:
	virtual void cup() = 0;
	virtual void material() = 0;
	virtual void maker() = 0;
	virtual void time() = 0;
};

class coffee :public abstractdrink
{
public:
	void cup()
	{
		cout << "big cup" << endl;
	}
	void material()
	{
		cout << "milk" << endl;
	}
	void maker()
	{
		cout << "me" << endl;
	}
	void time()
	{
		cout << "10 minutes" << endl;
	}
};
void test01()
{
	abstractdrink* d = new coffee;
	d->cup();
	d->maker();
	d->material();
	d->time();
	delete d;
}
int main()
{
	test01();
}