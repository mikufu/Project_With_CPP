//#include <iostream>
//
//using namespace std;
//
//class Vector
//{
//	friend ostream& operator<< (ostream& cout, Vector& p);
//
//private:
//	double m_x;
//	double m_y;
//	double m_z;
//
//public:
//
//	Vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z) { };
//
//	double Get_X()
//	{
//		return m_x;
//	}
//
//	double Get_Y()
//	{
//		return m_y;
//	}
//
//	double Get_Z()
//	{
//		return m_z;
//	}
//
//	Vector operator+ (Vector& u)
//	{
//		Vector tmp(0, 0, 0);
//		tmp.m_x = this->m_x + u.m_x;
//		tmp.m_y = this->m_y + u.m_y;
//		tmp.m_z = this->m_z + u.m_z;
//		return tmp;
//	}
//
//};
//
//ostream& operator<< (ostream& cout, Vector& v)
//{
//	cout <<"("<< v.m_x << ", " << v.m_y << ", " << v.m_z << ")";
//	return cout;
//}
//
//int main()
//{
//	Vector v(2.0, 3.0, 1.0);
//	Vector u(3.2, 1.9, 2.71);
//
//	Vector w = v + u;
//
//	cout << "v = " << v << endl;
//	cout << "u = " << u << endl;
//	cout << "w = v + u = " << w << endl;
//
//	return 0;
//}