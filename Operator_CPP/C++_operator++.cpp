//#include <iostream>
//
//using namespace std;
//
//class MyInteger
//{
//	friend ostream& operator<< (ostream& cout, MyInteger i);
//
//private:
//	int integer;
//
//public:
//	MyInteger() : integer(0) { };
//
//	MyInteger& operator++ ()
//	{
//		integer++;
//		return *this;
//	}
//
//	MyInteger operator++ (int)
//	{
//		MyInteger tmp = *this;
//		integer++;
//		return tmp;
//	}
//
//};
//
//ostream& operator<< (ostream& cout, MyInteger i)	//使用&则无法使用i++
//{
//	cout << i.integer;
//	return cout;
//}
//
//int main()
//{
//	MyInteger i;
//	cout << i << endl;
//	cout << ++i << endl;
//	cout << i++ << endl;
//	cout << i << endl;
//
//	return 0;
//}