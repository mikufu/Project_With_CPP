#include <iostream>
#include <Windows.h>

using namespace std;
//�̳л����﷨
class Mikufans
{
public:
	void header()
	{
		cout << "��ҳ	����	ֱ��	��Ա��		����	����	MSI		���ؿͻ���(��ҳ����)" << endl;
	}
	void footer()
	{
		cout << "��ҳ��Ϣ:>..." << "��ַ:>www.mikufuns.com(��ҳ�ײ�)" << endl;
	}
	void behindheader()
	{
		cout << "���硢MMD����Ϸ��ѧϰ���Ƽ�������...(����)" << endl;
	}
	void refresh()
	{
		cout << "ˢ����..." << endl;
		Sleep(5000);
		system("cls");
		Sleep(1000);
	}
};

class Animetion : public Mikufans
{
public:
	void anime()
	{
		cout << "ĳ��ѧ...		�ж���...		Ϊ����...		������...		(����)" << endl;
	}
};

class MikuMikuDance : public Mikufans
{
public:
	void mmd()
	{
		cout << "MIKU��������������������...(MMD)" << endl;
	}
};

class Game : public Mikufans
{
public:
	void game()
	{
		cout << "Minecraft����ʦ����Galgame������2...(��Ϸ)" << endl;
	}
};

class Study : public Mikufans
{
public:
	void study()
	{
		cout << "C/C++��Phython��Java��C#...(ѧϰ)" << endl;
	}
};

void test01()
{
	Animetion Ani;
	MikuMikuDance MMD;
	Game game;
	Study study;

	Ani.header();
	Ani.behindheader();
	Ani.anime();
	Ani.footer();
	Ani.refresh();

	MMD.header();
	MMD.behindheader();
	MMD.mmd();
	MMD.footer();
	MMD.refresh();

	game.header();
	game.behindheader();
	game.game();
	game.footer();
	game.refresh();

	study.header();
	study.behindheader();
	study.study();
	study.footer();
	study.refresh();

}
//�̳з�ʽ
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 : public Base1
{
public:
	void func()
	{
		m_A = 10;	//�����е�public����������Ȼ��public
		m_B = 10;	//�����е�protected����������protected
		//m_C = 10;	//�����е�private�����޷�����
	}
};

class Son2 : protected Base1
{
public:
	void func()
	{
		m_A = 10;	//�����е�public����������Ȼ��protected
		m_B = 10;	//�����е�protected����������protected
		//m_C = 10;	//�����е�private�����޷�����
	}
};

class Son3 : private Base1
{
public:
	void func()
	{
		m_A = 10;	//�����е�public����������Ȼ��private
		m_B = 10;	//�����е�protected����������private
		//m_C = 10;	//�����е�private�����޷�����
	}
};

//�̳��еĶ���ģ��
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son : public Base
{
public:
	int m_D;
};

void test02()
{
	cout << "sizeof(Son) = " << sizeof(Son) << endl;
}

int main()
{
	//test01();
	test02();

	return 0;
}

//����Developer Commmad Prompt�鿴����ģ��
//��ת�̷�	F:
//��ת�ļ�·�� cd ����·����
//�鿴����
//cl /d1 reportSingleClassLayout���� �ļ���