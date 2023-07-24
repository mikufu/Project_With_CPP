#include "workermanagement.h"

int main()
{
	WorkerManage wm;
	int input = 0;
	
	while (true)
	{
		wm.showmenu();
		cout << "请选择要使用的功能:> ";
		while (!(cin >> input))	//防止输入格式错误
		{
			cout << "输入错误，请重新输入!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//清除多输入的字符
		while (cin.get() != '\n')
			;

		switch (input)
		{
		case 0:	//退出系统
			wm.save();
			return 0;
			break;
		case 1:	//增加职工
			wm.Add_Emp();
			break;
		case 2:	//显示职工
			wm.showInfo();
			break;
		case 3:	//删除职工
			wm.del_Emp();
			break;
		case 4:	//修改信息
			wm.modify();
			break;
		case 5:	//查找职工
			wm.search_Emp();
			break;
		case 6:	//编号排序
			wm.sort_Emp();
			break;
		case 7:	//清空文档
			wm.clear_File();
			break;
		default:
		{
			cout << "输入错误，请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}

	cout << "欢迎下次使用!" << endl;
	system("pause");
	return 0;
}