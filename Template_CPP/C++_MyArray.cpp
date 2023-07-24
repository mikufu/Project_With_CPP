#include "MyArray.hpp"

template<class T>
void showArray(T& arr)
{
	for (int i = 0; i < arr.getsize(); i++)
		cout << arr[i] << endl;
}

void test01()
{
	MyArray<int>intArray1(4);
	intArray1.push_back(1);
	intArray1.push_back(2);
	intArray1.push_back(3);
	intArray1.push_back(4);

	showArray(intArray1);

	MyArray<int>intArray2(intArray1);
	intArray2.pop_back();
	showArray(intArray2);

	cout << "intArray1的大小为: " << intArray1.getsize() << endl;;
	cout << "intArray1的容量为: " << intArray1.getcapacity() << endl;;
	cout << "intArray2的大小为: " << intArray2.getsize() << endl;;
	cout << "intArray2的容量为: " << intArray2.getcapacity() << endl;
}

class Person
{
	friend ostream& operator<< (ostream& cout, const Person& p);
private:
	int m_age;
	string m_name;
	
public:
	Person() { m_age = 0; }	//没有默认构造函数，无法成功构造Person类数组

	Person(int age, string name)
	{
		m_age = age;
		m_name = name;
	}

	Person& operator= (const Person& p)
	{
		this->m_age = p.m_age;
		this->m_name = p.m_name;
		return *this;
	}
};

ostream& operator<< (ostream& cout, const Person& p)
{
	cout << "姓名：" << p.m_name << " 年龄：" << p.m_age;
	return cout;
}

void test02()
{
	Person p1(1000, "孙悟空");
	Person p2(500, "猪八戒");
	Person p3(400, "沙僧");

	MyArray<Person>PersonArray1(3);
	PersonArray1.push_back(p1);
	PersonArray1.push_back(p2);
	PersonArray1.push_back(p3);
	showArray(PersonArray1);
	cout << "PersonArray1的大小为: " << PersonArray1.getsize() << endl;;
	cout << "PersonArray1的容量为: " << PersonArray1.getcapacity() << endl;

	MyArray<Person>PersonArray2(PersonArray1);
	PersonArray2.pop_back();
	PersonArray2[1] = p3;
	showArray(PersonArray2);
	cout << "PersonArray2的大小为: " << PersonArray2.getsize() << endl;;
	cout << "PersonArray2的容量为: " << PersonArray2.getcapacity() << endl;

}

int main()
{
	//test01();
	test02();
	return 0;
}