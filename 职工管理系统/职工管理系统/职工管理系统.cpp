#include<iostream>
#include<ctime>
#include<string>
#include<fstream>
#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"worker.h"
#include"boss.h"

using namespace std;

int main()
{
	WorkerManager wm;
	int choice;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选项" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:wm.exit_system(); break;
		case 1:wm.Add_Emp(); break;
		case 2:wm.show_emp(); break;
		case 3:wm.del_emp(); break;
		case 4:wm.mod_emp(); break;
		case 5:wm.Find_emp(); break;
		case 6:wm.sort_emp(); break;
		case 7: break;
		default:
			system("cls");
			break;
		}

	}
	
	system("pause");
	return 0;
}
