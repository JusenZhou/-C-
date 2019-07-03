//普通员工文件
#pragma once
#include<iostream>
#include "worker.h"
using namespace std;


class Employee:public Worker

{
public:
	Employee(int id,string name,int dId);//构造函数

	//显示个人信息，纯虚函数
	virtual void showInfo();

	//获取岗位名称，纯虚函数
	virtual string getDeptName();
};