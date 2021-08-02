#include <iostream>
#include <ctime>
#include <string>
using namespace std;
//调用了有参函数就不会调用无参函数，调用了拷贝函数就不会调用另外两个函数。cpp的class类一开始就有4个函数
class person
{
public:
	person()//无参构造函数
	{
		cout << "构造函数的调用" << endl;
	}

	person(int age, int height)//有参构造函数
	{
		
		cout << "有参构造函数的调用" << endl;
		m_age = age;
		m_height = new int(height);
	}
	person(const person& p)//重写默认的拷贝构造函数，不然会自动拷贝所有的，一模一样的变过去
	{
		
		cout << "拷贝构造函数" << endl;
		m_age = p.m_age;
		m_height = new int(*p.m_height);
	}
	~person()
	{
		cout << "person的析构函数的调用" << endl;
		if (m_height != NULL)
		{
			delete m_height;
		}
	}

//private:
	int m_age;
	int * m_height;
};

int main()
{
	person p1(18, 180);
	person p2(p1);
	//person p3(p2);
	//cout << p2.age << endl;
	//cout << p3.age << endl;
	system("pause");
	return 0;
	
}





