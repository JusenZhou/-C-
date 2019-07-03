#include <iostream>
#include "workManager.h"
#include "employee.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"
using namespace std;
int main()
{

	//实例化一个管理者的对象
	WorkManager wm;
	int choice = 0;
	while (true)
	{
		//调用展示菜单成员函数
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;//接受用户的选项。
		switch (choice)
		{
		case 0://退出管理系统
			wm.exitSystem();
			break;
		case 1://增加员工信息
			wm.Add_Emp();
			break;
		case 2://显示员工信息
			wm.Show_Emp();
			break;
		case 3://删除离职员工
		/*
		测试
		{
			int ret = wm.IsExist(1);
			if (ret != -1)
			{
				cout << "职工存在" << endl;
			}
			else
			{
				cout << "职工不存在" << endl;
			}
			break; 
		}*/
			wm.Del_Emp();
			break;
		case 4://修改员工信息
			wm.Mod_Emp();
			break;
		case 5://查找员工信息
			wm.Find_Emp();
			break;
		case 6://按照编号排序
			wm.Sort_Emp();
			break;
		default:
			system("cls");//清屏
				break;
		}
	}

	system("pause");
	return 0;
}