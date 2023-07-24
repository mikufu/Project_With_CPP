#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

enum Number		//部门编号
{
	Mastermind, Arts, Tech
};

class Worker	//员工类
{
private:
	string m_name;
	int m_salary;
public:
	Worker(string name, int salary)
	{
		this->m_name = name;
		this->m_salary = salary;
	}

	string GetName()
	{
		return m_name;
	}

	int GetSalary()
	{
		return m_salary;
	}
};

void CreateWorkerVector(vector<Worker>& v)
{
	for (int i = 0; i < 7; i++)		//构建员工类的vector容器
	{
		string name = string("员工");
		name += 'A' + i;
		int salary = rand() % 10000 + 10000;
		Worker w(name, salary);
		v.push_back(w);
	}
}

void CreateWorekrMap(multimap<Number, Worker>& m, vector<Worker>& v)
{
	for (int i = 0; i < 7; i++)		//用map来存放员工部门和员工类
	{
		Number n = (Number)(rand() % 3);
		m.insert(make_pair(n, v[i]));
	}
}

void PrintWorkerMap(multimap<Number, Worker>& m)	//打印各个员工所属部门的各个员工
{
	multimap<Number, Worker>::iterator it = m.find(Mastermind);
	int count = (int)m.count(Mastermind);
	cout << "策划部门:>" << endl;
	for (int index = 0; it != m.end() && index < count; it++, index++)
	{
		cout << "员工:> " << it->second.GetName()
			<< "\t薪水:> " << (*it).second.GetSalary()
			<< endl;
	}
	cout << endl;
	it = m.find(Arts);
	count = (int)m.count(Arts);
	cout << "美术部门:>" << endl;
	for (int index = 0; it != m.end() && index < count; it++, index++)
	{
		cout << "员工:> " << it->second.GetName()
			<< "\t薪水:> " << (*it).second.GetSalary()
			<< endl;
	}
	cout << endl;
	it = m.find(Tech);
	count = (int)m.count(Tech);
	cout << "技术部门:>" << endl;
	for (int index = 0; it != m.end() && index < count; it++, index++)
	{
		cout << "员工:> " << it->second.GetName()
			<< "\t薪水:> " << (*it).second.GetSalary()
			<< endl;
	}
	cout << endl;
}

void test01()
{
	vector<Worker> v;
	multimap<Number, Worker> m;
	CreateWorkerVector(v);
	CreateWorekrMap(m, v);
	PrintWorkerMap(m);
}

int main()
{
	srand((unsigned int)time(NULL));
	test01();

	return 0;
}