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
	//cout << "������һ��CPU!" << endl;
}

class GPU
{
public:
	virtual void ShowGraphic() = 0;

	virtual ~GPU() = 0;
};

GPU::~GPU()
{
	//cout << "������һ��GPU!" << endl;
}

class Memory
{
public:
	virtual void Storage() = 0;

	virtual ~Memory() = 0;
};

Memory::~Memory()
{
	//cout << "������һ���ڴ���!" << endl;
}

class Intel : public CPU
{
public:
	void Calculate()
	{
		cout << "Ӣ�ض�CPU��ʼ����!" << endl;
	}

	~Intel()
	{
		cout << "������һ��Ӣ�ض�CPU!" << endl;
	}
};

class AMDCPU : public CPU
{
public:
	void Calculate()
	{
		cout << "AMDCPU��ʼ����!" << endl;
	}

	~AMDCPU()
	{
		cout << "������һ��AMDCPU!" << endl;
	}
};

class Nvdia : public GPU
{
public:
	void ShowGraphic()
	{
		cout << "Ӣΰ��GPU��ʼ����!" << endl;
	}

	~Nvdia()
	{
		cout << "������һ��Ӣΰ��GPU!" << endl;
	}
};

class AMDGPU : public GPU
{
public:
	void ShowGraphic()
	{
		cout << "AMDGPU��ʼ����!" << endl;
	}

	~AMDGPU()
	{
		cout << "������һ��AMDGPU!" << endl;
	}
};

class Lenovo : public Memory
{
public:
	void Storage()
	{
		cout << "�����ڴ�����ʼ����!" << endl;
	}

	~Lenovo()
	{
		cout << "������һ�������ڴ���!" << endl;
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
		cout << "���Կ�ʼ����!" << endl;
		m_cpu->Calculate();
		m_gpu->ShowGraphic();
		m_mem->Storage();
		Sleep(2000);
		system("cls");
		cout << "����������...";
		Sleep(1000);
	}

	~Computer()
	{
		system("cls");
		cout << "�ػ���..." << endl;
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
	cout << "������װ���!" << endl;
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