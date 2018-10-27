#include "Myheader.h"
#include "Function.h"
#include "Menu.h"
#include "MakeFx.h"
#include "OrderFunction.h"
#include "StatusFunction.h"

extern Menu *obj;

void orderMenu() { // 메뉴 주문
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 매장 주문";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 배달 주문"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 주문 수정"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : 주문내역 수정"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 : 이전"; gotoxy(48, 5); cout << "|" << endl;
		gotoxy(20, 6); cout << "=============================" << endl;
		gotoxy(25, 7); cout << "입력 : ";
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
			inOrder();
			break;
		case 2:
			outOrder();
			break;
		case 3:
			fixOrder();
			break;
		case 4:
			cancelOrderMenu();
			break;
		case 5:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

void inOrder() // 매장 주문 
{
	int price = 0;
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	sameOrder(fileName);
}
void outOrder() // 배달 주문 
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-OutOrder.txt";
	sameOrder(fileName);

}

void sameOrder(string fileName) // 매개변수에 따라서 매장 , 배달 주문 
{
	int price = 0;
	int wanner;
	string want;
	int count;
	int howmany = 0;
	ofstream Menus(fileName, ios::app); // 파일 이어 쓰기
	while (1) {
		system("cls");
		obj->checkMenu();
		cout << "주문할 메뉴를 선택하세요 : (0 = 종료)(메뉴는 위에서 부터 1부터 시작)";
		cin >> count;
		if (cin.fail())
		{
			cin.clear();
			count = NULL;
		}
		cin.ignore();
		if (count > obj->getSize())
		{
			cout << "존재하지 않는 메뉴 번호를 입력하셨습니다." << endl;
			Sleep(2000);
		}
		else {
			howmany++;
			if (count == 0) { // 0 혹은 숫자 외의 값이 입력된 경우 종료
				if (howmany == 1) // 0 외의 숫자가 전에 입력되지 않은 경우 입력된 것이 없다는 것을 알려주고 종료
				{
					cout << "메뉴 입력을 하나도 하지 않았습니다." << endl;
					Sleep(1000);
					break;
				}
				Menus << price << "\t"; // 가격 파일에 쓰기
				Menus << "X" << "\t"; // 완성 여부 파일에 쓰기
				cout << "원하는 요구사항이 있으십니까? ( 1 : yes ) >> ";
				cin >> wanner;
				if (cin.fail())
				{
					cin.clear();
					wanner = NULL;
				}
				cin.ignore();
				if (wanner == 1) // 요구사항이 있을 시
				{
					cout << "요구 사항 : ";
					getline(cin, want);
					Menus << "요구 사항 : " << want << endl; // 파일에 요구사항 내용 쓰기
				}
				else // 없을 시
				{
					cout << "요구 사항 접수 X ";
					Sleep(1000);
				}
				break;
			}
			else { // 0이 입력이 되기 전까지는 메뉴의 내용을 파일에 쓰기 총 가격을 알기 위해서 price변수에 메뉴 가격만큼 증가
				price += obj->getMenuPrice(count - 1);
				string MenuN = obj->getMenuName(count - 1);
				Menus << MenuN << "\t";
			}
		}
	}
	Menus << endl; // 파일 줄바꿈
	Menus.close();//파일 닫기
}

void fixOrder() // 주문 수정
{
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 매장 주문 수정";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 배달 주문 수정"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 매장 주문 추가";		gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : 배달 주문 추가"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 : 이전"; gotoxy(48, 5); cout << "|" << endl;
		gotoxy(20, 6); cout << "=============================" << endl;
		gotoxy(25, 7); cout << "입력 : ";
		int menu;
		cin >> menu;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore();
		switch (menu)
		{
		case 1:
			system("cls");
			inOrderfix();
			break;
		case 2:
			system("cls");
			outOrderfix();
			break;
		case 3:
			system("cls");
			plusInOrder();
			break;
		case 4:
			system("cls");
			plusOutOrder();
			break;
		case 5:
			system("cls");
			return;
		default:
			break;
		}
	}
}
void inOrderfix() { // 매장 주문 수정
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	sameOrderFix(fileName);
}

void outOrderfix() { // 배달 주문 수정
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	sameOrderFix(fileName);
}

