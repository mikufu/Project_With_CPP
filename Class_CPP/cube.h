#pragma once
#include <iostream>

class Cube
{
private:
	double m_L;
	double m_W;
	double m_H;
public:
	Cube(const double& L, const double& W, const double& H);

	double Get_L();

	double Get_W();

	double Get_H();

	double Cube_S();

	double Cube_V();

	~Cube();
};