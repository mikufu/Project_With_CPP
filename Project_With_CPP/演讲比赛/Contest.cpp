#include "Contest.h"

Contest::Contest()
{
	for (int i = 1; i <= 12; i++)
	{
		string name = "选手";
		name += 'A' + i - 1;
		v.push_back(Contestants(100 + i, name, 0.0));
	}
}

void Contest::menu()
{
	cout << "******************************" << endl;
	cout << "***    欢迎观看演讲比赛    ***" << endl;
	cout << "***     1.开始演讲比赛     ***" << endl;
	cout << "***     2.查看往届记录     ***" << endl;
	cout << "***     3.清空比赛记录     ***" << endl;
	cout << "***     0.退出比赛程序     ***" << endl;
	cout << "******************************" << endl;
	cout << "请选择需要的操作:> ";
}

void Print(Contestants& c)
{
	cout << "选手编号:> " << c.GetID()
		<< "    选手姓名:> " << c.GetName()
		<< "    选手分数:> " << c.GetSocre()
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
			string name = "选手";
			name += 'A' + i - 1;
			v.push_back(Contestants(100 + i, name, 0.0));
		}
	}
	cout << "---------------------------------------------------------------" << endl;
	cout << "第一轮比赛开始" << endl;
	cout << "---------------------------------------------------------------" << endl;
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), setscore);
	cout << "第一组比赛名次为:> " << endl;
	sort(v.begin(), v.begin() + 6, ContestantsCompare);
	ShowContestants(v.begin(), v.begin() + 6);
	cout << endl;
	cout << "第二组比赛名次为:> " << endl;
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
	cout << "第二轮比赛开始" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "第二轮比赛名次为:> " << endl;
	for_each(v.begin(), v.end(), setscore);
	sort(v.begin(), v.end(), ContestantsCompare);
	ShowContestants(v.begin(), v.end());
	system("pause");
	cout << endl;

	cout << "---------------------------------------------------------------" << endl;
	cout << "获胜选手名次为:>" << endl;
	ShowContestants(v.begin(), v.begin() + 3);
	
	v.resize(3);
	save();

	system("pause");
	system("cls");
}

void Contest::save()
{
	ofstream ofs;
	ofs.open("获奖名单.csv", ios::out | ios::app);
	for (int i = 0; i < 3; i++)
	{
		ofs << v[i].GetID() << ','
			<< v[i].GetName() << ' ' << ','	//防止','写入string中
			<< v[i].GetSocre() << endl;
	}
	ofs.close();
	v.clear();
}

void Contest::load()
{
	v.clear();
	ifstream ifs;
	ifs.open("获奖名单.csv", ios::in);
	if (FileIsEmpty())
	{
		cout << "文件为空！" << endl;
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
	cout << "往期获奖名单:>" << endl;
	for_each(v.begin(), v.end(), Print);
	v.clear();

	system("pause");
	system("cls");
}

void Contest::clear_File()
{
	while (true)
	{
		cout << "1. 确认\n2. 返回\n请确认是否清空?:> ";
		int choice = 0;
		while (!(cin >> choice))
		{
			cout << "输入错误，请重新输入!" << endl;
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
			ofs.open("获奖名单.csv", ios::trunc);
			ofs.close();
			cout << "删除成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (choice == 2)
		{
			cout << "按任意键返回" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "选择错误，请重新选择!" << endl;
		}
	}
}

bool Contest::FileIsEmpty()
{
	ifstream ifs;
	ifs.open("获奖名单.csv", ios::in);
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