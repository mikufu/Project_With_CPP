#include "system.h"

int main()
{
	int choice = 0;
	System s;
	do
	{
		s.MainMenu();
		checkInput(choice);
		switch (choice)
		{
		case 1:
			s.StuSystem();
			break;
		case 2:
			s.TeaSystem();
			break;
		case 3:
			s.AdmSystem();
			break;
		case 0:
			break;
		default:
			std::cout << "输入错误！" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	} while (choice);
	std::cout << "欢迎下次使用！" << std::endl;
	system("pause");
	return 0;
}