void sameOrderFix(string fileName) // 주문 수정
{
	system("cls");
	int size = 0;
	string tempBuffer;
	string buffer[100];
	string name[100];
	int totalPrice;
	string *strTok;
	int count = 0;
	checkOrderMenu(fileName);
	ifstream Menus(fileName); // 파일 읽기
	while (!Menus.eof()) { // 파일 끝까지 읽기
		getline(Menus, buffer[size]); // 파일 줄단위로 읽기
		if (buffer[size] != "") {
			size++;
		}
	}
	Menus.close();
	cout << "변경 혹은 취소를 원하는 주문 번호를 입력하시오 : ";
	int index;
	cin >> index;
	if (cin.fail())
	{
		system("cls");
		cin.clear();
		cin.ignore();
		index = 0;
		cout << "숫자가 아닌 키가 입력되었습니다.";
		Sleep(1000);
	}
	else
	{
		cin.ignore();
		system("cls");
		if (index > size)
		{
			cout << "숫자를 초과하였습니다." << endl;
			Sleep(1000);
		}
		if (index == 0)
		{
			cout << "종료" << endl;
			Sleep(1000);
			return;
		}
		else {
			while (1) {
				if (index > size)
				{
					break;
				}
				system("cls");
				int tempNumber = 0;
				tempBuffer = ""; // 수정된 메뉴 내용을 저장하기 위한 문자열 초기화
				strTok = StringSplit(buffer[index - 1], "\t");
				for (int i = 0; !strTok[i].empty(); i++) {
					if (strTok[i] != "O" && isStringDouble(strTok[i].c_str()) != 1) {
						if (strTok[i] != "X")
						{
							cout << strTok[i] << "\t";
						}
					}
				}
				cout << endl << "해당 주문에서 변경하기를 원하는 메뉴를 입력하시오 .(0 = 종료) :";
				string menuName;
				getline(cin, menuName);
				if (menuName == "0") // 메뉴가 완료된 메뉴이면 변경 불가
				{
					break;
				}
				for (int i = 0; !strTok[i].empty(); i++) // 메뉴 총 가격에 해당하는 부분 찾기
				{
					if (strTok[i] == "X")
					{
						tempNumber = i - 1; // 가격에 해당하는 위치
					}
				}
				for (int i = 0; !strTok[i].empty(); i++)
				{
					if (menuName == strTok[i]) // 메뉴 이름과 같은 메뉴를 찾을 시
					{
						cout << strTok[i] << endl << "해당 메뉴를 취소(1)하시겠습니까 ? 변경(2)하시겠습니까 ? (0 = 종료) ";
						int number;
						cin >> number;
						if (cin.fail())
						{
							cin.clear();
							number == NULL;
						}
						cin.ignore();
						if (number == 1) // 취소
						{
							totalPrice = atoi(strTok[tempNumber].c_str()); // 총 가격에 해당하는 토큰내용을 정수로 변환
							totalPrice -= obj->takePrice(strTok[i]); // 총 가격에서 취소하는 메뉴의 가격만큼 차감
							strTok[tempNumber] = to_string(totalPrice); // 변경된 값을 문자열로 변환 후 값에 해당하는 토큰에 저장
							strTok[i] = ""; // 해당 메뉴 위치의 토큰을 공백으로 변경
							for (int j = 0; j <= tempNumber + 1; j++)
							{
								if (j == 0) {
									tempBuffer = strTok[j];
								}
								else if (tempNumber == 1) // 메뉴가 한개 밖에 없었을 경우
								{
									tempBuffer == "";
									break;
								}
								else {
									if (j == 1 && strTok[0] == "") // 첫 번째 메뉴를 취소했을 경우
									{
										tempBuffer = strTok[j];
									}
									else { // 그 외의 경우
										if (strTok[j] != "") {
											tempBuffer += "\t";
											tempBuffer += strTok[j];
										}
									}
								}
							}
							tempNumber -= 1;
							break;
						}
						else if (number == 2) // 변경
						{

							obj->checkMenu();
							cout << "변경을 원하는 메뉴 번호를 입력하시오 : "; // 정상작동
							int menuNumber;
							cin >> menuNumber;
							if (cin.fail())
							{
								cin.clear();
								cin.ignore();
								cout << "숫자가 아닌 키가 입력되었습니다.";
								Sleep(1000);
								break;
							}
							else
							{
								if (menuNumber > obj->getSize()) // 찾지 못했을 시
								{
									cout << "존재하지 않는 메뉴를 입력하셨습니다." << endl;
									Sleep(1000);
									break;
								}
								cin.ignore();
								totalPrice = atoi(strTok[tempNumber].c_str()); // 메뉴가 수정되었기 때문에 토탈가격도 변경
								totalPrice -= obj->takePrice(strTok[i]); // 토탈 가격에서 원래 메뉴 가격만큼 차감
								strTok[i] = obj->getMenuName(menuNumber - 1); // 새로 추가할 메뉴 이름 추가
								totalPrice += obj->takePrice(strTok[i]); // 새로 추가할 메뉴 이름을 통해 메뉴가격 가져와서 토탈 가격에 추가
								strTok[tempNumber] = to_string(totalPrice); // 토탈가격이 정수이기 때문에 문자열로 변환 후 토큰에 저장
								for (int j = 0; j <= tempNumber + 1; j++)
								{
									if (j == 0) {
										tempBuffer = strTok[j];
									}
									else {
										tempBuffer += "\t";
										tempBuffer += strTok[j];
									}
								}
								break;
							}
						}
						else if (number == 0)
						{
							break;
						}
						else
						{
							cout << "잘못된 숫자를 입력하셨습니다." << endl;
							break;
						}
					}
				}
				buffer[index - 1] = tempBuffer;
				cout << buffer[index - 1] << endl;
				Sleep(5000);

			}
		}
		system("cls");
		ofstream writeMenus(fileName, ios::trunc);
		for (int i = 0; i < size; i++)
		{
			if (buffer[i] != "")
				writeMenus << buffer[i] << endl;
		}
		writeMenus.close();
	}
}


