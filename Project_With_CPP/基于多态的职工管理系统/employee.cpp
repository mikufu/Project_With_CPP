#include "employee.h"

Employee::Employee(int m_ID, string m_name, int m_dID)
{
	this->m_ID = m_ID;
	this->m_name = m_name;
	this->m_dID = m_dID;
}

void Employee::ShowInfo()
{
	cout << "职工编号: " << m_ID
		<< "\t职工姓名: " << m_name
		<< "\t职工职位: " << "员工"
		<< "\t职工职责: " << "完成经理布置的任务"
		<< endl;
}
