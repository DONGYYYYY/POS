#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
#include "MakeFx.h"
#include "StoreFunction.h"
#include "StatusFunction.h"


void storeStatus() // 가계 상황
{
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 완료된 주문 확인";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 당일 매출액"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 해당 달 총 매출액"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : 컴플레인"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 : 이전"; gotoxy(48, 5); cout << "|" << endl;
		gotoxy(20, 6); cout << "=============================" << endl;
		gotoxy(25, 7); cout << "입력 : ";
		cin >> menu;
		if (cin.fail())
		{
			menu = -1;
			cin.clear();
		}
		cin.ignore();
		switch (menu)
		{
		case 1:
			checkSellMenu(); // 완료된 주문 확인
			break;
		case 2:
			checkTotalPrice(); // 당일 매출액
			break;
		case 3:
			MonthSellPrice(); // 해당 달 총 매출액
			break;
		case 4:
			checkComplain(); // 컴플레인 
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}

void checkTotalPrice() // 총 판매액 확인
{
	system("cls");
	int ye;
	string priceFile = "C:\\";
	priceFile += currentDate();
	priceFile += "-sales.txt";
	ifstream Sell(priceFile, ios::in);
	if (!Sell) // 파일 오픈 실패시
	{
		cout << "당일 매출이 없습니다.";
		Sleep(2000);
		return;
	}
	int totalPrice;
	string buffer;
	getline(Sell, buffer); // 한줄을 읽어온다.
	totalPrice = atoi(buffer.c_str()); // totalPrice에 문자열을 정수로 변환하는 atoi를 사용하여 값을 저장한다
	cout << "오늘 판매액 : " << totalPrice << endl; // 콘솔창에 출력
	cout << "계산을 마치겠습니까?" << endl;
	cin >> ye;
	cin.ignore(); // 버퍼 지우기
	Sell.close();//파일 닫기
}
void MonthSellPrice() // 해당 달 총 매출액
{
	/* 현재 날짜를 알기 위해서 사용하는 time관련 함수 */
	time_t now = time(0);
	struct tm tstruct;
	char day[80];
	tstruct = *localtime(&now);
	strftime(day, sizeof(day), "%d", &tstruct); // tstruct에서 %d에 해당하는 값은 day(일)이다.
	int howday = atoi(day);

	system("cls");
	int ye;
	string dayFile = "C:\\";
	dayFile += currentDate();
	dayFile += "-sales.txt";
	ifstream daySell(dayFile);

	if (!daySell) // 파일 오픈 실패 시
	{
		cout << "당일 매출이 없습니다.";
		Sleep(2000);
		return;
	}
	int dayPrice;
	string buffer;
	getline(daySell, buffer);
	dayPrice = atoi(buffer.c_str());
	string priceFile = "C:\\";
	priceFile += currentMonth();
	priceFile += "-sales.txt";
	ifstream Sell(priceFile); // 읽기 전용으로 파일 오픈
	if (!Sell) // 파일 오픈 실패 시
	{
		cout << "이번 달 매출이 없습니다.";
		Sleep(2000);
		return;
	}
	int totalPrice;
	getline(Sell, buffer); // 해당 파일 한줄 읽기
	totalPrice = atoi(buffer.c_str()); // 문자열값을 정수형으로 바꿔서 totalPrice 변수에 값을 저장.
	cout << "이번 달 총 매출액 : " << totalPrice << endl;
	cout << endl << "===============================================================================" << endl;
	cout << "이번 달 평균 매출액 : " << totalPrice / howday << endl;
	cout << endl << "===============================================================================" << endl;
	cout << "이번 달 평균 매출액과 당일 매출액 비교 : " << dayPrice - (totalPrice / howday) << endl;
	cout << endl << "===============================================================================" << endl;
	cout << "계산을 마치겠습니까?" << endl;
	cin >> ye;
	if (cin.fail()) //입력값이 정수가 아닌경우
	{
		cin.clear(); // clear를 통해서 cin안의 입력값을 초기화
	}
	cin.ignore(); // cin의 버퍼를 지워준다
	Sell.close(); // 파일 닫기
}

void checkSellMenu() // 완료 주문 확인 기능
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 매장 완료 주문 확인";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 배달 완료 주문 확인"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 이전"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "=============================" << endl;
		gotoxy(25, 5); cout << "입력 : ";
		cin >> menu;
		if (cin.fail())
		{
			cin.clear();
			menu = -1;
		}
		cin.ignore();
		switch (menu)
		{
		case 1:
			inOrderCheckSellMenu(); // 매장 완료 주문 확인
			break;
		case 2:
			outOrderCheckSellMenu(); // 배달 완료 주문 확인
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}


void inOrderCheckSellMenu() // 매장 주문 완료 확인
{
	string completeName = "C:\\";
	completeName += currentDate();
	completeName += "-completeInOrder.txt";
	sameCheckSellMenu(completeName);
}
void outOrderCheckSellMenu() // 배달 주문 완료 확인
{
	string completeName = "C:\\";
	completeName += currentDate();
	completeName += "-completeOutOrder.txt";
	sameCheckSellMenu(completeName);
}
void sameCheckSellMenu(string fileName) // 파일 이름에 따라서 매장 , 배달 주문 완료 확인
{
	system("cls");
	int size = 0;
	int ye;
	string buffer[100];

	ifstream Menus(fileName); // 파일 읽기 전용으로 오픈
	if (!Menus) // 파일 오픈 실패시
	{
		cout << "오늘 주문한 메뉴가 없습니다.";
		Sleep(2000);
		return;
	}
	while (!Menus.eof()) {
		getline(Menus, buffer[size]); // 파일 한줄 씩 읽어서 buffer[size]에 값을 저장
		if (buffer[size] != "") { // buffer[size]값이 ""이 아닌 경우
			cout << "완료된 주문 " << size + 1 << "\t메뉴 이름 : " << buffer[size] << endl;
			cout << "===============================================================================" << endl;
			size++; // 다음 저장공간을 가르키기 위해서 size값 ++
		}
	}
	while (1) {
		cout << "저장된 내용을 확인하셨습니까? (1 : 다음) >>>";
		cin >> ye;
		if (ye == 1) {
			system("cls");
			break;
		}
	}
	Menus.close(); // 파일 닫기
}


void checkComplain() // 컴플레인
{
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 컴플레인 확인";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 컴플레인 작성"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 컴플레인 초기화"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : 이전"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "=============================" << endl;
		gotoxy(25, 6); cout << "입력 : ";
		cin >> menu;
		if (cin.fail()) // 입력 값에 정수가 아닌 값이 들어온 경우
		{
			cin.clear(); // cin을 비워준다.
			menu = NULL; // menu값에 NULL로 초기화 한다.
		}
		cin.ignore(); // 버퍼를 지워준다.
		switch (menu)
		{
		case 1:
			readComplain(); // 컴플레인 확인
			break;
		case 2:
			writeComplain(); // 컴플레인 작성
			break;
		case 3:
			resetComplain(); // 컴플레인 초기화
			break;
		case 4:
			return; // 이전
		default:
			break;
		}
	}
}

