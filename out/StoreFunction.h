#include "Myheader.h"

/* 매장 현황 함수들*/
void storeStatus(); // 가계 상태 확인
void checkSellMenu(); // 주문 완료 확인
void inOrderCheckSellMenu(); // 매장 완료 주문 확인
void outOrderCheckSellMenu(); // 배달 완료 주문 확인
void sameCheckSellMenu(string fileName); // 매장 , 배달 주문에서 준 매개변수로 처리하는 완료 주문 확인
void checkTotalPrice();//당일 매출액
void MonthSellPrice();//해당 달 매출액

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
