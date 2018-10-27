#include "Myheader.h"

class Menu {
private:
	int totalPrice; // 총 판매액
	int *menuPrice; // 메뉴 가격(동적할당)
	int size; // 메뉴 크기(동적 할당에 쓰일 크기)
	string *menuName; // 메뉴 이름 (동적할당)
public:
	Menu(); // 생성자
	~Menu(); // 소멸자
			 //Menu(const Menu& copy);//복사생성자 (생략)
	void MakeMenu(); // 메뉴생성
	void setMenuPrice(int index, int menuPrice); // 메뉴 변경
	void setMenuName(int index, string menuName); // 가격 변경
	void addMenu(); // 메뉴 추가
	int getTotalPrice(); // 총 판매액 반환
	int getMenuPrice(int index); // 메뉴 가격 반환
	string getMenuName(int index); // 메뉴 이름 반환
	void findMenu(); //메뉴 파일 확인 및 대기
	int getSize(); // Size getter
	void checkMenu(); // 메뉴 파일 내용 확인 (대기 x) 메뉴확면을 띄운 후 다른 작업 처리시 사용
	void setAll(int index, string menuName, int menuPrice); // 메뉴 가격과 메뉴 이름을 동시에 set
	void setTotalPrice(int totalPrice); // 총판매액 setter
	void plusTotalPrice(int price); // 총판매액 매개변수 값만큼 증가
	int takePrice(string menuName); // 매개변수(메뉴 이름)과 일치하는 메뉴 찾은 후 그 메뉴의 가격 반환
	void fixMenu();
};
