//#include <iostream>
//
//using namespace std;
//
//class Person
//{
//public:
//	int* m_Age;
//
//	Person(int age)
//	{
//		m_Age = new int(age);
//	}
//
//	~Person()
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//
//	Person& operator= (Person& p)
//	{
//		if (this->m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = new int(*p.m_Age);
//		}
//		return *this;
//	}
//};
//
//int main()
//{
//	Person p1(10);
//	Person p2(12);
//	Person p3(15);
//
//	cout << "p1的年龄" << *p1.m_Age << endl;
//
//	p1 = p2 = p3;
//
//	cout << "p1的年龄" << *p1.m_Age << endl;
//	cout << "p2的年龄" << *p2.m_Age << endl;
//	cout << "p3的年龄" << *p3.m_Age << endl;
//
//	return 0;
//}