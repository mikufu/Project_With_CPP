#include <iostream>
#include "cube.h"
#include "point.h"
#include "circle.h"
#include "cpu.h"

using namespace std;

void test01()
{
	Cube C(1.09, 1.45, 1.322);

	cout << "������C�ĳ�Ϊ��" << C.Get_L() << endl;
	cout << "������C�Ŀ�Ϊ��" << C.Get_W() << endl;
	cout << "������C�ĸ�Ϊ��" << C.Get_H() << endl;
	cout << "������C�����Ϊ��" << C.Cube_S() << endl;
	cout << "������C�����Ϊ��" << C.Cube_V() << endl;
}

void test02()
{
	Point p(2.93, 5.39);
	cout << "��p��x����Ϊ��" << p.GetX() << endl;
	cout << "��p��y����Ϊ��" << p.GetY() << endl;

	Circle c(6.3, 7.23, 9.39);

	cout << "Բc��Բ��x����Ϊ��" << c.GetX() << endl;
	cout << "Բc��Բ��y����Ϊ��" << c.GetY() << endl;
	cout << "Բc�İ뾶Ϊ��" << c.GetR() << endl;
	
	cout << "��p�Ƿ���Բc�ڣ�";
	if (c.IsInCirle(p))
		cout << "��Բ��" << endl;
	else
		cout << "��Բ��" << endl;

}

void test03()
{
	CPU a(R7, 300, 2.8f);

	a.Run();

	cout << "CPU��rank:>" << a.GetRank() << endl;
	cout << "CPU��frequency:>" << a.GetFrequency() << endl;
	cout << "CPU��voltage:>" << a.GetVoltage() << endl;

	a.Stop();
}

int main()
{
	//test01();
	//test02();
	test03();

	return 0;
}