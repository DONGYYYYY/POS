#include "Myheader.h"
#include "Function.h"
#include "Menu.h"
#include "MakeFx.h"
#include "MenuFunction.h"
#include "StatusFunction.h"

extern Menu *obj;

void checkMenu() { // �޴� ���� �޴� (��� �޴�ȭ�� switch case�� ����!
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : �޴��� Ȯ��";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : �޴� ����"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 :    ����";		gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "=============================" << endl;
		gotoxy(25, 5); cout << "�Է� : ";
		cin >> menu;
		if (cin.fail())
		{
			cin.clear();
			menu = 0;
		}
		cin.ignore();
		switch (menu) {
		case 1:
			system("cls");
			MyMenu();
			break;

		case 2:
			system("cls");
			changeMenu();
			break;
		case 3:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

void MyMenu() // ���� ���õǾ� �ִ� �޴� Ȯ�� ( �޴��� Ȯ�� )
{
	system("cls");
	int ye;
	while (1) {
		for (int i = 0; i < obj->getSize(); i++)
		{
			cout << "�޴� �̸� : " << obj->getMenuName(i) << "\t���� : " << obj->getMenuPrice(i) << endl;
		}
		cout << "����� ������ Ȯ���ϼ̽��ϱ�? (1 : ����) >>>";
		cin >> ye;
		if (cin.fail())
		{
			cin.clear();
			ye = NULL;
		}
		cin.ignore();
		system("cls");
		if (ye == 1)
			break;
	}
}

void changeMenu() // �޴� ���� ��� ( �޴� ���� )
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : �޴� �߰�";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : �޴� �̸� ����"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : �޴� ���� ����"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : �޴� ���� �̸� ����"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 : �޴� ���� ����"; gotoxy(48, 5); cout << "|" << endl;
		gotoxy(20, 6); cout << "|"; gotoxy(25, 6); cout << "6 : �޴� ����"; gotoxy(48, 6); cout << "|" << endl;
		gotoxy(20, 7); cout << "|"; gotoxy(25, 7); cout << "7 : ����"; gotoxy(48, 7); cout << "|" << endl;
		gotoxy(20, 8); cout << "=============================" << endl;
		gotoxy(25, 9); cout << "�Է� : ";
		cout << "               ";
		gotoxy(31, 9);
		cin >> menu;
		if (cin.fail())
		{
			cin.clear();
			menu = 0;
		}
		cin.ignore();
		switch (menu) {
		case 1:
			system("cls");
			MenuAdd();
			break;

		case 2:
			system("cls");
			changeMenuName();
			break;
		case 3:
			system("cls");
			changeMenuPrice();
			break;
		case 4:
			system("cls");
			changeAll();
			break;
		case 5:
			system("cls");
			sortMenu();
			break;
		case 6:
			system("cls");
			deleteMenu();
			break;
		case 7:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

void MenuAdd() // �޴� �߰�
{
	obj->addMenu(); // �޴� Ŭ������ addMenu()ȣ��
}

void changeMenuName() { // �޴� �̸� ����
	int ye;
	string name;
	obj->checkMenu(); // �޴� Ŭ������ checkMenu()ȣ��
	cout << "�̸� ������ ���ϴ� �޴� �̸��� �Է��Ͻÿ� : ";
	getline(cin, name);
	int count = 0;
	for (int i = 0; i < obj->getSize(); i++) {
		if (name == obj->getMenuName(i)) {
			cout << "������ �޴� �̸��� �Է��Ͻÿ� : ";
			string changeName;
			getline(cin, changeName);
			obj->setMenuName(i, changeName); // �޴� �̸� ����
			obj->findMenu(); // ��ü ���� ����
			return;
		}
		else {
			count++;
		}
	}
	if (count == obj->getSize()) {
		system("cls");
		cout << "�Է��� �޴� �̸��� ��ġ�ϴ� �޴��� �����ϴ�." << endl;
	}
	cout << "" << endl;
	cout << "�ƹ� Ű�� �����ÿ�. >>>";
	cin >> ye;
	if (cin.fail())
	{
		cin.clear();
		ye = 0;
	}
	cin.ignore();
	system("cls");


}

void changeMenuPrice() // �޴� ���� ����
{
	int ye;
	string name;
	string temp;
	int changePrice;
	obj->checkMenu();
	cout << "���� ������ ���ϴ� �޴� �̸��� �Է��Ͻÿ� : ";
	getline(cin, name);
	int count = 0;
	for (int i = 0; i < obj->getSize(); i++) {
		if (name == obj->getMenuName(i)) {
			system("cls");
			cout << name << "�� ���� = " << obj->getMenuPrice(i) << " ������ �޴� ������ �Է��Ͻÿ� : ";
			getline(cin, temp);
			try
			{
				changePrice = stoi(temp.c_str()); // �Է� ���� ���ڰ� �ƴѰ�� ( ���ڿ��� �Է¹޾Ƽ� ����ó���� �ذ� )
				obj->setMenuPrice(i, changePrice); // ���� ���� �޼ҵ�
				obj->findMenu(); // ��ü ���� ����
				return;
			}
			catch (invalid_argument&) // ���� �߻���( ���ڿ��� ������ �ƴ� ���ڰ� ���� ��� )
			{
				i--;
				cout << "���ݿ� ���ڰ� �ƴ� ���� �ԷµǾ����ϴ�.";
				Sleep(1000);
			}
		}
		else {
			count++;
		}
	}
	if (count == obj->getSize()) {
		system("cls");
		cout << "�Է��� �޴� �̸��� ��ġ�ϴ� �޴��� �����ϴ�." << endl;
	}
	cout << "" << endl;
	cout << "�ƹ�Ű�� �Է��Ͻÿ�.";
	cin >> ye;
	if (cin.fail())
	{
		cin.clear();
		ye = 0;
	}
	cin.ignore();
	system("cls");

}

void changeAll() { // �޴� ���� , �̸� ���� ����
	string name;
	string temp;
	int changePrice;
	obj->checkMenu();
	cout << "�̸� ������ ���ϴ� �޴� �̸��� �Է��Ͻÿ� : ";
	getline(cin, name);
	int count = 0;
	for (int i = 0; i < obj->getSize(); i++) {
		if (name == obj->getMenuName(i)) {
			cout << "������ �޴� �̸��� �Է��Ͻÿ� : ";
			string changeName;
			getline(cin, changeName);
			while (1) {
				system("cls");
				cout << changeName << "�� ���� = " << obj->getMenuPrice(i) << " ������ �޴� ������ �Է��Ͻÿ� : ";
				getline(cin, temp);
				try
				{
					changePrice = stoi(temp.c_str()); // ���� �߻��� �� �ִ� �κ�
					obj->setAll(i, changeName, changePrice); // ���� , �̸� ���� ����
					obj->findMenu(); // ���� ����
					break;
				}
				catch (invalid_argument&) // ���� �߻���
				{
					cout << "���ݿ� ���ڰ� �ƴ� ���� �ԷµǾ����ϴ�." << endl;
					Sleep(1000);
				}
			}
		}
		else {
			count++;
		}
	}
	if (count == obj->getSize()) {
		system("cls");
		cout << "�Է��� �޴� �̸��� ��ġ�ϴ� �޴��� �����ϴ�." << endl;
		Sleep(1000);
		system("cls");
	}
}

void sortMenu() // �޴� ���� ���� �޼ҵ�
{
	int number1 = 0;
	int number2 = 0;
	bool can = true;
	while (1) {
		system("cls");
		obj->checkMenu();
		cout << "������ �ٲ� �޴� ù��° ��ȣ�� �Է��ϼ��� : (0 = ����)";
		cin >> number1;
		if (cin.fail())
		{
			can = false;
			cin.clear();
		}
		cin.ignore();
		cout << "������ �ٲ� �޴� �ι�° ��ȣ�� �Է��ϼ��� : (0 = ����)";
		cin >> number2;
		if (cin.fail())
		{
			can = false;
			cin.clear();
		}
		cin.ignore();
		if (number1 == 0 || number2 == 0 || can == false) // �Է� �� ���� �ϳ��� 0�̰ų� �Է°��� ���ڰ� �ƴ� ���� ���� ���
		{
			cout << "������ �����մϴ�." << endl;
			Sleep(2000);
			system("cls");
			break;
		}
		else if (number1 > obj->getSize() || number2 > obj->getSize()) // �����ϴ� �޴��� �ƴ� ���� �Է����� ���
		{
			cout << "�������� �ʴ� �޴� ��ȣ�� �ֽ��ϴ�." << endl;
			Sleep(2000);
			system("cls");
		}
		else { // �޴� ������ �� ��� ( ������ )
			string tempMenuName = obj->getMenuName(number1 - 1);
			int tempMenuPrice = obj->getMenuPrice(number1 - 1);
			obj->setMenuName(number1 - 1, obj->getMenuName(number2 - 1));
			obj->setMenuPrice(number1 - 1, obj->getMenuPrice(number2 - 1));
			obj->setMenuName(number2 - 1, tempMenuName);
			obj->setMenuPrice(number2 - 1, tempMenuPrice);
			system("cls");
			cout << "���� �Ϸ� " << endl;
			obj->fixMenu();
			obj->checkMenu();
			Sleep(2000);
		}
	}
}

void deleteMenu() // �޴� ����
{
	string name;
	obj->checkMenu();
	cout << "�޴� ������ ���ϴ� �޴� �̸��� �Է��Ͻÿ� : ";
	getline(cin, name); 
	bool success = false;
	for (int i = 0; i < obj->getSize(); i++) {// �迭�� ũ����� �ݺ�
		if (name == obj->getMenuName(i)) { // ���� �̸��� ã�� ���
			obj->setAll(i, "", NULL); // ����
			cout << "���� �� " << endl;
			obj->fixMenu(); // ���Ͽ� ����
			obj->checkMenu(); //���Ͽ��� ������ �о�� ��ü�� ����
			success = true; // ����
			Sleep(2000);
			break;
		}
	}
	if (success == false) { // ���н�
		system("cls");
		cout << "�Է��� �޴� �̸��� ��ġ�ϴ� �޴��� �����ϴ�." << endl;
		Sleep(2000);
	}
	system("cls");


}
