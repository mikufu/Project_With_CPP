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
//		cout << "�տ�ˮ" << endl;
//	}
//
//	void AddMaterial()
//	{
//		cout << "�Ӳ�Ҷ" << endl;
//	}
//
//	void PourWater()
//	{
//		cout << "����ˮ" << endl;
//	}
//
//	void AddSomething()
//	{
//		cout << "�����" << endl;
//	}
//};
//
//class MakeCoffee : public AbstractProducing
//{
//public:
//	void Boil()
//	{
//		cout << "�տ�ˮ" << endl;
//	}
//
//	void AddMaterial()
//	{
//		cout << "�ӿ���" << endl;
//	}
//
//	void PourWater()
//	{
//		cout << "����ˮ" << endl;
//	}
//
//	void AddSomething()
//	{
//		cout << "��ţ��" << endl;
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
//	cout << "�ݲ�" << endl;
//	doWork(new MakeTea);
//	cout << "-------------" << endl;
//	
//	cout << "�忧��" << endl;
//	doWork(new MakeCoffee);
//}
//
//int main()
//{
//	test01();
//
//	return 0;
//}