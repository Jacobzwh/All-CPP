#include <iostream>
#include <ctime>
#include <string>
using namespace std;
//�������вκ����Ͳ�������޲κ����������˿��������Ͳ��������������������cpp��class��һ��ʼ����4������
class person
{
public:
	person()//�޲ι��캯��
	{
		cout << "���캯���ĵ���" << endl;
	}

	person(int age, int height)//�вι��캯��
	{
		
		cout << "�вι��캯���ĵ���" << endl;
		m_age = age;
		m_height = new int(height);
	}
	person(const person& p)//��дĬ�ϵĿ������캯������Ȼ���Զ��������еģ�һģһ���ı��ȥ
	{
		
		cout << "�������캯��" << endl;
		m_age = p.m_age;
		m_height = new int(*p.m_height);
	}
	~person()
	{
		cout << "person�����������ĵ���" << endl;
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





