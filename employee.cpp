#include "employee.h"

//���캯��
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//���캯��

//��ʾ������Ϣ�����麯��
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id << endl;
	cout << "ְ��������" << this->m_Name << endl;
	cout << "ְ����λ��" << this->getDeptName()<< endl;//���ú���Ҫ������
	cout << "��λְ����ɾ�����������" << endl;
}

//��ȡ��λ���ƣ����麯��
string Employee::getDeptName()
{
	return string("Ա��");
}