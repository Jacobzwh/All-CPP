#include<iostream>
#include<ctime>
#include<string>
#include<vector>
using namespace std;
void printvector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it)<<" ";
	}
	cout << endl;
}
void test01()
{
	// initialize
	vector<int> v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(i);
	}
	printvector(v);
	//copy value
	vector<int> v2;
	v2 = v;
	printvector(v2);
	//empty capacity size resize
	/*
	cout << v2.empty() << endl;
	cout << v2.capacity() << endl;
	cout << v2.size() << endl;
	v2.resize(25, 10);
	printvector(v2);
	v2.resize(5);
	printvector(v2);*/
	v2.pop_back();
	//vector<int> ::iterator address = v.begin();
	//address++;
	//address++;
	v2.insert(v2.begin()+2, 2, 1000);
	printvector(v2);
	v2.erase(v2.begin()+1, v2.end()-2);
	printvector(v2);
	cout << v2.front() << endl;
	cout << v2.back() << endl;
	cout << v2[1] << endl;

}
int main()
{
	test01();
	
	cout << endl;
} 