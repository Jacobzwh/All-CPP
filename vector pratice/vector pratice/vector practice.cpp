#include <vector>
#include <string>
using namespace std;
#include<iostream>

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//≤Â»Î∫Õ…æ≥˝
void test01()
{
	vector<int> v1;
	//Œ≤≤Â
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	v1.push_back(90);
	v1.push_back(100);

	printVector(v1);
	//Œ≤…æ
	v1.pop_back();
	printVector(v1);//10 20 30 40
	//≤Â»Î
	vector<int> ::iterator v_top = v1.begin();
	vector<int> ::iterator v_end = v1.end();
	for (int i = 0; i < 3; i++)
	{
		++v_top;
	}
	//v_end--;
	v1.insert(v_top, 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//…æ≥˝
	v1.erase(v1.begin());
	printVector(v1);

	//«Âø’

	v1.erase(v_top, --v1.end());
	//v1.clear();
	printVector(v1);
}

int main() {

	test01();

	system("pause");

	return 0;
}