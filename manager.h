#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//经理类
class Manager:public Worker
{
public:
	Manager(int id ,string name,int dId);

	//显示个人信息，纯虚函数
	virtual void showInfo();

	//获取岗位名称，纯虚函数
	virtual string getDeptName();

};
