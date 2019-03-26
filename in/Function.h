#include "Myheader.h"

void mainPrint();

int checkMain();
void gotoxy(int x, int y);

int sameOrder(string fileName1, string fileName2);

void checkComplain(); // 컴플레인
void writeComplain(); // 컴플레인 쓰기로 메뉴
void readComplain(); // 컴플레인 읽기로 메뉴

void inWriteComplain(); // 매장 컴플레인 쓰기 
void outWriteComplain(); // 주방 컴플레인 쓰기
void sameWriteComplain(string fileName); // 컴플레인 쓰기 처리

void inReadComplain(); // 매장 컴플레인 읽기
void outReadComplain(); // 주방 컴플레인 읽기
void sameReadComplain(string fileName); // 컴플레인 읽기 처리

void resetComplain(); // 컴플레인 파일 초기화 메뉴

void resetInComplain(); //  매장 컴플레인 파일 초기화
void resetOutComplain(); // 주방 컴플레인 파일 초기화
void resetSameComplain(string fileName); // 컴플레인 파일 초기화 처리

extern string* StringSplit(string strOrigin, string strTok);
string currentDate();
