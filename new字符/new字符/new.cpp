#include <iostream>
#include <ctime>
#include <string>
using namespace std;
/*
int* func()
{
	int* p = new int(10);//p中的内容是堆区的一个地址
	return p;
}

void printfunc()
{
	int* p = func();
	cout << "*p" << endl;
	cout << "*p" << endl;
	cout << "*p" << endl;
	cout << "*p" << endl;
	delete p;//把P中得内容删掉，p的内容就是一个地址，释放掉堆区的那块东西。
	//删除完毕函数执行完成，给p分配在栈区的东西释放掉了，这个是有编译器来申请的

}
*/
/*
int & test02()
{
	static int a = 10;
	return a;
}*/
/*
void modified ( int&val)
{
	val = 7;
}*/
int main()
{/*
	int& ref = test02();
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;
	cout << ref << endl;

	int a = 10;
	modified(a);
	cout << a << endl; 
	*/
}