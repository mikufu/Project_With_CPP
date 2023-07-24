#include "Contest.h"

Contest::Contest()
{
	for (int i = 1; i <= 12; i++)
	{
		string name = "ѡ��";
		name += 'A' + i - 1;
		v.push_back(Contestants(100 + i, name, 0.0));
	}
}

void Contest::menu()
{
	cout << "******************************" << endl;
	cout << "***    ��ӭ�ۿ��ݽ�����    ***" << endl;
	cout << "***     1.��ʼ�ݽ�����     ***" << endl;
	cout << "***     2.�鿴�����¼     ***" << endl;
	cout << "***     3.��ձ�����¼     ***" << endl;
	cout << "***     0.�˳���������     ***" << endl;
	cout << "******************************" << endl;
	cout << "��ѡ����Ҫ�Ĳ���:> ";
}

void Print(Contestants& c)
{
	cout << "ѡ�ֱ��:> " << c.GetID()
		<< "    ѡ������:> " << c.GetName()
		<< "    ѡ�ַ���:> " << c.GetSocre()
		<< endl;
}

void Contest::ShowContestants(vector<Contestants>::iterator beg, vector<Contestants>::iterator end)
{
	for_each(beg, end, Print);
}

void setscore(Contestants& c)
{
	double score = 0;
	for (int i = 0; i < 10; i++)
		score += (rand() % 41 + 60) * 0.1;
	c.SetScore(score);
}

bool ContestantsCompare(Contestants& c1, Contestants& c2)
{
	return c1 > c2;
}

void Contest::process()
{
	if (v.empty())
	{
		for (int i = 1; i <= 12; i++)
		{
			string name = "ѡ��";
			name += 'A' + i - 1;
			v.push_back(Contestants(100 + i, name, 0.0));
		}
	}
	cout << "---------------------------------------------------------------" << endl;
	cout << "��һ�ֱ�����ʼ" << endl;
	cout << "---------------------------------------------------------------" << endl;
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), setscore);
	cout << "��һ���������Ϊ:> " << endl;
	sort(v.begin(), v.begin() + 6, ContestantsCompare);
	ShowContestants(v.begin(), v.begin() + 6);
	cout << endl;
	cout << "�ڶ����������Ϊ:> " << endl;
	sort(v.begin() + 6, v.end(), ContestantsCompare);
	ShowContestants(v.begin() + 6, v.end());

	vector<Contestants>tmp(v.begin(), v.begin() + 3);
	for (int i = 6; i < 9; i++)
	{
		tmp.push_back(v[i]);
	}
	v.swap(tmp);
	system("pause");
	cout << endl;

	cout << "---------------------------------------------------------------" << endl;
	cout << "�ڶ��ֱ�����ʼ" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "�ڶ��ֱ�������Ϊ:> " << endl;
	for_each(v.begin(), v.end(), setscore);
	sort(v.begin(), v.end(), ContestantsCompare);
	ShowContestants(v.begin(), v.end());
	system("pause");
	cout << endl;

	cout << "---------------------------------------------------------------" << endl;
	cout << "��ʤѡ������Ϊ:>" << endl;
	ShowContestants(v.begin(), v.begin() + 3);
	
	v.resize(3);
	save();

	system("pause");
	system("cls");
}

void Contest::save()
{
	ofstream ofs;
	ofs.open("������.csv", ios::out | ios::app);
	for (int i = 0; i < 3; i++)
	{
		ofs << v[i].GetID() << ','
			<< v[i].GetName() << ' ' << ','	//��ֹ','д��string��
			<< v[i].GetSocre() << endl;
	}
	ofs.close();
	v.clear();
}

void Contest::load()
{
	v.clear();
	ifstream ifs;
	ifs.open("������.csv", ios::in);
	if (FileIsEmpty())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}

	int ID = 0;
	string name;
	double score = 0;
	char ch = 0;
	while (ifs >> ID && ifs>> ch && ifs >> name && ifs >> ch && ifs >> score)
	{
		v.push_back(Contestants(ID, name, score));
	}
	cout << "---------------------------------------------------------------" << endl;
	cout << "���ڻ�����:>" << endl;
	for_each(v.begin(), v.end(), Print);
	v.clear();

	system("pause");
	system("cls");
}

void Contest::clear_File()
{
	while (true)
	{
		cout << "1. ȷ��\n2. ����\n��ȷ���Ƿ����?:> ";
		int choice = 0;
		while (!(cin >> choice))
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();
		while (cin.get() != '\n')
			;


		if (choice == 1)
		{
			ofstream ofs;
			ofs.open("������.csv", ios::trunc);
			ofs.close();
			cout << "ɾ���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (choice == 2)
		{
			cout << "�����������" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "ѡ�����������ѡ��!" << endl;
		}
	}
}

bool Contest::FileIsEmpty()
{
	ifstream ifs;
	ifs.open("������.csv", ios::in);
	if (!ifs.is_open())
		exit(-1);
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		return true;
	}
	return false;
}