void plusInOrder() // 매장 주문 추가
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	samePlusOrder(fileName);
}
void plusOutOrder() // 배달 주문 추가
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	samePlusOrder(fileName);
}
void samePlusOrder(string fileName) // 매장 배달에서 준 매개 변수로 처리하는 주문 내역 추가
{
	int size = 0;
	int number;
	string tempBuffer;
	string buffer[100];
	int tempNumber;
	int totalPrice;
	string *strTok;
	int count = 0;
	checkOrderMenu(fileName);
	ifstream Menus(fileName, ios::in);
	if (!Menus)
	{
		return;
	}
	while (!Menus.eof()) {
		getline(Menus, buffer[size]);
		if (buffer[size] != "") {
			size++;
		}
	}
	Menus.close();
	cout << "메뉴를 추가할 주문 번호를 입력하시오 : ";
	int index;
	cin >> index;
	if (cin.fail())
	{
		system("cls");
		cin.clear();
		cin.ignore();
		cout << "숫자가 아닌 키가 입력되었습니다.";
		Sleep(1000);
	}
	else
	{
		cin.ignore();
		system("cls");
		if (index > size)
		{
			cout << "존재하는 주문을 초과하였습니다." << endl;
			Sleep(1000);
		}
		else
		{
			strTok = StringSplit(buffer[index - 1], "\t");
			for (int i = 0; !strTok[i].empty(); i++)
			{
				if (strTok[i] != "X" && isStringDouble(strTok[i].c_str()) != 1)
				{
					if (i == 0)
					{
						tempBuffer = strTok[i] + "\t";
					}
					else {
						tempBuffer += strTok[i] + "\t";
					}
				}
				if (strTok[i] == "X")
				{
					tempNumber = i - 1; // 총가격에 해당하는 문자열의 위치
				}
			}
			totalPrice = atoi(strTok[tempNumber].c_str()); // 문자열을 정수로 변환해서 저장
			while (1) {
				system("cls");
				obj->checkMenu();
				cout << "추가할 메뉴 번호를 입력하시오 : ( 0 : 종료 ) ";
				cin >> number;
				if (cin.fail())
				{
					cin.clear();
					number = -1;
				}
				cin.ignore();
				if (number == 0)
				{
					system("cls");
					break;
				}
				else if (number != -1)
				{
					tempBuffer += obj->getMenuName(number - 1) + "\t";
					totalPrice += obj->getMenuPrice(number - 1);
				}
			}
			tempBuffer += to_string(totalPrice); // 문자열로 변환후 문자열에 덧붙이기.
			buffer[index - 1] = "";
		}
		system("cls");
		ofstream writeMenus(fileName, ios::trunc);
		for (int i = 0; i < size; i++)
		{
			if (buffer[i] != "") { // 원래 내용 파일에 쓰기
				writeMenus << buffer[i] << endl;
				cout << buffer[i] << endl;
			}
			else // 수정한 내용 원래 위치의 파일에 쓰기
			{
				writeMenus << tempBuffer << endl;
				cout << tempBuffer << endl;
			}
		}
		Sleep(1000);
		writeMenus.close();//파일 닫기
	}
}


