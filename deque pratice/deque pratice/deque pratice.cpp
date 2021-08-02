#include <deque>
#include <string>
using namespace std;
#include<iostream>

void printDeque( deque<int> &d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";

	}
	cout << endl;
}
//Á½¶Ë²Ù×÷
void test01()
{
	deque<int> d;
	//Î²²å
	d.push_back(10);
	d.push_back(20);
	//Í·²å
	d.push_front(100);
	d.push_front(200);

	printDeque(d);

	//Î²É¾
	d.pop_back();
	//Í·É¾
	d.pop_front();
	printDeque(d);
}

//²åÈë
void test02()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	//deque<int>::iterator v_top = d.begin();
	

	d.insert(d.begin(), 1000);
	printDeque(d);

	d.insert(d.begin()+3, 2, 10000);
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin()+1, d2.begin(), d2.end());
	printDeque(d);

}

//É¾³ý
void test03()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	d.push_back(50);
	d.push_back(60);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	d.push_front(400);
	printDeque(d);

	d.erase(d.begin()+3);
	printDeque(d);

	d.erase(d.begin()+2, d.end()-3);
	//d.clear();
	printDeque(d);
}

int main() {

	test01();

	test02();

	test03();

	system("pause");

	return 0;
}
