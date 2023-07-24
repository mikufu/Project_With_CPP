#pragma once
#include "worker.h"

class Employee : public Worker
{
public:

	Employee(int m_ID, string m_name, int m_dID = 1);

	virtual void ShowInfo();
};
