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
//};
//
//ostream& operator<< (ostream& cout, Vector& v)
//{
//	cout << "ÏòÁ¿v = (" << v.m_x << ", " << v.m_y << ", " << v.m_z << ")";
//	return cout;
//}
//
//int main()
//{
//	Vector v(2.78, 3.29, 1.47);
//
//	cout << v << endl;
//
//	return 0;
//}