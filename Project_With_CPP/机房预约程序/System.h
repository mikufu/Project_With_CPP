#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
//��ϵͳ
class System
{
public:
	std::list<Student> ls;	//ѧ���б�
	std::list<Teacher> lt;	//��ʦ�б�
	std::list<Admin> la;	//����Ա�б�
	Order ord;				//ԤԼϵͳ

public:
	//��ʼ��ϵͳ
	System();
	//���˵�
	void MainMenu();
	//���ѧ��������Ϣ
	std::list<Student>::iterator checkStu(int ID, std::string username, std::string password);
	//ѧ��ϵͳ
	void StuSystem();
	//����ʦ������Ϣ
	std::list<Teacher>::iterator checkTea(int ID, std::string username, std::string password);
	//��ʦϵͳ
	void TeaSystem();
	//������Ա������Ϣ
	std::list<Admin>::iterator checkAdm(std::string username, std::string password);
	//����Աϵͳ
	void AdmSystem();
	//����ϵͳ��Ϣ
	void save();
	//������ϵͳ
	~System();
};