void readComplain() // 컴플레인 읽기
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "====================================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(23, 1); cout << "1 : 카운터 관련 컴플레인 읽기";		gotoxy(55, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(23, 2); cout << "2 : 주방 관련 컴플레인 읽기"; gotoxy(55, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(23, 3); cout << "3 : 이전"; gotoxy(55, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "====================================" << endl;
		gotoxy(25, 5); cout << "입력 : ";
		cin >> menu;
		if (cin.fail())
		{
			cin.clear(); // cin을 비워준다.
			menu = NULL; // menu값에 NULL로 초기화 한다.
		}
		cin.ignore();
		switch (menu)
		{
		case 1:
			inReadComplain(); // 카운터 관련 컴플레인 읽기
			break;
		case 2:
			outReadComplain(); // 주방 관련 컴플레인 읽기
			break;
		case 3:
			return; // 이전
		default:
			break;
		}
	}
}

void writeComplain() // 컴플레인 쓰기
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "====================================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(23, 1); cout << "1 : 카운터 관련 컴플레인 쓰기";		gotoxy(55, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(23, 2); cout << "2 : 주방 관련 컴플레인 쓰기"; gotoxy(55, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(23, 3); cout << "3 : 이전"; gotoxy(55, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "====================================" << endl;
		gotoxy(25, 5); cout << "입력 : ";
		cin >> menu;
		if (cin.fail())
		{
			cin.clear(); // 에러 플래그를 초기화. cin.fail을 초기화 하여 무한 반복되는 현상 없앰.
			menu = NULL; // menu값에 NULL로 초기화 한다.
		}
		cin.ignore(); // 버퍼를 지운다
		switch (menu)
		{
		case 1:
			inWriteComplain(); // 카운터 관련 컴플레인 쓰기
			break;
		case 2:
			outWriteComplain(); // 주방 관련 컴플레인 쓰기
			break;
		case 3:
			return; // 이전
		default:
			break;
		}
	}
}

