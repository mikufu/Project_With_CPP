#include "circle.h"

Circle::Circle(double x, double y, double r) : m_x(x), m_y(y), m_r(r) { };

void Circle::SetX(double x)
{
	m_x = x;
}

void Circle::SetY(double y)
{
	m_y = y;
}

void Circle::SetR(double r)
{
	m_r = r;
}

double Circle::GetX()
{
	return m_x;
}

double Circle::GetY()
{
	return m_y;
}

double Circle::GetR()
{
	return m_r;
}

bool Circle::IsInCirle(Point& p)
{
	double x = p.GetX(); double y = p.GetY();
	double distance = (m_x - x) * (m_x - x) + (m_y - y) * (m_y - y);
	
	if (distance < m_r * m_r)
		return true;
	else
		return false;
}

Circle::~Circle()
{
	std::cout << "析构了一个圆" << std::endl;
}