#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
#include "MakeFx.h"


Menu::Menu() : totalPrice(0) { // 생성자
	int check;
	while (1) {
		while (1) { // 정수가 입력될 때 까지 반복
			system("cls");
			cout << "메뉴를 새로 만들 것인가? (1 : yes 2 : no ) >>>";
			cin >> check;
			if (cin.fail()) // 정수아닌 값이 입력되었을 때 처리
			{
				cin.clear();
				cin.ignore();
			}
			else // 정수인 값이 들어오면 버퍼를 지우고 반복문을 종료한다.
			{
				cin.ignore();
				break;
			}
		}
		system("cls"); // 화면 창 지우기
		switch (check) { //check값에 대한 switch문
		case 1:  // 1 일 경우
			int countMenu;
			while (1) { // 메뉴 추가
				system("cls");
				cout << "추가할 메뉴의 개수는 몇개인가 ? : ";
				cin >> countMenu;
				if (cin.fail()) // 정수 값이 아닐 경우 
				{
					cin.clear();
					cin.ignore();
				}
				else // 정수값일 경우 반복문 종료
				{
					cin.ignore();
					break;
				}
			}
			this->size = countMenu; // 입력 값 만큼 size를 설정한다.
			menuPrice = new int[size]; // 동적할당 menuPrice
			menuName = new string[size]; // 동적할당 menuName
			MakeMenu(); // 함수로 이동
			return; // 종료
			break;
		case 2: // 2일 경우
			findMenu();
			return;
		default:  // 그 외의 경우
			system("cls");
		}
	}
}
Menu::~Menu() // 소멸자 
{
	/* 동적 할당 한 변수에 대한 소멸자*/
	delete[] menuPrice;
	delete[] menuName;
}
void Menu::MakeMenu() // 메뉴 생성 
{
	string MenuN;
	string MenuPTemp;
	int MenuP;
	int success = 0;
	bool input = true;
	ofstream Menus("C:\\Menu.txt", ios::trunc); // 새로 메뉴를 만들기 때문에 파일 쓰기 형식 옵션을 trunc로 오픈
	for (int i = 0; i < size; i++) {
		system("cls");
		success = 0; // 정수 값이 입력 되었는지 유무를 확인하기 위한 변수
		while (success == 0) {
			input = true;
			cout << "메뉴 생성" << endl;
			cout << "메뉴 이름을 입력하시오 :";
			getline(cin, MenuN);
			cout << "메뉴의 가격을 입력하시오 : ";
			getline(cin, MenuPTemp);
			try { // 예외처리
				MenuP = stoi(MenuPTemp.c_str()); // 문자열을 정수로 변환
				success = 1; // 성공시 success를 1로 설정
				for (int j = 0; j < size; j++) // 이름 중복 확인을 위한 for문
				{
					if (MenuN == this->menuName[j]) // 중복이 있을 시
					{
						input = false; // input 에 false를 저장
					}
				}
				if (input == true) // 중복 없을 시 
				{
					this->menuName[i] = MenuN; // 객체에 저장
					this->menuPrice[i] = MenuP; // 객체에 저장
					Menus << MenuN << "\t" << MenuP << endl; // 파일에 쓰기
				}
				else // 중복일 시
				{
					i--; // i 1 차감
					cout << "중복되는 메뉴 이름을 입력하셨습니다." << endl;
					Sleep(1000);
				}
			}
			catch (invalid_argument&) // 예외 발생시
			{
				cout << "가격에 해당하는 부분에 숫자 외 다른 값이 입력되었습니다" << endl; // 화면에 출력
				success = 0; // 다시 반복문(while) 수행
				Sleep(1000);

			}
		}
	}
	Menus.close(); // 파일 닫기
	return;

}

