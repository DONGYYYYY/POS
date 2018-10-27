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


void mainPrint() // 시작 메뉴 다음 메뉴로 이동 스위치 케이스 문
{
	int menu;
	while (1) {
		system("cls");
		menu = checkMain();
		switch (menu) {
		case 1:
			orderMenu(); // 주문현황
			break;
		case 2:
			orderStatus(); // 주문 현황
			break;
		case 3:
			payMenu(); // 계산
			break;
		case 4:
			storeStatus(); // 계산 현황
			break;
		case 5:
			checkMenu(); // 메뉴
			break;
		case 6:
			system("cls");
			cout << "장사를 종료합니다." << endl;
			exit(0);
		default:
			system("cls");
		}
	}
}


int checkMain() // 시작 메뉴
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 콘솔 text 색상 변경
	gotoxy(20, 0); cout << "=============================" << endl;
	gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 :   주문";		gotoxy(48, 1); cout << "|" << endl;
	gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 주문 현황"; gotoxy(48, 2); cout << "|" << endl;
	gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 :   계산";		gotoxy(48, 3); cout << "|" << endl;
	gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : 가계 현황"; gotoxy(48, 4); cout << "|" << endl;
	gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 :   메뉴"; gotoxy(48, 5); cout << "|" << endl;
	gotoxy(20, 6); cout << "|"; gotoxy(25, 6); cout << "6 :   종료"; gotoxy(48, 5); cout << "|" << endl;
	gotoxy(20, 7); cout << "=============================" << endl;
	gotoxy(25, 8); cout << "입력 : ";
	int menu;
	cin >> menu;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore();
	return menu; // 입력 값 반환
}
