#include <iostream>
#include "workManager.h"
#include "employee.h"
#include "worker.h"
#include "boss.h"
#include "manager.h"
using namespace std;
int main()
{

	//ʵ����һ�������ߵĶ���
	WorkManager wm;
	int choice = 0;
	while (true)
	{
		//����չʾ�˵���Ա����
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;//�����û���ѡ�
		switch (choice)
		{
		case 0://�˳�����ϵͳ
			wm.exitSystem();
			break;
		case 1://����Ա����Ϣ
			wm.Add_Emp();
			break;
		case 2://��ʾԱ����Ϣ
			wm.Show_Emp();
			break;
		case 3://ɾ����ְԱ��
		/*
		����
		{
			int ret = wm.IsExist(1);
			if (ret != -1)
			{
				cout << "ְ������" << endl;
			}
			else
			{
				cout << "ְ��������" << endl;
			}
			break; 
		}*/
			wm.Del_Emp();
			break;
		case 4://�޸�Ա����Ϣ
			wm.Mod_Emp();
			break;
		case 5://����Ա����Ϣ
			wm.Find_Emp();
			break;
		case 6://���ձ������
			wm.Sort_Emp();
			break;
		default:
			system("cls");//����
				break;
		}
	}

	system("pause");
	return 0;
}