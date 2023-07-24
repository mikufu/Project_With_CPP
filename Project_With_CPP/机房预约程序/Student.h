#pragma once
#include "Identity.h"

class Student : public Identity
{
private:
	int m_ID;

public:
	//��ʼ��ѧ����
	Student(int ID, std::string username, std::string password);
	// ѧ���˵�
	virtual void showMenu();
	//����ԤԼ
	void applyRes(Order& ord);
	//�鿴�����ԤԼ
	void checkM_Res(Order& ord);
	//�鿴�����˵�ԤԼ
	void checkAllRes(Order& ord);
	//�޸�ԤԼ
	void modifyRes(Order& ord);
	//ȡ��ԤԼ
	void cancelRes(Order& ord);
	//������������
	virtual void setPword();
	//����==�ж�ѧ��ѧ���Ƿ��ظ�
	bool operator==(const Student& s) const;
	//�����ȡѧ�����û���
	virtual std::string GetUname() const;
	//�����ȡѧ������
	virtual std::string GetPword() const;
	//�����ȡѧ��ѧ��
	int GetID() const;
};