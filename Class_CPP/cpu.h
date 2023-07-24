#pragma once
#include <iostream>

enum CPU_RANK
{
	R3 = 1, i3, R5, i5, R7, i7, R9, i9
};

class CPU
{
private:
	CPU_RANK rank;
	int frequency;
	float voltage;
public:
	CPU(CPU_RANK r, int f, float v);

	~CPU();

	CPU_RANK GetRank();

	int GetFrequency();

	float GetVoltage();
	
	void SetRank(CPU_RANK r);

	void SetFrequency(int f);

	void SetVoltage(float v);

	void Run();
	
	void Stop();

};