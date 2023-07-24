#include "checkInput.h"

void checkInput(int& choice)
{
	while (!(std::cin >> choice))
	{
		std::cout << "输入错误，请重新输入:> ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			;
	}
	std::cin.clear();
	while (std::cin.get() != '\n')
		;
}

void checkInput(int& choice, const int& size)
{
	checkInput(choice);
	while (choice < 1 || choice > size)
	{
		std::cout << "输入错误，请重新输入:> ";
		checkInput(choice);
	}
}