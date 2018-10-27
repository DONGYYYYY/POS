#include "Myheader.h"

/*주문 상태 확인*/
void orderStatus(); // 주문 상태 확인
void inOrderStatus(); // 매장 주문 상태 확인
void outOrderStatus(); // 배달 주문 상태 확인
void sameOrderStatus(string fileName); // 매장 , 배달 주문에서 준 매개변수로 처리하는 주문 상태 확인

void checkOrderMenu(string fileName); // 주문 메뉴 확인 (요구사항을 제외한)
