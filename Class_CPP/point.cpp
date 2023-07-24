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
	std::cout << "析构了一个Point类" << std:: endl;
}