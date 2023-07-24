#include <iostream>
using namespace std;

template<class T>
class MyArray
{
private:
	int m_Capacity;
	int m_Size;
	T* pAddrass;
public:
	MyArray(int capacity)
	{
			this->m_Capacity = capacity;
			this->m_Size = 0;
			this->pAddrass = new T[capacity];
	}

	MyArray(const MyArray& arr) 
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddrass = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddrass[i] = arr.pAddrass[i];
		}
	}

	MyArray& operator= (const MyArray& arr)
	{
		if (this->pAddrass)
		{
			delete[] pAddrass;
			this->pAddrass = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddrass = new T(m_Capacity);
		for (int i = 0; i < m_Size; i++)
		{
			this->pAddrass[i] = arr.pAddrass[i];
		}
		return *this;
	}

	T& operator[] (int i)
	{
		return this->pAddrass[i];
	}

	void push_back(const T& a)
	{
		if (this->m_Size == this->m_Capacity)
		{
			return;
		}
		else
		{
			this->pAddrass[this->m_Size] = a;
			m_Size++;
		}
	}

	void pop_back()
	{
		if (this->m_Size)
		{
			this->m_Size--;
		}
		else
			return;
	}

	int getsize()
	{
		return this->m_Size;
	}

	int getcapacity()
	{
		return this->m_Capacity;
	}

	~MyArray()
	{
		if (this->pAddrass)
		{
			delete[] this->pAddrass;
			this->pAddrass = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		else
			return;
	}
};
