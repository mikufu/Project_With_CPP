#include <iostream>

using namespace std;

class MyPrint
{
public:
	void operator() (const string& text)
	{
		cout << text << endl;
	}
};

class Add
{
public:
	int operator() (const int& num1, const int& num2)
	{
		return num1 + num2;
	}
};

int main()
{
	MyPrint print;

	print("hello world!");

	Add plus;
	int ret = plus(12, 94);

	cout << ret << endl;
	//匿名函数对象
	cout << Add()(12, 94) << endl;

	return 0;
}