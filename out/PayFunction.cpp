#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
#include "MakeFx.h"
#include "PayFunction.h"
#include "StatusFunction.h"

extern Menu *obj;

void payMenu() // 계산 기능
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 매장 주문 계산";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 배달 주문 계산"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 처음으로"; gotoxy(48, 4); cout << "|" << endl;
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
			inPayMenu();
			break;
		case 2:
			outPayMenu();
			break;
		case 3:
			return;
		default:
			break;
		}

	}
}
void inPayMenu() // 매장 주문 계산
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	string completeName = "C:\\";
	completeName += currentDate();
	completeName += "-completeInOrder.txt";
	samePayMenu(fileName, completeName);
}
void outPayMenu() // 배달 주문 계산
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	string completeName = "C:\\";
	completeName += currentDate();
	completeName += "-completeOutOrder.txt";
	samePayMenu(fileName, completeName);
}

void samePayMenu(string fileName, string completeName) // 파일 내용에 따라서 매장 , 배달 주문 계산
{
	bool complete = false;
	int size = 0;
	int ye;
	int soldMoney;
	int temp;
	string tempBuffer;
	string buffer[100];
	string name[100];
	string *tokName;
	string *tempTok;
	int find = 0;
	int count = 0;
	//일 매출에 해당하는 파일
	string priceFile = "C:\\";
	priceFile += currentDate();
	priceFile += "-sales.txt";

	//월 매출에 해당하는 파일
	string MonthSale = "C:\\";
	MonthSale += currentMonth();
	MonthSale += "-sales.txt";

	ifstream Menus(fileName); // 일기 전용으로 파일 오픈
	while (!Menus.eof()) { // 파일 끝까지 읽기
		system("cls");
		getline(Menus, buffer[size]);
		name[size] = buffer[size];
		if (name[size] != "") {
			tokName = StringSplit(name[size], "\t");
			for (int i = 0; !tokName[i].empty(); i++) {
				if (tokName[i] == "O" && complete == false) { // 해당 토큰이 O이고 complete가 false인 경우
					cout << name[size]; //해당 주문 번호에 해당하는 메뉴 내용을 출력
					cout << endl << "이번 메뉴를 결제하시겠습니까 ? (1 : yes)";
					cin >> ye;
					if (cin.fail())
					{
						cin.clear();
						ye = NULL;
					}
					cin.ignore();
					if (ye == 1)
					{
						temp = i - 1; // 메뉴 가격에 해당하는 위치를 temp에 저장
						tokName[i] = "C"; // O에 해당하는 문자열을 C로 바꾸기 위해 tokName[i]에 값을 저장
						for (int j = 0; j <= i; j++) {
							if (j == 0) {
								tempBuffer = tokName[j];
							}
							else {
								tempBuffer += "\t";
								tempBuffer += tokName[j];
							}
						}
						tempTok = tokName;
						buffer[size] = "";
						complete = true;
						break; // 반복문 탈출

					}
				}
			}
			size++;
		}
	}
	if (complete == false) { // 계산을 실행하지 않거나 계산 할 것이 없는 경우
		cout << "계산할 테이블이 없습니다." << endl;
		cout << "계산을 마치겠습니까?" << endl;
		cin >> ye;
		cin.ignore();
		Menus.close();
		return;
	}
	else {
		string priceTemp;
		int MonthSaleInt;
		string MonthTemp;
		ifstream readMenus(priceFile);
		ifstream readMonth(MonthSale); // 수정 필요 한달 매출액 작성 파일이 없을 경우에 파일 생성
		if (!readMonth)
		{
			MonthSaleInt = 0;
		}
		else {
			getline(readMonth, MonthTemp);
			MonthSaleInt = atoi(MonthTemp.c_str()); // 문자열을 정수로 바꿔서 값을 저장
			readMonth.close(); // 파일 닫기
		}
		ofstream writeMenus(fileName, ios::trunc); // 덮어쓰기 형식으로 파일 쓰기 오픈
		ofstream completeMenus(completeName, ios::app); // 덧붙이기 형식으로 파일 쓰기 오픈
		completeMenus << tempBuffer << endl;

		for (int i = 0; i <= size; i++)
		{
			if (buffer[i] != "")
			{
				writeMenus << buffer[i] << endl;
			}
		}
		writeMenus.close();
		if (complete == true) {
			getline(readMenus, priceTemp);
			soldMoney = atoi(tempTok[temp].c_str());
			obj->setTotalPrice(atoi(priceTemp.c_str()));
			obj->plusTotalPrice(soldMoney);
			cout << "판매 금액 : " << soldMoney << endl;
			cout << tempBuffer << endl;
		}
		ofstream Sell(priceFile, ios::trunc);
		ofstream MonthSell(MonthSale, ios::trunc);
		int totalPrice = obj->getTotalPrice();
		MonthSaleInt += soldMoney;
		MonthSell << MonthSaleInt;
		Sell << totalPrice;
		cout << "당일 판매액 : " << obj->getTotalPrice() << endl;
		cout << "계산을 마치겠습니까?" << endl;
		cin >> ye;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore();
		Menus.close();
		Sell.close();
	}
}
