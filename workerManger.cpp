//职工管理类
#include "workManager.h"

WorkManager::WorkManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		//初始化属性
		this->m_EmpNum = 0;//初始化人数为0
		this->m_EmpArray = NULL;//初始化数组指针为空
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;//文件为空
		this->m_EmpNum = 0;//初始化人数为0
		this->m_EmpArray = NULL;//初始化数组指针为空
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，并记录数据
	int num = this->get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	
	
	this->m_EmpArray = new Worker*[this->m_EmpNum];//开辟
	this->init_Emp();//文件中的数据，存到数组中

	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "编号：" << this->m_EmpArray[i]->m_Id
			 << "姓名：" << this->m_EmpArray[i]->m_Name
			 << "部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}

void WorkManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "**欢迎使用员工管理系统！**" << endl;
	cout << "******0.退出管理系统******" << endl;
	cout << "******1.增加员工信息******" << endl;
	cout << "******2.显示员工信息******" << endl;
	cout << "******3.删除离职员工******" << endl;
	cout << "******4.修改员工信息******" << endl;
	cout << "******5.查找员工信息******" << endl;
	cout << "******6.按照编号排序******" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);//退出程序
}

void WorkManager::Add_Emp()//添加职工函数
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;//记录保持用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//执行具体添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间大小 = 原来人数 + 新增人数
		Worker ** newSapce  = new Worker*[newSize];//开辟新空间	

		//将原来的空间下数据，拷贝到新空间下
		if (this ->m_EmpArray != NULL)
		{
			for ( int i = 0; i < this->m_EmpNum; i++)
			{
				newSapce[i] = this->m_EmpArray[i];
			}
		}

		//疲劳添加新的数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门编号选择
			cout << "请输入第 " << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的一个岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			newSapce[this->m_EmpNum + i] = worker;//将创建的职工指针保存到数组中
		}
		delete[] this->m_EmpArray;//释放原有的空间
		this->m_EmpArray = newSapce;//更改新空间的指向
		this->m_EmpNum = newSize;//更新新的职工人数
		this->m_FileIsEmpty = false;//更新职工不为空的标志
		cout << "成功添加" <<addNum<<"名新职工！"<< endl;//提示添加成功
		this->save();//保存数据到文件中
	}
	else
	{
		cout << "输入有误！" << endl;//不添加
	}
	system("pause");//按任意键后清屏，回到上级目录
	system("cls");
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式来打开文件 -- 写文件
		for(int i = 0; i < this->m_EmpNum; i++)//将每个人的数据写入到文件这
		{
			ofs << this->m_EmpArray[i]->m_Id << "  "
				<< this->m_EmpArray[i]->m_Name << "  "
				<< this->m_EmpArray[i]->m_DeptId << endl;
		}
		//关闭文件
		ofs.close();
}

int WorkManager::get_EmpNum()//统计文件中的人数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件 读文件

	int id;

	string name;

	int dId;

	int num = 0;

	while (ifs >> id && ifs >>name && ifs >> dId)
	{
		num++;//统计人数的标志
	}

	return num;
}

void WorkManager::init_Emp()//初始化员工
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
		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if ( dId == 2 )//经理
		{
			worker = new Manager(id, name, dId);
		}
		else //老板
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

void WorkManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用接口
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
		cout << "文件不存在或记录为空！" << endl;

	}
	else
	{
		cout << "请输入想要删除的职工编号：" << endl;//按照职工编号删除
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//说明职工存在，并且要删除掉index位置上的职工
		{
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];//数据前移
			}
			this->m_EmpNum--;//更新数组中记录人员个数
			this->save();//数据同步更新到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工！" << endl;
		}
	}
	//删除？我们应该把数组中的长度看成一节节火车车厢，而其中的数据就好比是乘客，
	//相较于删除，个人觉得应该使用后一位的数组数据覆盖前一位比较合适。本质就是数据迁移
	
	system("pause");//按任意键清屏
	system("cls");
}

int WorkManager::IsExist(int id)
{
	int index = -1;//初始认定不存在
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

void WorkManager::Mod_Emp()//修改职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			 //查找到编号的职工
			delete this->m_EmpArray[ret];
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			this->m_EmpArray[ret] = worker;//更改数据到数组中
			cout <<"修改成功！"<< this->m_EmpArray[ret]->m_DeptId << endl;

			this->save();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkManager::Find_Emp()//查找职工
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式！" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)//安装编号来查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功,职工编号为："
						<< m_EmpArray[i]->m_Id
						<< " 号的信息如下：" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}


	system("pause");
	system("cls");
}

void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else  //降序
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

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}

}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)//堆区的数据手动开辟手动删除
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
