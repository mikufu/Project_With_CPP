#include "workermanagement.h"

int main()
{
	WorkerManage wm;
	int input = 0;
	
	while (true)
	{
		wm.showmenu();
		cout << "��ѡ��Ҫʹ�õĹ���:> ";
		while (!(cin >> input))	//��ֹ�����ʽ����
		{
			cout << "�����������������!" << endl;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cin.clear();		//�����������ַ�
		while (cin.get() != '\n')
			;

		switch (input)
		{
		case 0:	//�˳�ϵͳ
			wm.save();
			return 0;
			break;
		case 1:	//����ְ��
			wm.Add_Emp();
			break;
		case 2:	//��ʾְ��
			wm.showInfo();
			break;
		case 3:	//ɾ��ְ��
			wm.del_Emp();
			break;
		case 4:	//�޸���Ϣ
			wm.modify();
			break;
		case 5:	//����ְ��
			wm.search_Emp();
			break;
		case 6:	//�������
			wm.sort_Emp();
			break;
		case 7:	//����ĵ�
			wm.clear_File();
			break;
		default:
		{
			cout << "�����������������!" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
	}

	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	return 0;
}