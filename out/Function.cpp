#include "Myheader.h"
#include "Function.h"
#include "Menu.h"
#include "MakeFx.h"
#include "MenuFunction.h"
#include "OrderFunction.h"
#include "PayFunction.h"
#include "StatusFunction.h"
#include "StoreFunction.h"

extern Menu *obj;


void mainPrint() // ���� �޴� ���� �޴��� �̵� ����ġ ���̽� ��
{
	int menu;
	while (1) {
		system("cls");
		menu = checkMain();
		switch (menu) {
		case 1:
			orderMenu(); // �ֹ���Ȳ
			break;
		case 2:
			orderStatus(); // �ֹ� ��Ȳ
			break;
		case 3:
			payMenu(); // ���
			break;
		case 4:
			storeStatus(); // ��� ��Ȳ
			break;
		case 5:
			checkMenu(); // �޴�
			break;
		case 6:
			system("cls");
			cout << "��縦 �����մϴ�." << endl;
			exit(0);
		default:
			system("cls");
		}
	}
}


int checkMain() // ���� �޴�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // �ܼ� text ���� ����
	gotoxy(20, 0); cout << "=============================" << endl;
	gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 :   �ֹ�";		gotoxy(48, 1); cout << "|" << endl;
	gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : �ֹ� ��Ȳ"; gotoxy(48, 2); cout << "|" << endl;
	gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 :   ���";		gotoxy(48, 3); cout << "|" << endl;
	gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : ���� ��Ȳ"; gotoxy(48, 4); cout << "|" << endl;
	gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 :   �޴�"; gotoxy(48, 5); cout << "|" << endl;
	gotoxy(20, 6); cout << "|"; gotoxy(25, 6); cout << "6 :   ����"; gotoxy(48, 5); cout << "|" << endl;
	gotoxy(20, 7); cout << "=============================" << endl;
	gotoxy(25, 8); cout << "�Է� : ";
	int menu;
	cin >> menu;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore();
	return menu; // �Է� �� ��ȯ
}
