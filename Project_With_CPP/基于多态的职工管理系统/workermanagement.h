#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include "employee.h"
#include "Manager.h"
#include "Boss.h"

class WorkerManage
{
public:
	WorkerManage();

	void showmenu();

	bool m_FileisEmpty();
	
	bool is_repete(int ID);

	void Add_Emp();

	void save();

	void showInfo();

	list<Worker*>::iterator Find();

	void del_Emp();

	void modify();

	void search_Emp();

	//bool compare(const Worker* first, const Worker* second); list.sort()的比较函数在类外定义

	void sort_Emp();

	void clear_File();

	~WorkerManage();

public:
	list<Worker*> wlist;
};