#include<iostream>
#include <string>
#include <ctime>
using namespace std;
//传递数组就是传递数组首地址？？，试一下一维数组和二维数组，C++ 传数组给一个函数，数组类型自动转换为指针类型，因而传的实际是地址。
/*
struct student
{
	string name;
	int score;
};

struct teacher
{

	string name;
	student S[5];

};
void allocatespace(teacher array_1[], int len)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 3; i++)
	{
		array_1[i].name = "Teacher_";
		array_1[i].name += nameseed[i];


		for (int j = 0; j < 5; j++)
		{
			int random = rand()%61+40;
			array_1[i].S[j].name = "Student_";
			array_1[i].S[j].name += nameseed[j];
			array_1[i].S[j].score = random;
		}
	}
};

void printresult(teacher array_1[], int len)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 3; i++)
	{
		cout << array_1[i].name<<endl;
		for (int j = 0; j < 5; j++)
		{
			cout<< "      "<<array_1[i].S[j].name << "     "<<array_1[i].S[j].score<<endl;
			
		}
	}

};
int main()
{
	srand((unsigned)time(NULL));
	teacher T[3];
	int len = sizeof(T) / sizeof(T[0]);
	allocatespace(T, len);
	printresult(T, len);

	system("pause");
	return 0;
}
*/
/*
void modified(int array_1[][3])
{
	array_1[2][2] = 12;

}

int main()
{

	int p[][3] = { {3,4,5},{6,7,8},{9,0,0 } };
	modified(p);
	cout << "  " << p[0][0] << "   " << p[2][2] << endl;
	system("pause");
	return 0;
}*/

struct hero
{
	string name;
	int age;
	string sex;
};
void give_name(hero array_1[])
{
	string nameseed[5] = {"张飞","赵云","刘备","貂蝉","关羽" };
	int ageseed[5] = { 20,21,23,19,22 };
	string sexseed[5] = { "男","男" ,"男","女","男"};
	for(int i = 0; i < 5; i++)
	{
		array_1[i].name = nameseed[i];
		array_1[i].age = ageseed[i];
		array_1[i].sex = sexseed[i];
	
	};

}
void sort_age(hero array_1[])
{
	hero temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (array_1[j].age > array_1[j + 1].age)
			{
				temp = array_1[j];
				array_1[j] = array_1[j+1];
				array_1[j + 1] = temp;
			}
		}
	}

}
void print_info(hero array_1[])
{
	for (int i = 4; i >= 0; i--)
	{
		cout << array_1[i].name << " " << array_1[i].age << " " << array_1[i].sex << endl;
		if (i == 0)
			break;
	}

	
		
}
int main()
{
	hero brother[5];
	give_name(brother);
	sort_age(brother);
	print_info(brother);
	system("pause");
	return 0;
}