#include<iostream>
#include<ctime>
#include<string>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};
class VideoCard
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void memory() = 0;
};
//intel厂商
//
class intelcpu :public CPU
{
public:
	void calculate()
	{
		cout << "intel的cpu开始工作了" << endl;
	}
};
class intelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "intel的显卡开始工作了" << endl;
	}
};
class intelMemory :public Memory
{
public:
	void memory()
	{
		cout << "intel的存储器开始工作了" << endl;
	}
};

//Lenovo厂商
//
class lenovocpu :public CPU
{
public:
	void calculate()
	{
		cout << "intel的cpu开始工作了" << endl;
	}
};
class lenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "intel的显卡开始工作了" << endl;
	}
};
class lenovoMemory :public Memory
{
public:
	void memory()
	{
		cout << "intel的存储器开始工作了" << endl;
	}
};
//
//
class Computer
{
public:
	Computer(CPU& cpu, VideoCard& videocard, Memory& memory)
	{
		cpu.calculate();
		videocard.display();
		memory.memory();
	}
	/*
	Computer(CPU* cpu, VideoCard* videocard, Memory* memory)
	{
		m_CPU = cpu;
		m_Videocard = videocard;
		m_memory = memory;
	}

	
	void work()
	{
		m_CPU->calculate();
		m_Videocard->display();
		m_memory->memory();
	}
	

	CPU * m_CPU;
	VideoCard* m_Videocard;
	Memory* m_memory;*/
};

void test01()
{	/*
	CPU* intelCpu = new intelcpu;
	VideoCard* intelcard = new intelVideoCard;
	Memory* intelmemory = new intelMemory;
	Computer* computer1 = new Computer(intelCpu, intelcard, intelmemory);
	computer1->work();
	delete computer1;
	delete intelCpu;
	delete intelcard;
	delete intelmemory;*/
	intelcpu a;
	intelVideoCard b;
	intelMemory c;
	Computer(a, b, c);



}
int main()
{
	test01();


}