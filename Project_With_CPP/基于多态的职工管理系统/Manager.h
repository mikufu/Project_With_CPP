#pragma once
#include "worker.h"

class Manager : public Worker
{
public:

	Manager(int m_ID, string m_name, int m_dID = 2);

	void ShowInfo();
};