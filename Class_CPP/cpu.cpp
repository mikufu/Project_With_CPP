#include "cpu.h"

CPU::CPU(CPU_RANK r, int f, float v) : rank(r), frequency(f), voltage(v)
{
	std::cout << "构造了一个CPU类！" << std::endl;
}

CPU::~CPU()
{
	std::cout << "析构了一个CPU类！" << std::endl;
}

CPU_RANK CPU::GetRank() { return rank; }

int CPU::GetFrequency() { return frequency; }

float CPU::GetVoltage() { return voltage; }

void CPU::SetRank(CPU_RANK r) { rank = r; }

void CPU::SetFrequency(int f) { frequency = f; }

void CPU::SetVoltage(float v) { voltage = v; }

void CPU::Run() { std::cout << "CPU开始运行！" << std::endl; }

void CPU::Stop() { std::cout << "CPU停止运行！" << std::endl; }