#include "point.h"

Point::Point(double x, double y) : m_x(x), m_y(y) { };

double Point::GetX()
{
	return m_x;
}

double Point::GetY()
{
	return m_y;
}

Point::~Point()
{
	std::cout << "������һ��Point��" << std:: endl;
}