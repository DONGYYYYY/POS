#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
Menu *obj; // 전역 객체 변수 obj
int main()
{
	obj = new Menu();
	system("cls");
	mainPrint();
	delete obj;
}
