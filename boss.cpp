#include "boss.h"

//���캯��
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//���캯��

//��ʾ������Ϣ�����麯��
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id << endl;
	cout << "ְ��������" << this->m_Name << endl;
	cout << "ְ����λ��" << this->getDeptName() << endl;//���ú���Ҫ������
	cout << "��λְ�𣺹���˾����" << endl;
}

//��ȡ��λ���ƣ����麯��
string Boss::getDeptName()
{
	return string("�ܲ�");
}