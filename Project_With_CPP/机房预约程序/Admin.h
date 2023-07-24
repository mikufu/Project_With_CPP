#pragma once
#include "Student.h"
#include "Teacher.h"

class Admin : public Identity
{
public:
	//��ʼ������Ա��
	Admin(std::string account, std::string password);
	//����Ա�˵�
	virtual void showMenu();
	//��ӡѧ���˺�
	void printAccount(const std::list<Student>& ls);
	//��ӡ��ʦ�˺�
	void printAccount(const std::list<Teacher>& lt);
	//��ӡ����Ա�˺�
	void printAccount(const std::list<Admin>& la);
	//����Ƿ��˺ţ�����ʹ��printAccount��ӡ�˺���Ϣ
	void checkAccount(const std::list<Student>& ls, const std::list<Teacher>& lt, const std::list<Admin>& la);
	//����˺�
	void addAccount(std::list<Student>& ls, std::list<Teacher>& lt, std::list<Admin>& la);
	//ɾ���˺�
	void delAccount(std::list<Student>& ls, std::list<Teacher>& lt, std::list<Admin>& la);
	//�鿴������Ϣ
	void checkComRoom(Order& ord);
	//���Ļ�������
	void setComRoom(Order& ord);
	//������������
	virtual void setPword();
	//���ԤԼ�ļ�
	void clearRes(Order& ord);
	//����==�жϹ���Ա�û����Ƿ��ظ�
	bool operator== (const Admin& a) const;
	//�����ȡ����Ա�û���
	virtual std::string GetUname() const;
	//�����ȡ����Ա����
	virtual std::string GetPword() const;
};