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
//		cout << "姓名：" << this->m_name << " 年龄：" << this->m_age << endl;
//	}
//
//	NameType m_name;
//	AgeType m_age;
//};
//
////1. 指定传入类型
//void showPerson1(Person<string, int>& p)
//{
//	p.showperson();
//}
//
//void test01()
//{
//	Person<string, int> p1("孙悟空", 1000);
//	showPerson1(p1);
//}
//
////2. 参数模板化
//template<class NameType, class AgeType>
//void showPerson2(Person<NameType, AgeType>& p)
//{
//	p.showperson();
//	cout << "NameType的数据类型: " << typeid(NameType).name() << endl;
//	cout << "AgeType的数据类型: " << typeid(AgeType).name() << endl;
//}
//
//void test02()
//{
//	Person<string, int> p2("猪八戒", 500);
//	showPerson2(p2);
//}
//
////3. 整个类模板化
//template<class T>
//void showPerson3(T& p)
//{
//	p.showperson();
//	cout << "T的数据类型: " << typeid(T).name() << endl;
//}
//
//void test03()
//{
//	Person<string, int> p3("沙悟净", 400);
//	showPerson3<Person<string, int>>(p3);	//可以自动转换类型
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