//#include <iostream>
//
//using namespace std;
//
//class AbstractProducing
//{
//public:
//	virtual void Boil() = 0;
//
//	virtual void AddMaterial() = 0;
//
//	virtual void PourWater() = 0;
//
//	virtual void AddSomething() = 0;
//
//	void Producing()
//	{
//		Boil();
//		AddMaterial();
//		PourWater();
//		AddSomething();
//	}
//};
//
//class MakeTea : public AbstractProducing
//{
//public:
//	void Boil()
//	{
//		cout << "烧开水" << endl;
//	}
//
//	void AddMaterial()
//	{
//		cout << "加茶叶" << endl;
//	}
//
//	void PourWater()
//	{
//		cout << "倒开水" << endl;
//	}
//
//	void AddSomething()
//	{
//		cout << "加枸杞" << endl;
//	}
//};
//
//class MakeCoffee : public AbstractProducing
//{
//public:
//	void Boil()
//	{
//		cout << "烧开水" << endl;
//	}
//
//	void AddMaterial()
//	{
//		cout << "加咖啡" << endl;
//	}
//
//	void PourWater()
//	{
//		cout << "倒开水" << endl;
//	}
//
//	void AddSomething()
//	{
//		cout << "加牛奶" << endl;
//	}
//};
//
//void doWork(AbstractProducing* abs)
//{
//	abs->Producing();
//}
//
//void test01()
//{
//	cout << "泡茶" << endl;
//	doWork(new MakeTea);
//	cout << "-------------" << endl;
//	
//	cout << "冲咖啡" << endl;
//	doWork(new MakeCoffee);
//}
//
//int main()
//{
//	test01();
//
//	return 0;
//}