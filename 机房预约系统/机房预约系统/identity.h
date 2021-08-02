#pragma once
#include<iostream>
using namespace std;

class Identity
{
public:
	virtual void openmenu()=0;//子类必须重写父类的纯虚函数, 记得要写上=0

	string m_Name;//	用户名
	string m_Pwd;//		密码
};