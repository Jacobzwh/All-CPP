#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
class cube
{
public:
	void set_length(float L)
	{
		length = L;
	}
	void set_width(float W)
	{
		width = W;
	}
	void set_height(float H)
	{
		height = H;
	}
	float get_length()
	{
		return length;
	}
	float get_width()
	{
		return width;
	}
	float get_height()
	{
		return height;
	}
	float square()
	{
		return 2 * (length * width + width * height + length * height);
	}
	float volume()
	{
		return (length * width * height);
	}
	bool compare(cube& a)
	{
		float b = volume();
		if (b == a.volume())
			return true;
		else
			return false;
	}
private:
	float length;
	float width;
	float height;

};
void compare_result(cube& a, cube& b)
{
	if (a.volume() == b.volume())
		cout << "Same" << endl;
	else
		cout << "Different" << endl;
}


int main()
{
	cube a, b;
	b.set_height(10);
	b.set_width(10);
	b.set_length(10);
	a.set_height(10);
	a.set_width(10);
	a.set_length(10);
	//cout << a.compare(b) << endl;
	compare_result(a, b);

}*/

struct cube 
{
	float length, width, height;

	float volume()
	{
		return length * width * height;
	}

	bool compare(cube a)
	{
		if (volume() == a.volume())
			return true;
		else
			return false;

	}

};

void change(cube c[], cube d[])
{
	c[0].height = 20;
	d[1].length = 30;
}
int main()
{
	cube a[2], b[2];
	for (int i = 0; i < 2; i++)
	{
		a[i].length = 10;
		a[i].width = 10;
		a[i].height = 10;
		b[i].length = 10;
		b[i].width = 10;
		b[i].height = 10;
	}
	

	change(a, b);
	//change(&a, &b);
	cout << a[0].height << endl;
	cout << b[1].length << endl;

}