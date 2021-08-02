#pragma once
#include <iostream>
#include<fstream>
using namespace std;
#include<map>
#include"globalFile.h"

class OrderFile
{
public:
	//构造函数
	OrderFile();
	//更新预约记录
	void updateOrder();
	//key：记录的条数， value:
	map<int, map<string, string>> m_orderData;
	//预约记录条数
	int  m_Size;

};