#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		cout << "有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
		
	}
	//operator 
	MyArray& operator=(const MyArray& arr)
	{
		cout << "operator调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//
	MyArray(const MyArray& arr)
	{
		cout << "拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}

	}
	~MyArray()
	{
		cout << "析构函数的调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;// T contain the address of the array of the heap area
	int m_Capacity;
	int m_Size;
};