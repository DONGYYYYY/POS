#include "Myheader.h"
#include "Menu.h"
#include "Function.h"

string* StringSplit(string strOrigin, string strTok) // 문자열 토큰으로 나누기 함수
{
	int cutAt;
	int index = 0;
	string *strResult = new string[1000]; // 동적할당 (최대치를 일단 100으로 잡음) 100개 이상의 메뉴를 시키는 경우가 있으면 크기를 더 크게 설정

	while ((cutAt = strOrigin.find_first_of(strTok)) != strOrigin.npos) // cutAt에 토큰으로 나눠진 만큼의 문자열의 길이를 저장한다. ( 원래 문자열의 끝까지 반복 (최종적으로 "\0"일 때까지) 
	{
		if (cutAt > 0)
		{
			strResult[index++] = strOrigin.substr(0, cutAt); //strResult[index++]값에 strOrigin을 토큰단위로 분리한 문자열을 저장한다.
		}
		strOrigin = strOrigin.substr(cutAt + 1); // strOrigin은 다음 문자열을 가르킨다. ( 토큰으로 분리한 )
	}

	if (strOrigin.length() > 0)
	{
		strResult[index++] = strOrigin.substr(0, cutAt);
	}
	return strResult; // 토큰으로 나눠진 문자열을 반환
}

int isStringDouble(const char *s) { // 문자열이 숫자로만 이루어져 있는지 확인하는 함수
	size_t size = strlen(s);
	if (size == 0) return 0; // 0바이트 문자열은 숫자가 아님

	for (int i = 0; i < (int)size; i++) {
		if (s[i] == '.' || s[i] == '-' || s[i] == '+') continue;
		if (s[i] < '0' || s[i] > '9') return 0; // 알파벳 등이 있으면 숫자 아님
	}

	return 1; // 그밖의 경우는 숫자
}


string currentDate() // 현재 년-월-일을 문자열 형태로 반환하는 함수 (주문 내역을 날짜 별로 나누기 위해서 사용하는 함수)
{
	time_t now = time(0); // 현재 시간에 대한 정보를 가지는 now 변수
	struct tm tstruct; // 구조체 선언 
	char buf[80];
	tstruct = *localtime(&now); // 현재 시간에 대한 내용을 tstruct에 저장.
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct); // %Y = 년도 %m = 달 %d = 일 에 대한 내용을 가진다.

	return buf; // 년-월-일의 내용을 가진 문자열을 반환
}


string currentMonth() // 년-월 문자열 값을 반환하는 함수
{
	time_t now = time(0); // 현재 시간에 대한 정보를 가지는 now 변수
	struct tm tstruct; // 구조체 선언 
	char buf[80];
	tstruct = *localtime(&now); // 현재 시간에 대한 내용을 tstruct에 저장.
	strftime(buf, sizeof(buf), "%Y-%m", &tstruct);// %Y = 년도 %m = 달 에 대한 내용을 가진다.

	return buf; // 년-월의 내용을 가진 문자열을 반환
}

void gotoxy(int x, int y) { // 콘솔 포인터 위치를 변경하기 위한 함수
	COORD pos;
	pos.X = x; // x 축
	pos.Y = y; // y 축
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // 매개변수로 받은 x , y축 만큼 이동 ( 0 , 0 ) 기준에서
}
