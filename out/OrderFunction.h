#include "Myheader.h"

/*주문 관련 함수*/
void orderMenu(); // 주문 메뉴
void inOrder(); // 매장 주문
void outOrder(); // 배달 주문
void sameOrder(string fileName);
/*주문 수정*/
void fixOrder(); // 주문 수정
void inOrderfix(); // 매장 주문 메뉴 수정
void outOrderfix(); // 배달 주문 메뉴 수정
void sameOrderFix(string fileName); // 매장 배달에서 준 매개변수로 처리하는 메뉴 수정
void plusInOrder(); // 매장 주문 추가
void plusOutOrder(); // 배달 주문 추가
void samePlusOrder(string fileName); // 매장 배달에서 준 매개 변수로 처리하는 주문 내역 추가
									 /*주문 취소 함수들*/
void cancelOrderMenu(); // 주문 취소
void cancelNumberOutOrderMenu(); // 배달 주문 낱개 취소
void cancelNumberInOrderMenu(); // 매장 주문 낱개 취소
void cancelNumberOrderMenu(string fileName); // 매장 , 배달 주문 취소에서 준 매개변수로 처리하는 주문 취소
void cancelNumberInOrderAllMenu(); // 매장 주문 전체 취소
void cancelNumberOutOrderAllMenu(); // 배달 주문 전체 취소
void cancelNumberOrderAllMenu(string fileName); // 매장 , 배달 주문 취소에서 준 매개변수로 처리하는 주문 전체 취소
