#include "employee.h"

Employee::Employee(int m_ID, string m_name, int m_dID)
{
	this->m_ID = m_ID;
	this->m_name = m_name;
	this->m_dID = m_dID;
}

void Employee::ShowInfo()
{
	cout << "ְ�����: " << m_ID
		<< "\tְ������: " << m_name
		<< "\tְ��ְλ: " << "Ա��"
		<< "\tְ��ְ��: " << "��ɾ����õ�����"
		<< endl;
}
