#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//�ϰ���
class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);

	//��ʾ������Ϣ�����麯��
	virtual void showInfo();

	//��ȡ��λ���ƣ����麯��
	virtual string getDeptName();

};
