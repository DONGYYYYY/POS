
/*	Function.cpp	*/

#include "Myheader.h"
#include "Function.h"



void mainPrint()
{
	int menu;
	while (1)
	{
		string fileName1 = "C:\\";
		fileName1 += currentDate();
		fileName1 += "-inOrder.txt";
		string fileName2 = "C:\\";
		fileName2 += currentDate();
		fileName2 += "-outOrder.txt";
		menu = sameOrder(fileName1, fileName2);
		if (menu == 0)
		{
			break;
		}
	}
	cout << "프로그램 종료";

}

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int sameOrder(string fileName1, string fileName2) // 주방에 관련된 작업을 하는 함수.
{
	int size1 = 0;
	int size2 = 0;
	int index;
	int number;
	string buffer1[100];
	string buffer2[100];
	string *tokName;
	char want[] = "요구 사항 : ";
	int i = 0;
	string temp;
	bool complete = false;
	while (!_kbhit()) // 키보드가 입력이 될 때 가지 반복을 한다.
	{
		system("cls");
		size1 = 0;
		ifstream Menus(fileName1); // 매장 주문 현황

		if (Menus)  //파일이 오픈 가능할 때.
		{
			while (!Menus.eof()) { // 파일 끝까지 읽기
				getline(Menus, buffer1[size1]); // 줄단위로 buffer1에 저장.
				if (buffer1[size1] != "") { // 읽은 문자열이 ""이 아닌 경우
					cout << "매장 주문 " << size1 + 1 << " : ";
					tokName = StringSplit(buffer1[size1], "\t");
					for (int i = 0; !tokName[i].empty(); i++) {
						if (strncmp(tokName[i].c_str(), want, 7) != 0) {
							cout << tokName[i] << "\t";
						}
						else
						{
							cout << endl << tokName[i];
						}
					}
					size1++; // 배열 위치값 증가
					cout << endl << "===============================================================================" << endl;
				}
			}

			Menus.close(); // 파일 닫기
		}
		if (size1 == 0) // size1의 크기가 0인 경우 (파일을 오픈햇는데 내용이 없는 경우 혹은 파일이 존재하지 않은 경우)
		{
			cout << "매장 주문 메뉴가 없습니다." << endl;
		}
		size2 = 0;
		ifstream outMenus(fileName2); // 배달 주문 현황
		if (outMenus) // 파일이 오픈 가능할 때
		{
			while (!outMenus.eof()) {//파일 끝까지 읽기
				getline(outMenus, buffer2[size2]); // 줄단위로 buffer2에 저장
				if (buffer2[size2] != "") { // 읽은 문자열이 ""이 아닌 경우
					cout << "배달 주문 " << size2 + 1 << " : ";
					tokName = StringSplit(buffer2[size2], "\t");
					for (int i = 0; !tokName[i].empty(); i++) {
						if (strncmp(tokName[i].c_str(), want, 7) != 0) {
							cout << tokName[i] << "\t";
						}
						else
						{
							cout << endl << tokName[i];
						}
					}
					size2++; // 배열 위치값 증가
					cout << endl << "===============================================================================" << endl;
				}
			}
			outMenus.close(); // 파일 닫기
		}
		if (size2 == 0) //size1의 크기가 0인 경우(파일을 오픈햇는데 내용이 없는 경우 혹은 파일이 존재하지 않은 경우)
		{
			cout << "배달 주문 메뉴가 없습니다." << endl;
		}
		for (int i = 3; i >= 1; i--) // 3초간 대기
		{
			cout << i << endl;
			Sleep(1000); // 
		}
	}
	cout << "완성된 위치를 선택하시오 : ( 1 : 매장 , 2 : 배달  3 : 컴플레인 확인 0 : 종료) >>>";
	cin >> index;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		return 1;
	}
	cin.ignore();
	if (index == 1) // 매장 주문 처리
	{
		cout << "매장 주문 완료 선택" << endl;
		cout << "완성된 메뉴를 선택하시오 : >>";
		cin >> number;
		if (cin.fail()) // 예외 처리
		{
			cin.clear();
			number = NULL;
		}
		cin.ignore();
		if (number > size1) // 메뉴값보다 큰 수를 입력한 경우
		{
			cout << "주문한 메뉴수보다 큰 수를 입력하셨습니다." << endl;
			Sleep(1000);
		}
		else // 정상적인 경우
		{
			system("cls");
			tokName = StringSplit(buffer1[number - 1], "\t");
			for (i = 0; !tokName[i].empty(); i++)
			{
				if (tokName[i] == "X") 
				{
					tokName[i] = "O";
					complete = true;
					buffer1[number - 1] = "";
					for (int j = 0; j <= i; j++)
					{
						if (j == 0)
						{
							temp = tokName[j];
						}
						else
						{
							temp += "\t";
							temp += tokName[j];
						}
					}
					break;
				}
			}
			if (complete == false) // 완료 실패
			{
				system("cls");
				cout << "이미 주문 완료된 메뉴 입니다." << endl;
			}
			else // 완료 성공시
			{
				ofstream writeMenus(fileName1, ios::trunc); // 파일 덮어쓰기
				for (int j = 0; j <= size1; j++)
				{
					if (buffer1[j] != "")
					{
						writeMenus << buffer1[j] << endl; // 파일 내용 저장.
					}
				}
				writeMenus << temp << endl; // 바뀐 내용을 파일 마지막에 저장.
				writeMenus.close(); // 파일 닫기
			}
		}
	}
	else if (index == 2) // 배달 주문 완료 index가 1일 경우와 동일
	{
		cout << "배달 주문 완료 선택" << endl;
		cout << "완성된 메뉴를 선택하시오 : >>";
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			number = NULL;
		}
		cin.ignore();
		if (number > size2)
		{
			cout << "주문한 메뉴수보다 큰 수를 입력하셨습니다." << endl;
			Sleep(1000);
		}
		else {
			system("cls");
			tokName = StringSplit(buffer2[number - 1], "\t");
			for (i = 0; !tokName[i].empty(); i++)
			{
				if (tokName[i] == "X")
				{
					tokName[i] = "O";
					complete = true;
					buffer2[number - 1] = "";
					for (int j = 0; j <= i; j++)
					{
						if (j == 0)
						{
							temp = tokName[j];
						}
						else
						{
							temp += "\t";
							temp += tokName[j];
						}
					}
					break;
				}
			}
			if (complete == false)
			{
				system("cls");
				cout << "이미 주문 완료된 메뉴 입니다." << endl;
			}
			else
			{
				ofstream writeMenus1(fileName2, ios::trunc);
				for (int j = 0; j <= size2; j++)
				{
					if (buffer2[j] != "")
					{
						writeMenus1 << buffer2[j] << endl;
					}
				}
				writeMenus1 << temp << endl;
				writeMenus1.close();
			}
		}
	}
	else if (index == 3)
	{
		checkComplain();//컴플레인
	}
	else if (index == 0)
	{
		return 0;
	}
	return 1;
}
string* StringSplit(string strOrigin, string strTok) // 문자열 토큰으로 나누기 함수
{
	int cutAt;
	int index = 0;
	string *strResult = new string[1000];

	while ((cutAt = strOrigin.find_first_of(strTok)) != strOrigin.npos)
	{
		if (cutAt > 0)
		{
			strResult[index++] = strOrigin.substr(0, cutAt);
		}
		strOrigin = strOrigin.substr(cutAt + 1);
	}

	if (strOrigin.length() > 0)
	{
		strResult[index++] = strOrigin.substr(0, cutAt);
	}
	return strResult;
}




string currentDate()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

	return buf;
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
		cout << buffer << endl; // 파일 내용 출력
		cout << endl << "===============================================================================" << endl;
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