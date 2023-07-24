#include "System.h"

System::System()
{
	std::ifstream ifs;
	//��Student.txt�ļ��ж�ȡѧ����Ϣ
	ifs.open("Student.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "û��Student.txt�ļ�������ӣ�" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	int ID = 0;
	std::string username;
	std::string password;
	//��ʼ��ѧ���б�
	while (ifs >> ID >> username >> password)
	{
		this->ls.push_back(Student(ID, username, password));
	}
	ifs.close();
	//��Teacher.txt�ļ��ж�ȡ��ʦ��Ϣ
	ifs.open("Teacher.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "û��Teacher.txt�ļ�������ӣ�" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	//��ʼ����ʦ�б�
	while (ifs >> ID >> username >> password)
	{
		lt.push_back(Teacher(ID, username, password));
	}
	ifs.close();
	//��Adimn.txt�ļ��ж�ȡ����Ա��Ϣ
	ifs.open("Admin.txt", std::ios::in);
	if (!ifs.is_open())
	{
		std::cout << "û��Order.txt�ļ�������ӣ�" << std::endl;
		system("pause");
		ifs.close();
		return;
	}
	//��ʼ������Ա�б�
	while (ifs >> username >> password)
	{
		la.push_back(Admin(username, password));
	}
	ifs.close();
}

void System::MainMenu()
{
	//��ӡ���˵�
	std::cout << "--------------------��ӭʹ�û���ԤԼϵͳ!--------------------" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "                |      1.ѧ       ��        |" << std::endl;
	std::cout << "                |      2.��       ʦ        |" << std::endl;
	std::cout << "                |      3.��       ��        |" << std::endl;
	std::cout << "                |      0.��       ��        |" << std::endl;
	std::cout << "                  -------------------------" << std::endl;
	std::cout << "���������ѡ��:> ";
}

std::list<Student>::iterator System::checkStu(int ID, std::string username, std::string password)
{
	//����ѧ���б�����Ӧ�����ѧ���ĵ���������
	for (std::list<Student>::iterator it = ls.begin();
		it != ls.end(); it++)
	{
		if (it->GetID() == ID
			&& it->GetUname() == username
			&& it->GetPword() == password)
			return it;
	}
	return ls.end();
}

void System::StuSystem()
{
	int ID = 0;
	std::string username;
	std::string password;
	while (true)
	{
		std::cout << "������ѧ��:> ";
		checkInput(ID);
		std::cout << "�������û���:> ";
		std::cin >> username;
		std::cout << "����������:> ";
		std::cin >> password;
		//������ѧ������Ϣ�Ƿ����
		std::list<Student>::iterator it = checkStu(ID, username, password);
		if (it != ls.end())
		{
			system("cls");
			int choice = 0;
			do
			{
				it->showMenu();
				checkInput(choice);
				switch (choice)
				{
				case 1:
					it->applyRes(this->ord);				//����ԤԼ
					break;
				case 2:
					it->checkM_Res(this->ord);				//�鿴ԤԼ
					break;
				case 3:
					it->checkAllRes(this->ord);				//�鿴����ԤԼ
					break;
				case 4:
					it->modifyRes(this->ord);				//�޸�ԤԼ
					break;
				case 5:
					it->cancelRes(this->ord);				//ȡ��ԤԼ
					break;
				case 6:
					it->setPword();							//������������
					this->save();
					break;
				case 0:
					break;
				default:
					std::cout << "�������" << std::endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice);
			break;
		}
		else
			std::cout << "�û�����������������µ�¼��" << std::endl;
	}
}

std::list<Teacher>::iterator System::checkTea(int ID, std::string username, std::string password)
{
	//������ʦ�б�����Ӧ����Ľ�ʦ�ĵ���������
	for (std::list<Teacher>::iterator it = lt.begin();
		it != lt.end(); it++)
	{
		if (it->GetID() == ID
			&& it->GetUname() == username
			&& it->GetPword() == password)
			return it;
	}
	return lt.end();
}

void System::TeaSystem()
{
	int ID;
	std::string username;
	std::string password;
	while (true)
	{
		std::cout << "�����빤��:> ";
		checkInput(ID);
		std::cout << "�������û���:> ";
		std::cin >> username;
		std::cout << "����������:> ";
		std::cin >> password;
		//�������ʦ����Ϣ�Ƿ����
		std::list<Teacher>::iterator it = checkTea(ID, username, password);
		if (it != lt.end())
		{
			system("cls");
			int choice = 0;
			do
			{
				it->showMenu();
				checkInput(choice);
				switch (choice)
				{
				case 1:
					it->checkRes(this->ord);				//�鿴ԤԼ
					break;
				case 2:
					it->auditRes(this->ord);				//���ԤԼ
					break;
				case 3:
					it->setPword();							//������������
					this->save();
					break;
				case 0:
					break;
				default:
					std::cout << "�������" << std::endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice);
			break;
		}
		else
			std::cout << "�û�����������������µ�¼��" << std::endl;
	}
}

std::list<Admin>::iterator System::checkAdm(std::string username, std::string password)
{
	//��������Ա�б�����Ӧ����Ĺ���Ա�ĵ���������
	for (std::list<Admin>::iterator it = la.begin();
		it != la.end(); it++)
	{
		if (it->GetUname() == username
			&& it->GetPword() == password)
			return it;
	}
	return la.end();
}

void System::AdmSystem()
{
	std::string username;
	std::string password;
	while (true)
	{
		std::cout << "�������û���:> ";
		std::cin >> username;
		std::cout << "����������:> ";
		std::cin >> password;
		//���������Ա����Ϣ�Ƿ����
		std::list<Admin>::iterator it = checkAdm(username, password);
		if (it != la.end())
		{
			system("cls");
			int choice = 0;
			do
			{
				it->showMenu();
				checkInput(choice);
				switch (choice)
				{
				case 1:
					it->checkAccount(ls, lt, la);			//�鿴�˺�
					break;
				case 2:
					it->addAccount(ls, lt, la);				//����˺�
					this->save();
					break;
				case 3:
					it->delAccount(ls, lt, la);				//ɾ���˺�
					this->save();
					break;
				case 4:
					it->checkComRoom(this->ord);			//�鿴������Ϣ
					break;
				case 5:
					it->setComRoom(this->ord);				//���Ļ�������
					break;
				case 6:
					it->setPword();							//������������
					this->save();
					break;
				case 7:
					it->clearRes(this->ord);				//���ԤԼ
					break;
				case 0:
					break;
				default:
					std::cout << "�������" << std::endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice);
			break;
		}
		else
			std::cout << "�û�����������������µ�¼��" << std::endl;
	}
}

void System::save()
{
	std::ofstream ofs;
	//��ѧ���б��е���Ϣд��Student.txt�ļ�
	ofs.open("Student.txt", std::ios::out);
	std::list<Student>::iterator it1 = ls.begin();
	while (it1 != ls.end())
	{
		ofs << it1->GetID() << " "
			<< it1->GetUname() << " "
			<< it1->GetPword() << " " << std::endl;
		it1++;
	}
	ofs.close();
	//����ʦ�б��е���Ϣд��Teacher.txt�ļ�
	ofs.open("Teacher.txt", std::ios::out);
	std::list<Teacher>::iterator it2 = lt.begin();
	while (it2 != lt.end())
	{
		ofs << it2->GetID() << " "
			<< it2->GetUname() << " "
			<< it2->GetPword() << " " << std::endl;
		it2++;
	}
	ofs.close();
	//������Ա�б��е���Ϣд��Admin.txt�ļ�
	ofs.open("Admin.txt", std::ios::out);
	std::list<Admin>::iterator it3 = la.begin();
	while (it3 != la.end())
	{
		ofs << it3->GetUname() << " "
			<< it3->GetPword() << " " << std::endl;
		it3++;
	}
	ofs.close();
}

System::~System()
{
	//����ϵͳ��Ϣ���ͷ��ڴ�
	save();
	ls.clear();
	lt.clear();
	la.clear();
}
