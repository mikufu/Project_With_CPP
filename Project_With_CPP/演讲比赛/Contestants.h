#ifndef _CONTESTANTS
#define _CONTESTANTS
#include <iostream>

class Contestants
{
private:
	int m_ID;
	std::string m_name;
	double m_score;
public:
	Contestants() { m_ID = 0; m_score = 0; }

	Contestants(int ID, std::string name, double m_score);

	void SetScore(double score);

	int GetID();

	std::string GetName();

	double GetSocre();

	bool operator> (Contestants& c);
};

#endif