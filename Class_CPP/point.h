#pragma once
#include <iostream>

class Point
{
	//friend std::ostream& operator<< (std::ostream& cout, Point& p);

private:
	double m_x;
	double m_y;
public:
	Point(double x, double y);

	double GetX();

	double GetY();

	~Point();
};

//std::ostream& operator<< (std::ostream& cout, Point& p)
//{
//	cout << "点p的x坐标为：" << p.m_x;
//	cout << " 点p的y坐标为：" << p.m_y;
//	return cout;
//}