//��ͨԱ���ļ�
#pragma once
#include<iostream>
#include "worker.h"
using namespace std;


class Employee:public Worker

{
public:
	Employee(int id,string name,int dId);//���캯��

	//��ʾ������Ϣ�����麯��
	virtual void showInfo();

	//��ȡ��λ���ƣ����麯��
	virtual string getDeptName();
};