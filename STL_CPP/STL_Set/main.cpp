#include <iostream>
#include <string>
#include <set>

using namespace std;

class MyCompare
{
public:
	bool operator() (const int x, const int y) const
	{
		return x > y;
	}
};

class Person
{
public:
	string m_name;
	int m_age;

	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
};

class MyComparePerson
{
public:
	bool operator() (const Person& p1, const Person& p2) const
	{
		return p1.m_age > p2.m_age;
	}
};

void test01()
{
	set<int>s1;
	s1.insert(20);
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int, MyCompare>s2;
	s2.insert(20);
	s2.insert(10);
	s2.insert(40);
	s2.insert(30);
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	Person p1("Áõ±¸", 29);
	Person p2("¹ØÓğ", 25);
	Person p3("ÕÅ·É", 23);
	Person p4("ÕÔÔÆ", 21);

	set<Person, MyComparePerson>s1;
	s1.insert(p2);
	s1.insert(p1);
	s1.insert(p4);
	s1.insert(p3);


	for (set<Person, MyComparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "ĞÕÃû£º" << (*it).m_name << " ÄêÁä£º" << (*it).m_age << endl;
	}
}

int main()
{
	//test01();
	test02();

	return 0;
}