//#include <iostream>
//
//using namespace std;
//
//class Person
//{
//private:
//	string m_name;
//	int m_age;
//
//public:
//	Person(const string& name, const int& age) : m_name(name), m_age(age) { };
//
//	bool operator== (Person& p)
//	{
//		if (m_name == p.m_name && m_age == p.m_age)
//			return true;
//		else
//			return false;
//	}
//
//	bool operator!= (Person& p)
//	{
//		if (m_name == p.m_name && m_age == p.m_age)
//			return false;
//		else
//			return true;
//	}
//};
//
//int main()
//{
//	Person p1("Tom", 3);
//	Person p2("Tom", 3);
//	Person p3("Jerry", 3);
//
//	if (p1 == p2)
//		cout << "p1 和 p2 相等" << endl;
//	else
//		cout << "p1 和 p2 不相等" << endl;
//
//	if (p1 != p2)
//		cout << "p1 和 p2 不相等" << endl;
//	else
//		cout << "p1 和 p2 相等" << endl;
//
//	if (p1 == p3)
//		cout << "p1 和 p3 相等" << endl;
//	else
//		cout << "p1 和 p3 不相等" << endl;
//
//	if (p1 != p3)
//		cout << "p1 和 p3 不相等" << endl;
//	else
//		cout << "p1 和 p3 相等" << endl;
//
//	return 0;
//}