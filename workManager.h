#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流的文件
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;//使用标准的命名空间

class WorkManager
{

public:
		WorkManager();//构造函数

		void Show_Menu();//展示菜单的函数

		void exitSystem();//退出系统

		int m_EmpNum;//记录职工人数

		Worker ** m_EmpArray;//职工数组的指针

		void Add_Emp();//添加职工函数

		void save();//保存文件

		bool m_FileIsEmpty;//判断文件是否为空

		int get_EmpNum();//统计文件中的人数

		void init_Emp();//初始化员工

		void Show_Emp();//显示职工信息

		void Del_Emp();//删除职工信息

		int IsExist(int id);//用于判断职工是否存在，如果存在则返回职工所在数组中的位置，不存在返回-1

		void Mod_Emp();//修改职工

		void Find_Emp();//查找职工

		void Sort_Emp();//职工排序

		//析构函数
		~WorkManager();
};