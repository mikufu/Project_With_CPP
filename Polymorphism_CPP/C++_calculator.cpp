//#include <iostream>
//using namespace std;
//
//class AbstractCalculator
//{
//public:
//	double num1 = 0.0;
//	double num2 = 0.0;
//	virtual double GetResult() 
//	{
//		return 0;
//	}
//};
//
//class AddCalculator : public AbstractCalculator
//{
//public:
//	double GetResult()
//	{
//		return num1 + num2;
//	}
//};
//
//class SubCalculator : public AbstractCalculator
//{
//public:
//	double GetResult()
//	{
//		return num1 - num2;
//	}
//};
//
//class MulCalculator : public AbstractCalculator
//{
//public:
//	double GetResult()
//	{
//		return num1 * num2;
//	}
//};
//
//class DivCalculator : public AbstractCalculator
//{
//public:
//	double GetResult()
//	{
//		return num1 / num2;
//	}
//};
//
//void test01()
//{
//	AbstractCalculator* cal = new AddCalculator;
//	cal->num1 = 2.4;
//	cal->num2 = 6.2;
//	cout << cal->num1 << " + " << cal->num2 << " = " << cal->GetResult() << endl;
//	delete cal;
//	
//	cal = new SubCalculator;
//	cal->num1 = 2.4;
//	cal->num2 = 6.2;
//	cout << cal->num1 << " - " << cal->num2 << " = " << cal->GetResult() << endl;
//	delete cal;
//
//	cal = new MulCalculator;
//	cal->num1 = 2.4;
//	cal->num2 = 6.2;
//	cout << cal->num1 << " * " << cal->num2 << " = " << cal->GetResult() << endl;
//	delete cal;
//
//	cal = new DivCalculator;
//	cal->num1 = 2.4;
//	cal->num2 = 6.2;
//	cout << cal->num1 << " / " << cal->num2 << " = " << cal->GetResult() << endl;
//	delete cal;
//
//}

//int main()
//{
//	test01();
//
//	return 0;
//}