void Menu::findMenu() // 메뉴 확인 (Menu.txt에 저장되어 있는 메뉴 내용을 현재 프로그램 객체에 내용 저장)
{
	size = 0;
	int ye;
	string buffer[100];
	string name[100];
	int price[100];
	ifstream Menus("C:\\Menu.txt"); // 읽기 전용으로 파일 오픈
	while (!Menus.eof()) { // 파일 끝까지 읽기
		getline(Menus, buffer[size]); // 줄단위로 파일 내용 받아오기
		string *m_pStrTok = StringSplit(buffer[size], "\t"); // "\t"토큰 단위로 문자열 나누기
		name[size] = m_pStrTok[0]; // 메뉴 이름에 해당하는 문자열 토큰
		if (name[size] != "") { // 파일 이름이 ""이 아닌 경우에만 실행
			price[size] = atoi(m_pStrTok[1].c_str()); // 가격에 해당하는 문자열을 정수로 변환
													  // m_pStrTok[1]이 string이기 때문에 atoi를 쓰기 위해서는 char타입이여야 해서 변환 하기 위해 사용
			cout << "메뉴 이름 : " << name[size] << "\t가격 : " << price[size] << endl; // 화면에 내용 출력 
			size++; // size 증가
		}
	}
	//동적 할당을 하기위한 size와 각각 메뉴가격과 이름에 대해서 동적할당
	this->size = size;
	menuPrice = new int[size];
	menuName = new string[size];
	for (int i = 0; i < size; i++) { // 파일에서 읽어온 내용 순서대로 각 해당하는 가격과 이름에 저장
		menuName[i] = name[i];
		menuPrice[i] = price[i];
	}
	while (1) { // 저장 내용을 확인했는지를 확인하기 위한 반복문
		cout << "저장된 내용을 확인하셨습니까? (1 : 다음) >>>";
		cin >> ye;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore();
		system("cls");
		if (ye == 1)
			break;
	}
	Menus.close();
}
void Menu::setMenuPrice(int index, int menuPrice) // 가격 변경 매개변수로 메뉴의 순서(index)와 변경할 메뉴 가격 menuPrice를 매개변수로 받는다.
{
	this->menuPrice[index] = menuPrice;
	ofstream Menus("C:\\Menu.txt", ios::trunc); // 파일 쓰기 전용으로(덮어쓰기) 오픈
	for (int i = 0; i < size; i++) { //파일에 바뀐 내용을 가지고 있는 객체로 쓰기.
		Menus << this->menuName[i] << "\t" << this->menuPrice[i] << endl;
	}
	Menus.close(); // 파일 닫기
}
void Menu::setMenuName(int index, string menuName) // 메뉴 변경 메뉴의 순서(index)와 변경할 메뉴 가격 menuName를 매개변수로 받는다.
{
	this->menuName[index] = menuName;
	ofstream Menus("C:\\Menu.txt", ios::trunc);// 파일 쓰기 전용으로(덮어쓰기) 오픈
	for (int i = 0; i < size; i++) {//파일에 바뀐 내용을 가지고 있는 객체로 쓰기.
		Menus << this->menuName[i] << "\t" << this->menuPrice[i] << endl;
	}
	Menus.close();
}
void Menu::addMenu() // 메뉴 추가 ( 중복시 가격만 변경 중복 아닐 시 파일에 새로 추가 )
{
	bool possible = false;
	string MenuN;
	string MenuPTemp;
	int MenuP;
	ifstream readMenus("C:\\Menu.txt");
	string buffer;
	string *strTok;
	int count;
	while (1) {
		system("cls");
		cout << "추가할 메뉴의 개수를 입력하시오 : ";
		cin >> count;
		if (cin.fail()) // 입력값이 정수가 아닐 시
		{
			cin.clear();
			cin.ignore();
		}
		else // 정수일 시 반복문 탈출
			break;
	}
	cin.ignore();
	int i = 0;
	int j = 0;
	while (!readMenus.eof()) // 파일 끝까지 읽기
	{
		getline(readMenus, buffer);
		if (buffer != "") {
			strTok = StringSplit(buffer, "\t");
			this->setAll(i++, strTok[0], atoi(strTok[1].c_str())); // 파일 내용을 읽은 문자열에서  메뉴 이름에 대한 부분과 메뉴 가격에 대한 부분에 대한 정보를 setAll을 통해서 menuName과 menuPrice 설정
		}
	}
	readMenus.close(); // 파일 읽기 닫기
	for (int z = 0; z < count; z++) { // 파일 추가할 만큼의 개수 만큼 반복
		possible = false;
		system("cls");
		checkMenu(); // 메뉴 내용 띄우기
		cout << "메뉴 생성" << endl;
		cout << "메뉴 이름을 입력하시오 :";
		getline(cin, MenuN); // 이름 입력 받기
		cout << "메뉴의 가격을 입력하시오 : ";
		getline(cin, MenuPTemp); // 가격 입력 받기
		try {  // 예외처리
			MenuP = stoi(MenuPTemp.c_str()); // atoi와 같은 작업을 하는 stoi함수 하지만 예외처리를 사용 할 수 있는 함수
		}
		catch (invalid_argument&) // 입력값에 숫자 외의 값이 입력된 경우 예외 처리를 해준다.
		{
			cout << "가격에 해당하는 부분에 숫자 외 다른 값이 입력되었습니다";
			Sleep(1000);
			break;
		}
		for (j = 0; j < i; j++) // 현재 존재하는 메뉴들 중에 중복되는 이름이 존재하는지를 확인하기 위한 for문
		{
			if (this->getMenuName(j) == MenuN) // 입력받은 메뉴 이름이 현재 메뉴에 있는지를 확인하기 위한 if문
			{
				possible = false;
				break;
			}
			else // 중복이 없을 시
			{
				possible = true; //possible을 true 저장
			}
		}
		if (possible == true) // 중복 없을시 파일 쓰기를 하기 위한 if문
		{
			ofstream addMenus("C:\\Menu.txt", ios::app);
			addMenus << MenuN << "\t" << MenuP << endl;
			addMenus.close();
			cout << "메뉴 추가 완료." << endl;
			Sleep(2000);
		}
		else // 중복 시 일치하는 메뉴 이름에 대한 가격만 변경
		{
			cout << "일치하는 이름이 존재합니다. 가격만 변경합니다." << endl;
			Sleep(2000);
			this->setMenuPrice(j, MenuP);
			ofstream fixMenus("C::\\Menu.txt", ios::trunc);
			for (int l = 0; l < size; l++)
			{
				fixMenus << this->getMenuName(l) << "\t" << this->getMenuPrice(l) << endl;
			}
			fixMenus.close();
		}
	}
	system("cls");
	findMenu(); // 바뀐 메뉴 내용을 보여주기 위한 findMenu()

}
int Menu::getTotalPrice() // 총 판매액 반환
{
	return this->totalPrice;
}
int Menu::getMenuPrice(int index) // 메뉴 가격 반환
{
	return this->menuPrice[index];
}
string Menu::getMenuName(int index) // 메뉴 이름 반환
{
	return this->menuName[index];
}
int Menu::getSize() // size 반환
{
	return size;
}



