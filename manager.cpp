#include "manager.h"

//���캯��
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//���캯��

//��ʾ������Ϣ�����麯��
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id << endl;
	cout << "ְ��������" << this->m_Name << endl;
	cout << "ְ����λ��" << this->getDeptName() << endl;//���ú���Ҫ������
	cout << "��λְ������ϰ彻�������񣬲��������·���Ա��" << endl;
}

//��ȡ��λ���ƣ����麯��
string Manager::getDeptName()
{
	return string("����");
}