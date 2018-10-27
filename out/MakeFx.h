#include "Myheader.h"
/*c++에는 직접 구현해 줘야 하는 함수 헤더 파일*/

extern void gotoxy(int x, int y); // 콘솔 포인터 위치 이동 함수
extern int isStringDouble(const char *s); // 매개변수 문자배열이 숫자인지 아닌지를 판단하는 함수
extern string intToString(int number); // int형 변수를 string으로 변환하는 함수
extern string* StringSplit(string strOrigin, string strTok); // 문자열을 strTok문자열 단위로 잘라서 배열에 저장하는 함수
extern string currentDate(); // 현재 년도 , 월 , 일을 반환하는 함수
extern string currentMonth(); // 현재 년도 , 월 , 일을 반환하는 함수
