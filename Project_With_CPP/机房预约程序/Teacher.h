#pragma once
#include "Identity.h"

class Teacher : public Identity
{
private:
	int m_ID;

public:
	//��ʼ����ʦ��
	Teacher(int ID, std::string account, std::string password);
	//��ʦ�˵�
	virtual void showMenu();
	//�鿴ԤԼ
	void checkRes(Order& ord);
	//���ԤԼ
	void auditRes(Order& ord);
	//������������
	virtual void setPword();
	//����==�жϽ�ʦ�����Ƿ��ظ�
	bool operator==(const Teacher& t) const;
	//�����ȡ��ʦ���û���
	virtual std::string GetUname() const;
	//�����ȡ��ʦ����
	virtual std::string GetPword() const;
	//�����ȡ��ʦ����
	int GetID() const;
};