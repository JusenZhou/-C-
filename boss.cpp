#include "boss.h"

//构造函数
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//构造函数

//显示个人信息，纯虚函数
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id << endl;
	cout << "职工姓名：" << this->m_Name << endl;
	cout << "职工岗位：" << this->getDeptName() << endl;//调用函数要加括号
	cout << "岗位职责：管理公司事务" << endl;
}

//获取岗位名称，纯虚函数
string Boss::getDeptName()
{
	return string("总裁");
}