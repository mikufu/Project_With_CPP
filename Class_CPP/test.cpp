#include <iostream>
#include "cube.h"
#include "point.h"
#include "circle.h"
#include "cpu.h"

using namespace std;

void test01()
{
	Cube C(1.09, 1.45, 1.322);

	cout << "立方体C的长为：" << C.Get_L() << endl;
	cout << "立方体C的宽为：" << C.Get_W() << endl;
	cout << "立方体C的高为：" << C.Get_H() << endl;
	cout << "立方体C的面积为：" << C.Cube_S() << endl;
	cout << "立方体C的体积为：" << C.Cube_V() << endl;
}

void test02()
{
	Point p(2.93, 5.39);
	cout << "点p的x坐标为：" << p.GetX() << endl;
	cout << "点p的y坐标为：" << p.GetY() << endl;

	Circle c(6.3, 7.23, 9.39);

	cout << "圆c的圆心x坐标为：" << c.GetX() << endl;
	cout << "圆c的圆心y坐标为：" << c.GetY() << endl;
	cout << "圆c的半径为：" << c.GetR() << endl;
	
	cout << "点p是否在圆c内：";
	if (c.IsInCirle(p))
		cout << "在圆内" << endl;
	else
		cout << "在圆外" << endl;

}

void test03()
{
	CPU a(R7, 300, 2.8f);

	a.Run();

	cout << "CPU的rank:>" << a.GetRank() << endl;
	cout << "CPU的frequency:>" << a.GetFrequency() << endl;
	cout << "CPU的voltage:>" << a.GetVoltage() << endl;

	a.Stop();
}

int main()
{
	//test01();
	//test02();
	test03();

	return 0;
}