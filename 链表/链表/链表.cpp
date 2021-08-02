#include<iostream>
#include<ctime>
#include<string>
using namespace std;
typedef struct node
{
	char name[20];
	int age;
	struct node* next;

}student;
student* CreateNode(int n)
{
	student* head = new student;
	student* pre = head;
	for (int i = 0; i < n; i++)
	{
		student* p = new student;
		cout << "Please Input the "<<i<< " Name" << endl;
		cin >> p->name;
		cout << "Please Input the "<<i<< " Age" << endl;
		cin >> p->age;
		pre->next = p;
		pre = p;
		p->next = NULL;
	}
	return head;
}
void display(student* m_head)
{
	student* p = m_head->next;
	while (p!=NULL)
	{
		cout << p->name << " " << p->age << endl;
		p=p->next;
	}
}
int length(student* head)
{
	int count = 0;
	student* p = head->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
}
void insertelement(student* head, int index)
{
	if (index<0 || index>=length(head))
	{
		cout << "out of range" << endl;
	}
	student* pre = head;
	for (int i = 0; i < index; i++)
	{
		pre = pre->next;
	}
	student* new_student = new student;
	cout << "Please Input the New Name" << endl;
	cin >> new_student->name;
	cout << "Please Input the New Age" << endl;
	cin >> new_student->age;

}
int main()
{
	student*head=CreateNode(1);
	display(head);
	length(head);
	system("pause");
	return 0;
}