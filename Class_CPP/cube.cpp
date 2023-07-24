#include "cube.h"

	Cube::Cube(const double& L, const double& W, const double& H) : 
		m_L(L), m_W(W), m_H(H) { };

	double Cube::Get_L()
	{
		return m_L;
	}

	double Cube::Get_W()
	{
		return m_W;
	}

	double Cube::Get_H()
	{
		return m_H;
	}

	double Cube::Cube_S()
	{
		return 2.0 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	double Cube::Cube_V()
	{
		return m_L * m_W * m_H;
	}

	Cube::~Cube() 
	{
		std::cout << "析构了一个Cube类" << std::endl;
	}