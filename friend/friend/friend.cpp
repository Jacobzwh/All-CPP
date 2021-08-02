#include <iostream>
#include <ctime>
#include <string>
using namespace std;


class Building
{
	friend void goodgay(Building* building);
public:
	
	Building()
	{
		m_Sittingroom = "¿ÍÌü";
		m_Bedroom = "ÎÔÊÒ";
	}

public:
	string m_Sittingroom;
private:
	string m_Bedroom;

};

void goodgay(Building* building)
{
	cout << "my friend is in "<< building->m_Sittingroom<<endl;
	cout << "my friend is in " << building->m_Bedroom << endl;
}

int main()
{
	Building p;
	goodgay(&p);


}