#include <iostream>
#include <Windows.h>

using namespace std;

class CPU
{
public:
	virtual void Calculate() = 0;

	virtual ~CPU() = 0;
};

CPU::~CPU()
{
	//cout << "析构了一个CPU!" << endl;
}

class GPU
{
public:
	virtual void ShowGraphic() = 0;

	virtual ~GPU() = 0;
};

GPU::~GPU()
{
	//cout << "析构了一个GPU!" << endl;
}

class Memory
{
public:
	virtual void Storage() = 0;

	virtual ~Memory() = 0;
};

Memory::~Memory()
{
	//cout << "析构了一个内存条!" << endl;
}

class Intel : public CPU
{
public:
	void Calculate()
	{
		cout << "英特尔CPU开始运行!" << endl;
	}

	~Intel()
	{
		cout << "析构了一个英特尔CPU!" << endl;
	}
};

class AMDCPU : public CPU
{
public:
	void Calculate()
	{
		cout << "AMDCPU开始运行!" << endl;
	}

	~AMDCPU()
	{
		cout << "析构了一个AMDCPU!" << endl;
	}
};

class Nvdia : public GPU
{
public:
	void ShowGraphic()
	{
		cout << "英伟达GPU开始运行!" << endl;
	}

	~Nvdia()
	{
		cout << "析构了一个英伟达GPU!" << endl;
	}
};

class AMDGPU : public GPU
{
public:
	void ShowGraphic()
	{
		cout << "AMDGPU开始运行!" << endl;
	}

	~AMDGPU()
	{
		cout << "析构了一个AMDGPU!" << endl;
	}
};

class Lenovo : public Memory
{
public:
	void Storage()
	{
		cout << "联想内存条开始运行!" << endl;
	}

	~Lenovo()
	{
		cout << "析构了一个联想内存条!" << endl;
	}
};

class Computer
{
private:
	CPU* m_cpu;
	GPU* m_gpu;
	Memory* m_mem;
public:
	Computer(CPU* cpu, GPU* gpu, Memory* mem)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_mem = mem;
	}

	void Run()
	{
		cout << "电脑开始运行!" << endl;
		m_cpu->Calculate();
		m_gpu->ShowGraphic();
		m_mem->Storage();
		Sleep(2000);
		system("cls");
		cout << "电脑运行中...";
		Sleep(1000);
	}

	~Computer()
	{
		system("cls");
		cout << "关机中..." << endl;
		Sleep(500);
		system("cls");

		delete m_cpu;
		delete m_gpu;
		delete m_mem;
	}
};

void Assembled(CPU* cpu, GPU* gpu, Memory* mem)
{
	Computer* m_Computer = new Computer(cpu, gpu, mem);
	cout << "电脑组装完成!" << endl;
	m_Computer->Run();
	delete m_Computer;
}

void test01()
{
	CPU* cpu1 = new Intel;
	GPU* gpu1 = new Nvdia;
	Memory* mem1 = new Lenovo;

	Assembled(cpu1, gpu1, mem1);

	CPU* cpu2 = new AMDCPU;
	GPU* gpu2 = new AMDGPU;
	Memory* mem2 = new Lenovo;

	Assembled(cpu2, gpu2, mem2);
}

int main()
{
	test01();

	return 0;
}