#include <iostream>
#include <Windows.h>

using namespace std;
//继承基本语法
class Mikufans
{
public:
	void header()
	{
		cout << "首页	番剧	直播	会员购		漫画	赛事	MSI		下载客户端(网页顶部)" << endl;
	}
	void footer()
	{
		cout << "网页信息:>..." << "网址:>www.mikufuns.com(网页底部)" << endl;
	}
	void behindheader()
	{
		cout << "番剧、MMD、游戏、学习、科技、音乐...(分区)" << endl;
	}
	void refresh()
	{
		cout << "刷新中..." << endl;
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
		cout << "某科学...		中二病...		为美好...		紫罗兰...		(番剧)" << endl;
	}
};

class MikuMikuDance : public Mikufans
{
public:
	void mmd()
	{
		cout << "MIKU、弱音、镜音、洛天依...(MMD)" << endl;
	}
};

class Game : public Mikufans
{
public:
	void game()
	{
		cout << "Minecraft、巫师三、Galgame、大表哥2...(游戏)" << endl;
	}
};

class Study : public Mikufans
{
public:
	void study()
	{
		cout << "C/C++、Phython、Java、C#...(学习)" << endl;
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
//继承方式
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
		m_A = 10;	//父类中的public在子类中依然是public
		m_B = 10;	//父类中的protected在子类中是protected
		//m_C = 10;	//父类中的private子类无法访问
	}
};

class Son2 : protected Base1
{
public:
	void func()
	{
		m_A = 10;	//父类中的public在子类中依然是protected
		m_B = 10;	//父类中的protected在子类中是protected
		//m_C = 10;	//父类中的private子类无法访问
	}
};

class Son3 : private Base1
{
public:
	void func()
	{
		m_A = 10;	//父类中的public在子类中依然是private
		m_B = 10;	//父类中的protected在子类中是private
		//m_C = 10;	//父类中的private子类无法访问
	}
};

//继承中的对象模型
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

//利用Developer Commmad Prompt查看对象模型
//跳转盘符	F:
//跳转文件路径 cd 具体路径下
//查看命令
//cl /d1 reportSingleClassLayout类名 文件名