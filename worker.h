#pragma once
#include <iostream>
#include <string>
using namespace std;

//ְ���������
class Worker
{
public:

	//��ʾ������Ϣ�����麯��
	virtual void showInfo() = 0;

	//��ȡ��λ���ƣ����麯��
	virtual string getDeptName() = 0;

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ������Ʊ��
};
