#include "cpu.h"

CPU::CPU(CPU_RANK r, int f, float v) : rank(r), frequency(f), voltage(v)
{
	std::cout << "������һ��CPU�࣡" << std::endl;
}

CPU::~CPU()
{
	std::cout << "������һ��CPU�࣡" << std::endl;
}

CPU_RANK CPU::GetRank() { return rank; }

int CPU::GetFrequency() { return frequency; }

float CPU::GetVoltage() { return voltage; }

void CPU::SetRank(CPU_RANK r) { rank = r; }

void CPU::SetFrequency(int f) { frequency = f; }

void CPU::SetVoltage(float v) { voltage = v; }

void CPU::Run() { std::cout << "CPU��ʼ���У�" << std::endl; }

void CPU::Stop() { std::cout << "CPUֹͣ���У�" << std::endl; }