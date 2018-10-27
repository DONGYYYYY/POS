#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
#include "MakeFx.h"
#include "PayFunction.h"
#include "StatusFunction.h"

extern Menu *obj;

void payMenu() // ��� ���
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : ���� �ֹ� ���";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : ��� �ֹ� ���"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : ó������"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 4); cout << "=============================" << endl;
		gotoxy(25, 5); cout << "�Է� : ";
		cin >> menu;
		if (cin.fail())
		{
			cin.clear();
			menu = -1;
		}
		cin.ignore();
		switch (menu)
		{
		case 1:
			inPayMenu();
			break;
		case 2:
			outPayMenu();
			break;
		case 3:
			return;
		default:
			break;
		}

	}
}
void inPayMenu() // ���� �ֹ� ���
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	string completeName = "C:\\";
	completeName += currentDate();
	completeName += "-completeInOrder.txt";
	samePayMenu(fileName, completeName);
}
void outPayMenu() // ��� �ֹ� ���
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	string completeName = "C:\\";
	completeName += currentDate();
	completeName += "-completeOutOrder.txt";
	samePayMenu(fileName, completeName);
}

void samePayMenu(string fileName, string completeName) // ���� ���뿡 ���� ���� , ��� �ֹ� ���
{
	bool complete = false;
	int size = 0;
	int ye;
	int soldMoney;
	int temp;
	string tempBuffer;
	string buffer[100];
	string name[100];
	string *tokName;
	string *tempTok;
	int find = 0;
	int count = 0;
	//�� ���⿡ �ش��ϴ� ����
	string priceFile = "C:\\";
	priceFile += currentDate();
	priceFile += "-sales.txt";

	//�� ���⿡ �ش��ϴ� ����
	string MonthSale = "C:\\";
	MonthSale += currentMonth();
	MonthSale += "-sales.txt";

	ifstream Menus(fileName); // �ϱ� �������� ���� ����
	while (!Menus.eof()) { // ���� ������ �б�
		system("cls");
		getline(Menus, buffer[size]);
		name[size] = buffer[size];
		if (name[size] != "") {
			tokName = StringSplit(name[size], "\t");
			for (int i = 0; !tokName[i].empty(); i++) {
				if (tokName[i] == "O" && complete == false) { // �ش� ��ū�� O�̰� complete�� false�� ���
					cout << name[size]; //�ش� �ֹ� ��ȣ�� �ش��ϴ� �޴� ������ ���
					cout << endl << "�̹� �޴��� �����Ͻðڽ��ϱ� ? (1 : yes)";
					cin >> ye;
					if (cin.fail())
					{
						cin.clear();
						ye = NULL;
					}
					cin.ignore();
					if (ye == 1)
					{
						temp = i - 1; // �޴� ���ݿ� �ش��ϴ� ��ġ�� temp�� ����
						tokName[i] = "C"; // O�� �ش��ϴ� ���ڿ��� C�� �ٲٱ� ���� tokName[i]�� ���� ����
						for (int j = 0; j <= i; j++) {
							if (j == 0) {
								tempBuffer = tokName[j];
							}
							else {
								tempBuffer += "\t";
								tempBuffer += tokName[j];
							}
						}
						tempTok = tokName;
						buffer[size] = "";
						complete = true;
						break; // �ݺ��� Ż��

					}
				}
			}
			size++;
		}
	}
	if (complete == false) { // ����� �������� �ʰų� ��� �� ���� ���� ���
		cout << "����� ���̺��� �����ϴ�." << endl;
		cout << "����� ��ġ�ڽ��ϱ�?" << endl;
		cin >> ye;
		cin.ignore();
		Menus.close();
		return;
	}
	else {
		string priceTemp;
		int MonthSaleInt;
		string MonthTemp;
		ifstream readMenus(priceFile);
		ifstream readMonth(MonthSale); // ���� �ʿ� �Ѵ� ����� �ۼ� ������ ���� ��쿡 ���� ����
		if (!readMonth)
		{
			MonthSaleInt = 0;
		}
		else {
			getline(readMonth, MonthTemp);
			MonthSaleInt = atoi(MonthTemp.c_str()); // ���ڿ��� ������ �ٲ㼭 ���� ����
			readMonth.close(); // ���� �ݱ�
		}
		ofstream writeMenus(fileName, ios::trunc); // ����� �������� ���� ���� ����
		ofstream completeMenus(completeName, ios::app); // �����̱� �������� ���� ���� ����
		completeMenus << tempBuffer << endl;

		for (int i = 0; i <= size; i++)
		{
			if (buffer[i] != "")
			{
				writeMenus << buffer[i] << endl;
			}
		}
		writeMenus.close();
		if (complete == true) {
			getline(readMenus, priceTemp);
			soldMoney = atoi(tempTok[temp].c_str());
			obj->setTotalPrice(atoi(priceTemp.c_str()));
			obj->plusTotalPrice(soldMoney);
			cout << "�Ǹ� �ݾ� : " << soldMoney << endl;
			cout << tempBuffer << endl;
		}
		ofstream Sell(priceFile, ios::trunc);
		ofstream MonthSell(MonthSale, ios::trunc);
		int totalPrice = obj->getTotalPrice();
		MonthSaleInt += soldMoney;
		MonthSell << MonthSaleInt;
		Sell << totalPrice;
		cout << "���� �Ǹž� : " << obj->getTotalPrice() << endl;
		cout << "����� ��ġ�ڽ��ϱ�?" << endl;
		cin >> ye;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore();
		Menus.close();
		Sell.close();
	}
}