void cancelOrderMenu() // 주문 번호 하나를 지우거나 주문 전체 취소 관련 메뉴
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : 매장 주문 취소";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : 배달 주문 취소"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : 매장 주문 전체 취소"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : 배달 주문 전체 취소"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 5); cout << "5 : 이전"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 6); cout << "=============================" << endl;
		gotoxy(25, 7); cout << "입력 : ";
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
			cancelNumberInOrderMenu();
			break;
		case 2:
			cancelNumberOutOrderMenu();
			break;
		case 3:
			cancelNumberInOrderAllMenu();
			break;
		case 4:
			cancelNumberOutOrderAllMenu();
			break;
		case 5:
			return;
		default:
			break;
		}
	}


}
void cancelNumberInOrderMenu() // 매장 주문 메뉴 취소
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	cancelNumberOrderMenu(fileName);
}
void cancelNumberOutOrderMenu() // 배달 주문 메뉴 취소
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	sameOrderFix(fileName);
}
void cancelNumberOrderMenu(string fileName) // 파일이름에 따라서 매장, 배달 주문 메뉴 취소
{
	system("cls");
	int size = 0;
	int number;
	string buffer[100];
	string name[100];

	ifstream Menus(fileName);
	while (!Menus.eof()) {
		getline(Menus, buffer[size]);
		name[size] = buffer[size];
		if (name[size] == "") {
			break;
		}
		cout << "주문 " << size + 1 << "\t메뉴 이름 : " << buffer[size] << endl;
		size++;
	}
	Menus.close();
	cout << "취소할 주문 번호를 입력하시오 : (0 : 종료)";
	cin >> number;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "숫자 말고 다른 키가 입력되었습니다." << endl;
		Sleep(1000);
	}
	else
	{
		cin.ignore();
		if (number != 0) {
			buffer[number - 1] = ""; // 내용 지우기
		}

		ofstream writeMenus(fileName, ios::trunc);
		for (int i = 0; i <= size; i++)
		{
			if (buffer[i] != "")
			{
				writeMenus << buffer[i] << endl; // 지운내용은 파일에 쓰기않고 나머지 내용을 파일에 다시 쓰기.
			}
		}
		writeMenus.close();
	}
}
void cancelNumberInOrderAllMenu() // 완료되지 않은 매장 주문 전체 취소
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	cancelNumberOrderAllMenu(fileName);
}
void cancelNumberOutOrderAllMenu() // 완료되지 않은 배달 주문 전체 취소
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";;
	cancelNumberOrderAllMenu(fileName);
}
void cancelNumberOrderAllMenu(string fileName) // 파일 이름에 따라 완료되지 않은 매장 , 배달 주문 전체 취소
{
	string buffer[100];
	int size = 0;
	ifstream Menus(fileName);//파일 읽기모드로 오픈
	while (!Menus.eof())
	{
		getline(Menus, buffer[size]);
		if(buffer[size]!="")
		{
		size++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		string *strTok = StringSplit(buffer[i], "\t");
		for (int j = 0; !strTok[j].empty(); j++)
		{
			if (strTok[j] == "X")
			{
				buffer[i] = ""; // 완료되지 않는 문자열을 전부 ""로 변경
			}
		}
	}
	Menus.close(); // 파일닫기
	ofstream writeMenus(fileName, ios::trunc); // 파일 덮어쓰기로 오픈
	for (int i = 0; i < size; i++)
	{
		if(buffer[i]!="") // 완료된 주문만 파일에 쓰기.
			writeMenus << buffer[i] << endl;

	}
	writeMenus.close();//파일닫기
}
