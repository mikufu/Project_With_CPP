#ifndef _CONTEST
#define _CONTEST
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
#include "Contestants.h"

class Contest
{
private:
	vector<Contestants> v;

public:
	Contest();

	void menu();

	void ShowContestants(vector<Contestants>::iterator beg, vector<Contestants>::iterator end);

	void process();

	void save();

	void load();

	void clear_File();

	bool FileIsEmpty();
};

#endif