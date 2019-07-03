//ְ��������
#include "workManager.h"

WorkManager::WorkManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		//��ʼ������
		this->m_EmpNum = 0;//��ʼ������Ϊ0
		this->m_EmpArray = NULL;//��ʼ������ָ��Ϊ��
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;//�ļ�Ϊ��
		this->m_EmpNum = 0;//��ʼ������Ϊ0
		this->m_EmpArray = NULL;//��ʼ������ָ��Ϊ��
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ�����¼����
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	
	
	this->m_EmpArray = new Worker*[this->m_EmpNum];//����
	this->init_Emp();//�ļ��е����ݣ��浽������

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "��ţ�" << this->m_EmpArray[i]->m_Id
			 << "������" << this->m_EmpArray[i]->m_Name
			 << "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}

void WorkManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "**��ӭʹ��Ա������ϵͳ��**" << endl;
	cout << "******0.�˳�����ϵͳ******" << endl;
	cout << "******1.����Ա����Ϣ******" << endl;
	cout << "******2.��ʾԱ����Ϣ******" << endl;
	cout << "******3.ɾ����ְԱ��******" << endl;
	cout << "******4.�޸�Ա����Ϣ******" << endl;
	cout << "******5.����Ա����Ϣ******" << endl;
	cout << "******6.���ձ������******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);//�˳�����
}

void WorkManager::Add_Emp()//���ְ������
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;//��¼�����û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		//ִ�о������
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ��С = ԭ������ + ��������
		Worker ** newSapce  = new Worker*[newSize];//�����¿ռ�	

		//��ԭ���Ŀռ������ݣ��������¿ռ���
		if (this ->m_EmpArray != NULL)
		{
			for ( int i = 0; i < this->m_EmpNum; i++)
			{
				newSapce[i] = this->m_EmpArray[i];
			}
		}

		//ƣ������µ�����
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//���ű��ѡ��
			cout << "������� " << i + 1 << "����ְ���ı�ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << "����ְ����������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����һ����λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
					break;
			}
			newSapce[this->m_EmpNum + i] = worker;//��������ְ��ָ�뱣�浽������
		}
		delete[] this->m_EmpArray;//�ͷ�ԭ�еĿռ�
		this->m_EmpArray = newSapce;//�����¿ռ��ָ��
		this->m_EmpNum = newSize;//�����µ�ְ������
		this->m_FileIsEmpty = false;//����ְ����Ϊ�յı�־
		cout << "�ɹ����" <<addNum<<"����ְ����"<< endl;//��ʾ��ӳɹ�
		this->save();//�������ݵ��ļ���
	}
	else
	{
		cout << "��������" << endl;//�����
	}
	system("pause");//����������������ص��ϼ�Ŀ¼
	system("cls");
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ�����ļ� -- д�ļ�
		for(int i = 0; i < this->m_EmpNum; i++)//��ÿ���˵�����д�뵽�ļ���
		{
			ofs << this->m_EmpArray[i]->m_Id << "  "
				<< this->m_EmpArray[i]->m_Name << "  "
				<< this->m_EmpArray[i]->m_DeptId << endl;
		}
		//�ر��ļ�
		ofs.close();
}

int WorkManager::get_EmpNum()//ͳ���ļ��е�����
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ���ļ�

	int id;

	string name;

	int dId;

	int num = 0;

	while (ifs >> id && ifs >>name && ifs >> dId)
	{
		num++;//ͳ�������ı�־
	}

	return num;
}

void WorkManager::init_Emp()//��ʼ��Ա��
{
	ifstream ifs;
	
	ifs.open(FILENAME, ios::in);
	
	int id;
	
	string name;
	
	int dId;

	int index = 0;
	
	while (ifs >> id && ifs >> name && ifs >>dId)
	{
		Worker * worker = NULL;
		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if ( dId == 2 )//����
		{
			worker = new Manager(id, name, dId);
		}
		else //�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

void WorkManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;

	}
	else
	{
		cout << "��������Ҫɾ����ְ����ţ�" << endl;//����ְ�����ɾ��
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
		{
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//����ǰ��
			}
			this->m_EmpNum--;//���������м�¼��Ա����
			this->save();//����ͬ�����µ��ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}
	//ɾ��������Ӧ�ð������еĳ��ȿ���һ�ڽڻ𳵳��ᣬ�����е����ݾͺñ��ǳ˿ͣ�
	//�����ɾ�������˾���Ӧ��ʹ�ú�һλ���������ݸ���ǰһλ�ȽϺ��ʡ����ʾ�������Ǩ��
	
	system("pause");//�����������
	system("cls");
}

int WorkManager::IsExist(int id)
{
	int index = -1;//��ʼ�϶�������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkManager::Mod_Emp()//�޸�ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			 //���ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker * worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;

			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;

			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;

			default:
				break;
			}
			this->m_EmpArray[ret] = worker;//�������ݵ�������
			cout <<"�޸ĳɹ���"<< this->m_EmpArray[ret]->m_DeptId << endl;

			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::Find_Emp()//����ְ��
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.������������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)//��װ���������
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else if (select == 2) //����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  //���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< m_EmpArray[i]->m_Id
						<< " �ŵ���Ϣ���£�" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}


	system("pause");
	system("cls");
}

void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //����
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //����
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker * temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}

		}

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}

}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)//�����������ֶ������ֶ�ɾ��
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
