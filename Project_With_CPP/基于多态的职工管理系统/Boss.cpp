#include "Boss.h"

Boss::Boss(int m_ID, string m_name, int m_dID)
{
	this->m_ID = m_ID;
	this->m_name = m_name;
	this->m_dID = m_dID;
}

void Boss::ShowInfo()
{
	cout << "ְ�����: " << m_ID
		<< "\tְ������: " << m_name
		<< "\tְ��ְλ: " << "�ϰ�"
		<< "\tְ��ְ��: " << "����˾��������"
		<< endl;
}