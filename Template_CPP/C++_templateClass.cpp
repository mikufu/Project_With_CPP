//#include <iostream>
//
//using namespace std;
//
//template<class NameType, class AgeType>
//class Person
//{
//public:
//	Person(NameType name, AgeType age)
//	{
//		m_name = name;
//		m_age = age;
//	}
//
//	void showperson()
//	{
//		cout << "������" << this->m_name << " ���䣺" << this->m_age << endl;
//	}
//
//	NameType m_name;
//	AgeType m_age;
//};
//
////1. ָ����������
//void showPerson1(Person<string, int>& p)
//{
//	p.showperson();
//}
//
//void test01()
//{
//	Person<string, int> p1("�����", 1000);
//	showPerson1(p1);
//}
//
////2. ����ģ�廯
//template<class NameType, class AgeType>
//void showPerson2(Person<NameType, AgeType>& p)
//{
//	p.showperson();
//	cout << "NameType����������: " << typeid(NameType).name() << endl;
//	cout << "AgeType����������: " << typeid(AgeType).name() << endl;
//}
//
//void test02()
//{
//	Person<string, int> p2("��˽�", 500);
//	showPerson2(p2);
//}
//
////3. ������ģ�廯
//template<class T>
//void showPerson3(T& p)
//{
//	p.showperson();
//	cout << "T����������: " << typeid(T).name() << endl;
//}
//
//void test03()
//{
//	Person<string, int> p3("ɳ��", 400);
//	showPerson3<Person<string, int>>(p3);	//�����Զ�ת������
//}
//
//int main()
//{
//	test01();
//	test02();
//	test03();
//
//	return 0;
//}