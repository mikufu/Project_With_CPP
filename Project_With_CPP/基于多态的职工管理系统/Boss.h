#pragma once
#include "worker.h"

class Boss : public Worker
{
public:

	Boss(int m_ID, string m_name, int m_dID = 3);

	void ShowInfo();
};