void inReadComplain() // 카운터 관련 컴플레인 읽기
{
	string fileName;
	fileName = "C:\\inComplain.txt";
	sameReadComplain(fileName);
}
void outReadComplain() // 주방 관련 컴플레인 읽기
{
	string fileName;
	fileName = "C:\\outComplain.txt";
	sameReadComplain(fileName);
}
void sameReadComplain(string fileName) // 매개변수인 파일 명에 따라서 카운터 , 주방 컴플레인 읽기 작업
{
	system("cls");
	string buffer;
	ifstream complain(fileName); // 파일 읽기 전용으로 오픈
	if (!complain) // 파일 오픈 실패 시
	{
		cout << "컴플레인 파일이 존재하지 않습니다.";
		Sleep(1000);
		return;
	}
	while (!complain.eof()) // 파일 끝까지 읽기( 끝일 경우 반복문 탈출 )
	{
		getline(complain, buffer); // buffer에 파일 내용 저장
		if (buffer != "") {
			cout << buffer << endl; // 파일 내용 출력
			cout << "===============================================================================" << endl;
		}
	}
	cout << "컴플레인을 확인하셨습니까?";
	int ye;
	cin >> ye;
	cin.ignore(); // 버퍼 지우기
	complain.close(); // 파일 닫기
}

void inWriteComplain() // 카운터 컴플레인 쓰기
{
	string fileName;
	fileName = "C:\\inComplain.txt";
	sameWriteComplain(fileName);
}
void outWriteComplain() // 주방 컴플레인 쓰기
{
	string fileName;
	fileName = "C:\\outComplain.txt";
	sameWriteComplain(fileName);
}
void sameWriteComplain(string fileName) // 파일 명에 따라서 카운터 , 주방 컴플레인 작성 작업
{
	system("cls");
	string buffer;
	ofstream complain(fileName, ios::app); // 파일 쓰기 전용으로 오픈 ( ios::app 는 기존 파일에서 이어서 파일을 쓰는 옵션 (덧붙이기))
	while (1) // 무한 반복
	{
		cout << "내용을 입력하세요 : ( 종료 == 0 )";
		getline(cin, buffer); // 문자열을 콘솔창으로 부터 입력 받는다.
		if (buffer == "0") // 입력 받은 값이 0일 경우
		{
			break; // 반복문 탈출
		}
		else // 그 외의 경우
		{
			complain << buffer << endl; // 입력 내용을 파일에 쓰고 줄바꿈을 한다.
		}
	}
	complain.close(); // 파일 닫기
}


void resetComplain() // 컴플레인 초기화 메뉴
{
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "====================================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(23, 1); cout << "1 : 카운터 관련 컴플레인 초기화";		gotoxy(55, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(23, 2); cout << "2 : 주방 관련 컴플레인 초기화"; gotoxy(55, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(23, 3); cout << "3 : 이전"; gotoxy(55, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "====================================" << endl;
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
			resetInComplain(); // 카운터 관련 컴플레인 초기화
			break;
		case 2:
			resetOutComplain(); // 주방 관련 컴플레인 초기화
			break;
		case 3:
			return; // 이전
		default:
			break;
		}
	}
}
void resetInComplain() // 카운터 관련 컴플레인 초기화
{
	string fileName;
	fileName = "C:\\inComplain.txt";
	sameWriteComplain(fileName);
}

void resetOutComplain() // 주방 관련 컴플레인 초기화
{
	string fileName;
	fileName = "C:\\outComplain.txt";
	sameWriteComplain(fileName);
}

void resetSameComplain(string fileName) // 매개변수인 파일명에 따라서 카운터 , 주방 관련 컴플레인 초기화 작업
{
	system("cls");
	ofstream complain(fileName, ios::trunc); // 읽기 전용으로 파일 오픈 (ios::trunc = 파일이 존재할 경우 새로 파일을 만든다.(덮어쓰기))
	complain.close(); // 파일을 닫는다.
	cout << "컴플레인 파일 초기화 완료";
	Sleep(1000);
}
