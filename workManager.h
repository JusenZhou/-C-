#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//����������������ļ�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;//ʹ�ñ�׼�������ռ�

class WorkManager
{

public:
		WorkManager();//���캯��

		void Show_Menu();//չʾ�˵��ĺ���

		void exitSystem();//�˳�ϵͳ

		int m_EmpNum;//��¼ְ������

		Worker ** m_EmpArray;//ְ�������ָ��

		void Add_Emp();//���ְ������

		void save();//�����ļ�

		bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

		int get_EmpNum();//ͳ���ļ��е�����

		void init_Emp();//��ʼ��Ա��

		void Show_Emp();//��ʾְ����Ϣ

		void Del_Emp();//ɾ��ְ����Ϣ

		int IsExist(int id);//�����ж�ְ���Ƿ���ڣ���������򷵻�ְ�����������е�λ�ã������ڷ���-1

		void Mod_Emp();//�޸�ְ��

		void Find_Emp();//����ְ��

		void Sort_Emp();//ְ������

		//��������
		~WorkManager();
};