#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
Menu *obj; // ���� ��ü ���� obj
int main()
{
	obj = new Menu();
	system("cls");
	mainPrint();
	delete obj;
}
