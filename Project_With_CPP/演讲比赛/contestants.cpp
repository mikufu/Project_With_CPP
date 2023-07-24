#include "Contestants.h"

Contestants::Contestants(int ID, std::string name, double score)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_score = score;
}

void Contestants::SetScore(double score)
{
	this->m_score = score;
}

int Contestants::GetID()
{
	return this->m_ID;
}

std::string Contestants::GetName()
{
	return this->m_name;
}

double Contestants::GetSocre()
{
	return this->m_score;
}

bool Contestants::operator> (Contestants& c)
{
	return this->m_score > c.m_score;
}