void Menu::checkMenu() { // 메뉴 내용 띄우기 및 파일 내용 만큼 다시 Menu객체 size를 수정하여 동적할당을 해준다. findMenu()와 다른점을 while문을 통하여 내용이 확인 유무를 묻는지 안묻는지의 차이점만 존재
	size = 0;
	string buffer[100];
	string name[100];
	int price[100];
	string *m_pStrTok;
	ifstream Menus("C:\\Menu.txt");
	while (!Menus.eof()) {
		getline(Menus, buffer[size]);
		m_pStrTok = StringSplit(buffer[size], "\t");
		name[size] = m_pStrTok[0];
		if (name[size] != "") {
			price[size] = atoi(m_pStrTok[1].c_str());
			// m_pStrTok[1]이 string이기 때문에 atoi를 쓰기 위해서는 char타입이여야 해서 변환 하기 위해 사용
			cout << size + 1 << "\t메뉴 이름 : " << name[size] << "\t가격 : " << price[size] << endl;
			size++;
		}
	}
	this->size = size;
	this->menuPrice = new int[size];
	this->menuName = new string[size];
	for (int i = 0; i < size; i++) {
		this->menuName[i] = name[i];
		this->menuPrice[i] = price[i];
	}
	return;
}

void Menu::setAll(int index, string menuName, int menuPrice) // index에 해당하는 menuName , menuPrice setter 및 파일 쓰기
{

	this->menuName[index] = menuName;
	this->menuPrice[index] = menuPrice;
	ofstream Menus("C:\\Menu.txt", ios::out, ios::trunc);
	for (int i = 0; i < size; i++) {
		if (this->menuName[i] != "" && this->menuPrice != NULL)
			Menus << this->menuName[i] << "\t" << this->menuPrice[i] << endl;
	}
	Menus.close();
}

void Menu::setTotalPrice(int totalPrice) // totalPrice setter
{
	this->totalPrice = totalPrice;
}

void Menu::plusTotalPrice(int price) // totalPrice pirce값 만큼 증가
{
	this->totalPrice += price;
}

int Menu::takePrice(string menuName) // 해당 menuName에 해당하는 menuPrice 가격 반환
{
	int i;
	int price;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		if (menuName == this->menuName[i])
		{
			price = this->menuPrice[i];
			break;
		}
		count++;
	}
	if (count == size) {
		cout << "해당 메뉴 이름과 일치하는 메뉴가 없습니다." << endl;
		Sleep(2000);
		system("cls");
		return NULL;
	}
	return price;
}

void Menu::fixMenu() // 파일에서 내용을 읽어와 객체에 내용 저장. (update기능)
{
	ofstream Menus("C:\\Menu.txt", ios::trunc);
	for (int i = 0; i < size; i++) {
		if (this->menuName[i] != "" && this->menuPrice != NULL)
			Menus << this->menuName[i] << "\t" << this->menuPrice[i] << endl;
	}
	Menus.close();
}
