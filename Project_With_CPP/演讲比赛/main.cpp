#include "Contest.h"

int main()
{
	srand((unsigned int)time(NULL));
	int choice = 0;
	Contest c;
	
	while (true)
	{
		c.menu();
		while (!(cin >> choice))
		{
			cout << "输入错误，请重新输入:> ";
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();
		while (cin.get() != '\n')
			;

		switch (choice)
		{
		case 0:
			return 0;
			break;
		case 1:
			c.process();
			break;
		case 2:
			c.load();
			break;
		case 3:
			c.clear_File();
			break;
		default:
			cout << "选择错误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}