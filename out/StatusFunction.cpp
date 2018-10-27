#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
#include "MakeFx.h"
#include "StatusFunction.h"


void orderStatus() { // 주문 확인 
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 매장 주문 확인";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 배달 주문 확인"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 이전"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 4); cout << "=============================" << endl;
		gotoxy(25, 5); cout << "입력 : ";

		cin >> menu;
		if (cin.fail()) // 숫자 이외의 값이 입력 되었을 경우
		{
			cin.clear(); // cin을 비워준다.
			menu = NULL; // menu값에 NULL로 초기화 한다.
		}

		cin.ignore(); // 버퍼를 지운다.
		switch (menu)
		{
		case 1:
			inOrderStatus(); // 매장 주문 확인
			break;
		case 2:
			outOrderStatus(); // 배달 주문 확인
			break;
		case 3:
			return; // 이전
		default:
			break;
		}

	}
}

void inOrderStatus() // 매장 주문 확인
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	sameOrderStatus(fileName);
}

void outOrderStatus() // 배달 주문 확인
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	sameOrderStatus(fileName);
}

void sameOrderStatus(string fileName) // 파일에 따라서 매장 혹은 배달 주문 확인
{
	system("cls");
	int size = 0;
	int ye;
	string buffer[100];
	string *tokName; // 토큰라이저 함수를 사용하기 위한 포인터 변수
	char want[] = "요구 사항 : ";
	ifstream Menus(fileName);
	if (!Menus)
	{
		cout << "오늘 주문한 메뉴가 없습니다.";
		Sleep(2000);
		return;
	}
	while (!Menus.eof()) {
		getline(Menus, buffer[size]);
		if (buffer[size] != "") {
			cout << "주문 " << size + 1 << " : ";
			tokName = StringSplit(buffer[size], "\t");
			for (int i = 0; !tokName[i].empty(); i++) { // tokName[]값이 비어 있을때 까지 반복
				if (strncmp(tokName[i].c_str(), want, 7) != 0) { // tokName[i]값이 7자리를 비교했을 때 want에 저장 되어 있는 값과 일치하는 경우 0을 반환
					cout << tokName[i] << "\t"; // 아닌 경우에는 tokName[i]값을 화면에 출력
				}
				else // 0인 경우 (같은 경우)
				{
					cout << endl << tokName[i]; // 줄 바꿈을 해준 후 화면에 출력
				}
			}
			size++; // size값 ++
			cout << endl << "===============================================================================" << endl;
		}
	}
	while (1) {
		cout << "저장된 내용을 확인하셨습니까? (1 : 다음) >>>";
		cin >> ye;
		if (cin.fail()) // 숫자가 아닌 값이 입력된 경우
		{
			cin.clear(); // cin을 비워준다.
			ye = NULL; //ye값을 NULL로 초기화
		}
		cin.ignore(); // 버퍼를 없앤다.
		if (ye == 1) { // 입력 값이 1인 경우
			system("cls");
			break; //반복문 종료
		}
	}
	Menus.close();//파일 닫기
}

void checkOrderMenu(string fileName) // 요구 사항 내용 확인 x
{
	system("cls");
	int size = 0;
	string buffer[100];
	string *tokName;
	ifstream Menus(fileName); // 읽기 전용 파일 오픈
	if (!Menus) // 파일 오픈 실패시
	{
		cout << "오늘 주문한 메뉴가 없습니다.";
		Sleep(2000); // 2초간 재운다
		return;
	}
	while (!Menus.eof()) { // 파일 끝까지 확인 
		getline(Menus, buffer[size]); // 한줄을 읽어서 buffer[size]에 저장
		if (buffer[size] != "") // buffer[size]값이 ""이 아닌 경우
		{
			cout << "주문 번호 " << size + 1 << " : ";
			tokName = StringSplit(buffer[size], "\t"); // \t 단위로 문자열을 나눠서 tokName에 저장
			for (int i = 0; !tokName[i].empty(); i++) { // tokName[]이 비어있을때 까지 for문 반복
				if (tokName[i] == "O" || tokName[i] == "X") { // 해당 문자열이 O 이거나 X이면
					cout << tokName[i]; // 문자열 출력 후
					break; // 반복문 종료
				}
				else { // 그 외의 경우
					cout << tokName[i] << "\t"; // 문자열 출력
				}
			}
			size++; // size값 ++
			cout << endl << "===============================================================================" << endl;
		}
	}
}
