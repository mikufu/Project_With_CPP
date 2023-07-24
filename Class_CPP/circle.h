#pragma once
#include "point.h"

class Circle
{
private:
	double m_x;
	double m_y;
	double m_r;
public:
	Circle(double x, double y, double r);

	void SetX(double x);

	void SetY(double y);

	void SetR(double r);

	double GetX();

	double GetY();

	double GetR();

	bool IsInCirle(Point& p);

	~Circle();
};