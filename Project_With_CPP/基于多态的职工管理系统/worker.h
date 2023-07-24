#pragma once
#include <iostream>
using namespace std;

class Worker
{
public:
	int m_ID;
	string m_name;
	int m_dID;

	virtual void ShowInfo() = 0;
};