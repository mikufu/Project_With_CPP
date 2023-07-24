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

	cout << "intArray1�Ĵ�СΪ: " << intArray1.getsize() << endl;;
	cout << "intArray1������Ϊ: " << intArray1.getcapacity() << endl;;
	cout << "intArray2�Ĵ�СΪ: " << intArray2.getsize() << endl;;
	cout << "intArray2������Ϊ: " << intArray2.getcapacity() << endl;
}

class Person
{
	friend ostream& operator<< (ostream& cout, const Person& p);
private:
	int m_age;
	string m_name;
	
public:
	Person() { m_age = 0; }	//û��Ĭ�Ϲ��캯�����޷��ɹ�����Person������

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
	cout << "������" << p.m_name << " ���䣺" << p.m_age;
	return cout;
}

void test02()
{
	Person p1(1000, "�����");
	Person p2(500, "��˽�");
	Person p3(400, "ɳɮ");

	MyArray<Person>PersonArray1(3);
	PersonArray1.push_back(p1);
	PersonArray1.push_back(p2);
	PersonArray1.push_back(p3);
	showArray(PersonArray1);
	cout << "PersonArray1�Ĵ�СΪ: " << PersonArray1.getsize() << endl;;
	cout << "PersonArray1������Ϊ: " << PersonArray1.getcapacity() << endl;

	MyArray<Person>PersonArray2(PersonArray1);
	PersonArray2.pop_back();
	PersonArray2[1] = p3;
	showArray(PersonArray2);
	cout << "PersonArray2�Ĵ�СΪ: " << PersonArray2.getsize() << endl;;
	cout << "PersonArray2������Ϊ: " << PersonArray2.getcapacity() << endl;

}

int main()
{
	//test01();
	test02();
	return 0;
}