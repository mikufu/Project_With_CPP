#include <iostream>
#include <deque>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

class Person
{
private:
	string m_name;
	double m_score;

public:
	Person(string name, double score)
	{
		m_name = name;
		m_score = score;
	}

	double GetScore()
	{
		return m_score;
	}

	string GetName()
	{
		return m_name;
	}
};

double GetAveScore()
{
	deque<int> s;
	for (int i = 0; i < 10; i++)
	{
		s.push_back(rand() % 101);
	}
	sort(s.begin(), s.end());
	s.pop_front();
	s.pop_back();
	double ave = 0.0;
	for (deque<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		ave += (* it) * 0.125;
	}
	return ave;
}

void printInfo(const deque<Person*>& dq)
{
	for (deque<Person*>::const_iterator it = dq.begin(); it != dq.end(); it++)
	{
		cout << "ѡ�֣�" << (*it)->GetName() << "\t�÷�" << (*it)->GetScore() << endl;
	}
}

void Score()
{
	deque<Person*> dq;
	dq.push_back(new Person("����", GetAveScore()));
	dq.push_back(new Person("����", GetAveScore()));
	dq.push_back(new Person("����", GetAveScore()));
	dq.push_back(new Person("����", GetAveScore()));
	dq.push_back(new Person("����", GetAveScore()));

	printInfo(dq);
}

int main()
{
	srand((unsigned int)time(NULL));
	Score();

	return 0;
}