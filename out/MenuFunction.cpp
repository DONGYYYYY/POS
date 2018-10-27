#include "Myheader.h"
#include "Function.h"
#include "Menu.h"
#include "MakeFx.h"
#include "MenuFunction.h"
#include "StatusFunction.h"

extern Menu *obj;

void checkMenu() { // 메뉴 관련 메뉴 (모든 메뉴화면 switch case로 수정!
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 메뉴판 확인";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 메뉴 수정"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 :    이전";		gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "=============================" << endl;
		gotoxy(25, 5); cout << "입력 : ";
		cin >> menu;
		if (cin.fail())
		{
			cin.clear();
			menu = 0;
		}
		cin.ignore();
		switch (menu) {
		case 1:
			system("cls");
			MyMenu();
			break;

		case 2:
			system("cls");
			changeMenu();
			break;
		case 3:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

void MyMenu() // 현재 세팅되어 있는 메뉴 확인 ( 메뉴판 확인 )
{
	system("cls");
	int ye;
	while (1) {
		for (int i = 0; i < obj->getSize(); i++)
		{
			cout << "메뉴 이름 : " << obj->getMenuName(i) << "\t가격 : " << obj->getMenuPrice(i) << endl;
		}
		cout << "저장된 내용을 확인하셨습니까? (1 : 다음) >>>";
		cin >> ye;
		if (cin.fail())
		{
			cin.clear();
			ye = NULL;
		}
		cin.ignore();
		system("cls");
		if (ye == 1)
			break;
	}
}

void changeMenu() // 메뉴 변경 기능 ( 메뉴 수정 )
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 메뉴 추가";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 메뉴 이름 수정"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 메뉴 가격 수정"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : 메뉴 가격 이름 수정"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 : 메뉴 순서 수정"; gotoxy(48, 5); cout << "|" << endl;
		gotoxy(20, 6); cout << "|"; gotoxy(25, 6); cout << "6 : 메뉴 삭제"; gotoxy(48, 6); cout << "|" << endl;
		gotoxy(20, 7); cout << "|"; gotoxy(25, 7); cout << "7 : 이전"; gotoxy(48, 7); cout << "|" << endl;
		gotoxy(20, 8); cout << "=============================" << endl;
		gotoxy(25, 9); cout << "입력 : ";
		cout << "               ";
		gotoxy(31, 9);
		cin >> menu;
		if (cin.fail())
		{
			cin.clear();
			menu = 0;
		}
		cin.ignore();
		switch (menu) {
		case 1:
			system("cls");
			MenuAdd();
			break;

		case 2:
			system("cls");
			changeMenuName();
			break;
		case 3:
			system("cls");
			changeMenuPrice();
			break;
		case 4:
			system("cls");
			changeAll();
			break;
		case 5:
			system("cls");
			sortMenu();
			break;
		case 6:
			system("cls");
			deleteMenu();
			break;
		case 7:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

void MenuAdd() // 메뉴 추가
{
	obj->addMenu(); // 메뉴 클래스의 addMenu()호출
}

void changeMenuName() { // 메뉴 이름 변경
	int ye;
	string name;
	obj->checkMenu(); // 메뉴 클래스의 checkMenu()호출
	cout << "이름 변경을 원하는 메뉴 이름을 입력하시오 : ";
	getline(cin, name);
	int count = 0;
	for (int i = 0; i < obj->getSize(); i++) {
		if (name == obj->getMenuName(i)) {
			cout << "변경할 메뉴 이름을 입력하시오 : ";
			string changeName;
			getline(cin, changeName);
			obj->setMenuName(i, changeName); // 메뉴 이름 설정
			obj->findMenu(); // 객체 내용 저장
			return;
		}
		else {
			count++;
		}
	}
	if (count == obj->getSize()) {
		system("cls");
		cout << "입력한 메뉴 이름과 일치하는 메뉴가 없습니다." << endl;
	}
	cout << "" << endl;
	cout << "아무 키나 눌르시오. >>>";
	cin >> ye;
	if (cin.fail())
	{
		cin.clear();
		ye = 0;
	}
	cin.ignore();
	system("cls");


}

void changeMenuPrice() // 메뉴 가격 변경
{
	int ye;
	string name;
	string temp;
	int changePrice;
	obj->checkMenu();
	cout << "가격 변경을 원하는 메뉴 이름을 입력하시오 : ";
	getline(cin, name);
	int count = 0;
	for (int i = 0; i < obj->getSize(); i++) {
		if (name == obj->getMenuName(i)) {
			system("cls");
			cout << name << "의 가격 = " << obj->getMenuPrice(i) << " 변경할 메뉴 가격을 입력하시오 : ";
			getline(cin, temp);
			try
			{
				changePrice = stoi(temp.c_str()); // 입력 값이 숫자가 아닌경우 ( 문자열로 입력받아서 예외처리로 해결 )
				obj->setMenuPrice(i, changePrice); // 가격 설정 메소드
				obj->findMenu(); // 객체 내용 저장
				return;
			}
			catch (invalid_argument&) // 예외 발생시( 문자열에 정수가 아닌 문자가 들어온 경우 )
			{
				i--;
				cout << "가격에 숫자가 아닌 값이 입력되었습니다.";
				Sleep(1000);
			}
		}
		else {
			count++;
		}
	}
	if (count == obj->getSize()) {
		system("cls");
		cout << "입력한 메뉴 이름과 일치하는 메뉴가 없습니다." << endl;
	}
	cout << "" << endl;
	cout << "아무키나 입력하시오.";
	cin >> ye;
	if (cin.fail())
	{
		cin.clear();
		ye = 0;
	}
	cin.ignore();
	system("cls");

}

void changeAll() { // 메뉴 가격 , 이름 동시 변경
	string name;
	string temp;
	int changePrice;
	obj->checkMenu();
	cout << "이름 변경을 원하는 메뉴 이름을 입력하시오 : ";
	getline(cin, name);
	int count = 0;
	for (int i = 0; i < obj->getSize(); i++) {
		if (name == obj->getMenuName(i)) {
			cout << "변경할 메뉴 이름을 입력하시오 : ";
			string changeName;
			getline(cin, changeName);
			while (1) {
				system("cls");
				cout << changeName << "의 가격 = " << obj->getMenuPrice(i) << " 변경할 메뉴 가격을 입력하시오 : ";
				getline(cin, temp);
				try
				{
					changePrice = stoi(temp.c_str()); // 예외 발생할 수 있는 부분
					obj->setAll(i, changeName, changePrice); // 가격 , 이름 동시 변경
					obj->findMenu(); // 내용 저장
					break;
				}
				catch (invalid_argument&) // 예외 발생시
				{
					cout << "가격에 숫자가 아닌 값이 입력되었습니다." << endl;
					Sleep(1000);
				}
			}
		}
		else {
			count++;
		}
	}
	if (count == obj->getSize()) {
		system("cls");
		cout << "입력한 메뉴 이름과 일치하는 메뉴가 없습니다." << endl;
		Sleep(1000);
		system("cls");
	}
}

void sortMenu() // 메뉴 순서 변경 메소드
{
	int number1 = 0;
	int number2 = 0;
	bool can = true;
	while (1) {
		system("cls");
		obj->checkMenu();
		cout << "순서를 바꿀 메뉴 첫번째 번호를 입력하세요 : (0 = 종료)";
		cin >> number1;
		if (cin.fail())
		{
			can = false;
			cin.clear();
		}
		cin.ignore();
		cout << "순서를 바꿀 메뉴 두번째 번호를 입력하세요 : (0 = 종료)";
		cin >> number2;
		if (cin.fail())
		{
			can = false;
			cin.clear();
		}
		cin.ignore();
		if (number1 == 0 || number2 == 0 || can == false) // 입력 값 둘중 하나가 0이거나 입력값에 숫자가 아닌 값이 들어온 경우
		{
			cout << "정렬을 종료합니다." << endl;
			Sleep(2000);
			system("cls");
			break;
		}
		else if (number1 > obj->getSize() || number2 > obj->getSize()) // 존재하는 메뉴가 아닌 값을 입력했을 경우
		{
			cout << "존재하지 않는 메뉴 번호가 있습니다." << endl;
			Sleep(2000);
			system("cls");
		}
		else { // 메뉴 선택이 된 경우 ( 정렬할 )
			string tempMenuName = obj->getMenuName(number1 - 1);
			int tempMenuPrice = obj->getMenuPrice(number1 - 1);
			obj->setMenuName(number1 - 1, obj->getMenuName(number2 - 1));
			obj->setMenuPrice(number1 - 1, obj->getMenuPrice(number2 - 1));
			obj->setMenuName(number2 - 1, tempMenuName);
			obj->setMenuPrice(number2 - 1, tempMenuPrice);
			system("cls");
			cout << "정렬 완료 " << endl;
			obj->fixMenu();
			obj->checkMenu();
			Sleep(2000);
		}
	}
}

void deleteMenu() // 메뉴 삭제
{
	string name;
	obj->checkMenu();
	cout << "메뉴 삭제를 원하는 메뉴 이름을 입력하시오 : ";
	getline(cin, name); 
	bool success = false;
	for (int i = 0; i < obj->getSize(); i++) {// 배열의 크기까지 반복
		if (name == obj->getMenuName(i)) { // 같은 이름을 찾은 경우
			obj->setAll(i, "", NULL); // 삭제
			cout << "삭제 후 " << endl;
			obj->fixMenu(); // 파일에 저장
			obj->checkMenu(); //파일에서 내용을 읽어와 객체에 저장
			success = true; // 성공
			Sleep(2000);
			break;
		}
	}
	if (success == false) { // 실패시
		system("cls");
		cout << "입력한 메뉴 이름과 일치하는 메뉴가 없습니다." << endl;
		Sleep(2000);
	}
	system("cls");


}
