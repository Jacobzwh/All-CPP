#include <iostream>
using namespace std;
#include <string>
#include <ctime>
#include "output arraty.h"
# define day 7

/*
void array_1(int arr1[])
{
	int temp;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8 - i; j++)
		{
			if (arr1[j + 1] < arr1[j])
			{
				temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;

			}

		}

	}


	for (int j = 0; j < 9; j++)
	{
		cout << arr1[j] << endl;
	}

}
*/
/*
void bubble_sort(int* p, int length)
{
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (*(p+1+j) < *(p+j))
			{
				temp = *(p+j);
				*(p+j) = *(p+1+j);
				*(p+1+j) = temp;
			}
		}

	}

}

*/
struct student
{
	string name; 
	int age;
	int score;
};

int main()
{	
	student s1;
	s1.name = "San Zhang";
	s1.age = 18;
	s1.score = 88;

	student* p1 = &s1;
	cout << (*p1).name << endl;
	cout << p1->age << endl;
	/*
	int arr[]={ 4,3,6,9,1,2,10,8,7,5 };
	bubble_sort(&arr[0], 10);
	for (int k = 0; k < 10; k++)
	{
		cout << arr[k] << endl;
	}
	*/
	/*
	int arr[3][3] = { {4,2,8},{0,5,9},{1,3,7} };
	array_1(arr);*/
	/*
	string str = "hello";
	cout << "please change the word hello into world" << endl;
	cin >> str;
	cout << "the string now is :    " << str << endl;

	*/
	/*
	char ch = 'a';
	cout << "original alphabet is a" << endl;
	cin  >>  ch;
	cout << "and now the alphabet is : " << ch << endl;
	*/
	/*
	float variable_1 = 3.14f;
	cout << "please input the other value: " << endl;
	cin >> variable_1;
	cout << "and now the value is : " << variable_1 << endl;
	*/
	/*
	int pig_1, pig_2, pig_3;
	cout << "please input the value of the first pig: " << endl;
	cin >> pig_1;
	cout << "please input the value of the second pig: " << endl;
	cin >> pig_2;
	cout << "please input the value of the third pig: " << endl;
	cin >> pig_3;

	if (pig_1 > pig_2)//
		{
		if (pig_1 > pig_3)
			cout << "the heaviest pig is pig_1 :  " << pig_1 << endl;
		else if (pig_1 < pig_3)
			cout << "the heaviest pig is pig_3 :  " << pig_3 << endl;
		else
			cout << "the heaviest pig is pig_1 and pig_3: " << pig_3 << endl;
		}
	else if (pig_1 < pig_2)
		{
		if (pig_2 > pig_3)
			cout << "the heaviest pig is pig_2 :  " << pig_2 << endl;
		else if (pig_2 < pig_3)
			cout << "the heaviest pig is pig_3 :  " << pig_3 << endl;
		else
			cout << "the heaviest pig is pig_2 and pig_3: " << pig_3 << endl;
		}
	else
		{
		if (pig_2 > pig_3)
			cout << "the heaviest pig is pig_1 and pig_2 :  " << pig_2 << endl;
		else if (pig_2 < pig_3)
			cout << "the heaviest pig is pig_3 :  " << pig_3 << endl;
		else
			cout << "the heaviest pig is pig_1, pig_2 and pig_3: " << pig_3 << endl;
		}
		*/
	/*
	char ch;
	cout << "please input the alphabet to choose: " << endl;
	cin >> ch;
	//char a, b, c, d;
	switch (ch)
	{
		case 'a' : cout << "alphabet is a"; break;
		case 'b': cout << "alphabet is b"; break;
		case 'c': cout << "alphabet is c"; break;
		case 'd': cout << "alphabet is d"; break;
		default: cout << "alphabet is nothing"; break;
	

	
	}
	*/
	/*
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int input_num;
	while (1)
	{
		cin >> input_num;
		if (input_num > num)
			cout << "Too Big" << endl;
		else if (input_num < num)
			cout << "Too small" << endl;
		else {
			cout << "Congrats!, you guess the true answer" << endl;
			break;
		}

	}
	*/
	/*
	int num = 0;
	while (num < 10)
	{
		cout << num << endl;
		num = num + 1;
	
	}
	*/
	//水仙花
	/*
	int num = 0;
	int a, b, c;
	do {
		a = (num)/100;
		b = (num-a*100)/10;
		c = (num-(a*100)-(b*10));
		if ((a * a * a + b * b * b + c * c * c) == num)
		{
			cout << "the number is : " << num << endl;
		}
	
		num ++;
	} while (num < 1000);
	*/
/*
	for (int i = 1; i <=100; i++)
	{
		if (i / 10 == 7 || i % 7 == 0 || (i - ((i) / 10) * 10)==7)
			cout << "knock the desk" << endl;
		else
			cout << "the number is: " << i << endl;

	}
		*/
	/*
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j = j + 1)
		{
			cout << "* ";
		}
		cout << endl;
	}
	*/
	/*
	for (int i = 1; i < 10; i = i + 1)
	{
		for (int k = 1; k <= i; k = k + 1)
		{
			cout << i<< "*" << k << "=" << k * i<<" " ;
		}
		cout << endl;

	}
	*/
/*
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			
		}
		else
		cout << "number is : " << i << endl;

	}
	*/
/*
	cout << "1" << endl;
	cout << "2" << endl;
	cout << "3" << endl;
	cout << "4" << endl;
	goto ABC;
	cout << "5" << endl;
	cout << "6" << endl;
	ABC :
	cout << "11" << endl;
	cout << "12" << endl;
    */
	/*
	float arr[] = { 10,20,30,40,50,60 };
	cout << "Total size of the array: " << sizeof(arr) << endl;
	cout << "The size of one element: " << sizeof(arr[0]) << endl;
	cout << "The numnber of element is: " << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "The location of first element" << arr << endl;
	cout << "The location of first element" << (int)&arr[0] << endl;
	cout << "The location of second element" << (int)& arr[1] << endl;
	*/
/*
int arr[] = { 100,200,350,302,301 };
int max = 0;
for (int i = 0; i < 5; i++)
{
	if (arr[i] > max)
		max = arr[i];

}
	
cout << "the max number is: " << max << endl;
*/
/*
int arr[] = { 100,200,350,302,301 };
int start = 0;
int temp;
int end = (sizeof(arr)/sizeof(arr[0]))-1;
for (int i = 0; i < 5; i++)
{
	if (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
for (int j = 0; j < 5; j++)
{
	cout << arr[j] << endl;


}
	*/
	///bubble sort
/*
int arr[] ={ 4,2,8,0,5,9,1,3,7 };
int temp;
for (int i = 0; i < 8; i++)
{
	for (int j = 0; j < 8-i; j++)
	{
		if (arr[j + 1] < arr[j])
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;

		}

	}

}


for (int j = 0; j < 9; j++) 
	{
	cout << arr[j] << endl;
	}
	*/
/*
int arr[3][3] = { {100,100,100},{90,50,100},{60,70,80} };
int result[3] = {0,0,0};
string name[3] = { "张三","李四","王五" };
for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++) 
		{
		result[i] = result[i] + arr[i][j];
	


		}

}
for (int k = 0; k < 3; k++)
{
	cout << name[k]<<"的分数为： "<<result[k] << endl;

}
*/

	


	system("pause");
	return 0;





}