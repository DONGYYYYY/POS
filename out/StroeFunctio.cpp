#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
#include "MakeFx.h"
#include "StoreFunction.h"
#include "StatusFunction.h"


void storeStatus() // ���� ��Ȳ
{
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : �Ϸ�� �ֹ� Ȯ��";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : ���� �����"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : �ش� �� �� �����"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : ���÷���"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 : ����"; gotoxy(48, 5); cout << "|" << endl;
		gotoxy(20, 6); cout << "=============================" << endl;
		gotoxy(25, 7); cout << "�Է� : ";
		cin >> menu;
		if (cin.fail())
		{
			menu = -1;
			cin.clear();
		}
		cin.ignore();
		switch (menu)
		{
		case 1:
			checkSellMenu(); // �Ϸ�� �ֹ� Ȯ��
			break;
		case 2:
			checkTotalPrice(); // ���� �����
			break;
		case 3:
			MonthSellPrice(); // �ش� �� �� �����
			break;
		case 4:
			checkComplain(); // ���÷��� 
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}

void checkTotalPrice() // �� �Ǹž� Ȯ��
{
	system("cls");
	int ye;
	string priceFile = "C:\\";
	priceFile += currentDate();
	priceFile += "-sales.txt";
	ifstream Sell(priceFile, ios::in);
	if (!Sell) // ���� ���� ���н�
	{
		cout << "���� ������ �����ϴ�.";
		Sleep(2000);
		return;
	}
	int totalPrice;
	string buffer;
	getline(Sell, buffer); // ������ �о�´�.
	totalPrice = atoi(buffer.c_str()); // totalPrice�� ���ڿ��� ������ ��ȯ�ϴ� atoi�� ����Ͽ� ���� �����Ѵ�
	cout << "���� �Ǹž� : " << totalPrice << endl; // �ܼ�â�� ���
	cout << "����� ��ġ�ڽ��ϱ�?" << endl;
	cin >> ye;
	cin.ignore(); // ���� �����
	Sell.close();//���� �ݱ�
}
void MonthSellPrice() // �ش� �� �� �����
{
	/* ���� ��¥�� �˱� ���ؼ� ����ϴ� time���� �Լ� */
	time_t now = time(0);
	struct tm tstruct;
	char day[80];
	tstruct = *localtime(&now);
	strftime(day, sizeof(day), "%d", &tstruct); // tstruct���� %d�� �ش��ϴ� ���� day(��)�̴�.
	int howday = atoi(day);

	system("cls");
	int ye;
	string dayFile = "C:\\";
	dayFile += currentDate();
	dayFile += "-sales.txt";
	ifstream daySell(dayFile);

	if (!daySell) // ���� ���� ���� ��
	{
		cout << "���� ������ �����ϴ�.";
		Sleep(2000);
		return;
	}
	int dayPrice;
	string buffer;
	getline(daySell, buffer);
	dayPrice = atoi(buffer.c_str());
	string priceFile = "C:\\";
	priceFile += currentMonth();
	priceFile += "-sales.txt";
	ifstream Sell(priceFile); // �б� �������� ���� ����
	if (!Sell) // ���� ���� ���� ��
	{
		cout << "�̹� �� ������ �����ϴ�.";
		Sleep(2000);
		return;
	}
	int totalPrice;
	getline(Sell, buffer); // �ش� ���� ���� �б�
	totalPrice = atoi(buffer.c_str()); // ���ڿ����� ���������� �ٲ㼭 totalPrice ������ ���� ����.
	cout << "�̹� �� �� ����� : " << totalPrice << endl;
	cout << endl << "===============================================================================" << endl;
	cout << "�̹� �� ��� ����� : " << totalPrice / howday << endl;
	cout << endl << "===============================================================================" << endl;
	cout << "�̹� �� ��� ����װ� ���� ����� �� : " << dayPrice - (totalPrice / howday) << endl;
	cout << endl << "===============================================================================" << endl;
	cout << "����� ��ġ�ڽ��ϱ�?" << endl;
	cin >> ye;
	if (cin.fail()) //�Է°��� ������ �ƴѰ��
	{
		cin.clear(); // clear�� ���ؼ� cin���� �Է°��� �ʱ�ȭ
	}
	cin.ignore(); // cin�� ���۸� �����ش�
	Sell.close(); // ���� �ݱ�
}

void checkSellMenu() // �Ϸ� �ֹ� Ȯ�� ���
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : ���� �Ϸ� �ֹ� Ȯ��";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : ��� �Ϸ� �ֹ� Ȯ��"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : ����"; gotoxy(48, 3); cout << "|" << endl;
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
			inOrderCheckSellMenu(); // ���� �Ϸ� �ֹ� Ȯ��
			break;
		case 2:
			outOrderCheckSellMenu(); // ��� �Ϸ� �ֹ� Ȯ��
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}


void inOrderCheckSellMenu() // ���� �ֹ� �Ϸ� Ȯ��
{
	string completeName = "C:\\";
	completeName += currentDate();
	completeName += "-completeInOrder.txt";
	sameCheckSellMenu(completeName);
}
void outOrderCheckSellMenu() // ��� �ֹ� �Ϸ� Ȯ��
{
	string completeName = "C:\\";
	completeName += currentDate();
	completeName += "-completeOutOrder.txt";
	sameCheckSellMenu(completeName);
}
void sameCheckSellMenu(string fileName) // ���� �̸��� ���� ���� , ��� �ֹ� �Ϸ� Ȯ��
{
	system("cls");
	int size = 0;
	int ye;
	string buffer[100];

	ifstream Menus(fileName); // ���� �б� �������� ����
	if (!Menus) // ���� ���� ���н�
	{
		cout << "���� �ֹ��� �޴��� �����ϴ�.";
		Sleep(2000);
		return;
	}
	while (!Menus.eof()) {
		getline(Menus, buffer[size]); // ���� ���� �� �о buffer[size]�� ���� ����
		if (buffer[size] != "") { // buffer[size]���� ""�� �ƴ� ���
			cout << "�Ϸ�� �ֹ� " << size + 1 << "\t�޴� �̸� : " << buffer[size] << endl;
			cout << "===============================================================================" << endl;
			size++; // ���� ��������� ����Ű�� ���ؼ� size�� ++
		}
	}
	while (1) {
		cout << "����� ������ Ȯ���ϼ̽��ϱ�? (1 : ����) >>>";
		cin >> ye;
		if (ye == 1) {
			system("cls");
			break;
		}
	}
	Menus.close(); // ���� �ݱ�
}


void checkComplain() // ���÷���
{
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : ���÷��� Ȯ��";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : ���÷��� �ۼ�"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : ���÷��� �ʱ�ȭ"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : ����"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "=============================" << endl;
		gotoxy(25, 6); cout << "�Է� : ";
		cin >> menu;
		if (cin.fail()) // �Է� ���� ������ �ƴ� ���� ���� ���
		{
			cin.clear(); // cin�� ����ش�.
			menu = NULL; // menu���� NULL�� �ʱ�ȭ �Ѵ�.
		}
		cin.ignore(); // ���۸� �����ش�.
		switch (menu)
		{
		case 1:
			readComplain(); // ���÷��� Ȯ��
			break;
		case 2:
			writeComplain(); // ���÷��� �ۼ�
			break;
		case 3:
			resetComplain(); // ���÷��� �ʱ�ȭ
			break;
		case 4:
			return; // ����
		default:
			break;
		}
	}
}

void readComplain() // ���÷��� �б�
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "====================================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(23, 1); cout << "1 : ī���� ���� ���÷��� �б�";		gotoxy(55, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(23, 2); cout << "2 : �ֹ� ���� ���÷��� �б�"; gotoxy(55, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(23, 3); cout << "3 : ����"; gotoxy(55, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "====================================" << endl;
		gotoxy(25, 5); cout << "�Է� : ";
		cin >> menu;
		if (cin.fail())
		{
			cin.clear(); // cin�� ����ش�.
			menu = NULL; // menu���� NULL�� �ʱ�ȭ �Ѵ�.
		}
		cin.ignore();
		switch (menu)
		{
		case 1:
			inReadComplain(); // ī���� ���� ���÷��� �б�
			break;
		case 2:
			outReadComplain(); // �ֹ� ���� ���÷��� �б�
			break;
		case 3:
			return; // ����
		default:
			break;
		}
	}
}

void writeComplain() // ���÷��� ����
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "====================================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(23, 1); cout << "1 : ī���� ���� ���÷��� ����";		gotoxy(55, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(23, 2); cout << "2 : �ֹ� ���� ���÷��� ����"; gotoxy(55, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(23, 3); cout << "3 : ����"; gotoxy(55, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "====================================" << endl;
		gotoxy(25, 5); cout << "�Է� : ";
		cin >> menu;
		if (cin.fail())
		{
			cin.clear(); // ���� �÷��׸� �ʱ�ȭ. cin.fail�� �ʱ�ȭ �Ͽ� ���� �ݺ��Ǵ� ���� ����.
			menu = NULL; // menu���� NULL�� �ʱ�ȭ �Ѵ�.
		}
		cin.ignore(); // ���۸� �����
		switch (menu)
		{
		case 1:
			inWriteComplain(); // ī���� ���� ���÷��� ����
			break;
		case 2:
			outWriteComplain(); // �ֹ� ���� ���÷��� ����
			break;
		case 3:
			return; // ����
		default:
			break;
		}
	}
}

void inReadComplain() // ī���� ���� ���÷��� �б�
{
	string fileName;
	fileName = "C:\\inComplain.txt";
	sameReadComplain(fileName);
}
void outReadComplain() // �ֹ� ���� ���÷��� �б�
{
	string fileName;
	fileName = "C:\\outComplain.txt";
	sameReadComplain(fileName);
}
void sameReadComplain(string fileName) // �Ű������� ���� �� ���� ī���� , �ֹ� ���÷��� �б� �۾�
{
	system("cls");
	string buffer;
	ifstream complain(fileName); // ���� �б� �������� ����
	if (!complain) // ���� ���� ���� ��
	{
		cout << "���÷��� ������ �������� �ʽ��ϴ�.";
		Sleep(1000);
		return;
	}
	while (!complain.eof()) // ���� ������ �б�( ���� ��� �ݺ��� Ż�� )
	{
		getline(complain, buffer); // buffer�� ���� ���� ����
		if (buffer != "") {
			cout << buffer << endl; // ���� ���� ���
			cout << "===============================================================================" << endl;
		}
	}
	cout << "���÷����� Ȯ���ϼ̽��ϱ�?";
	int ye;
	cin >> ye;
	cin.ignore(); // ���� �����
	complain.close(); // ���� �ݱ�
}

void inWriteComplain() // ī���� ���÷��� ����
{
	string fileName;
	fileName = "C:\\inComplain.txt";
	sameWriteComplain(fileName);
}
void outWriteComplain() // �ֹ� ���÷��� ����
{
	string fileName;
	fileName = "C:\\outComplain.txt";
	sameWriteComplain(fileName);
}
void sameWriteComplain(string fileName) // ���� �� ���� ī���� , �ֹ� ���÷��� �ۼ� �۾�
{
	system("cls");
	string buffer;
	ofstream complain(fileName, ios::app); // ���� ���� �������� ���� ( ios::app �� ���� ���Ͽ��� �̾ ������ ���� �ɼ� (�����̱�))
	while (1) // ���� �ݺ�
	{
		cout << "������ �Է��ϼ��� : ( ���� == 0 )";
		getline(cin, buffer); // ���ڿ��� �ܼ�â���� ���� �Է� �޴´�.
		if (buffer == "0") // �Է� ���� ���� 0�� ���
		{
			break; // �ݺ��� Ż��
		}
		else // �� ���� ���
		{
			complain << buffer << endl; // �Է� ������ ���Ͽ� ���� �ٹٲ��� �Ѵ�.
		}
	}
	complain.close(); // ���� �ݱ�
}


void resetComplain() // ���÷��� �ʱ�ȭ �޴�
{
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "====================================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(23, 1); cout << "1 : ī���� ���� ���÷��� �ʱ�ȭ";		gotoxy(55, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(23, 2); cout << "2 : �ֹ� ���� ���÷��� �ʱ�ȭ"; gotoxy(55, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(23, 3); cout << "3 : ����"; gotoxy(55, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "====================================" << endl;
		gotoxy(25, 5); cout << "�Է� : ";

		cin >> menu;
		if (cin.fail()) // ���� �̿��� ���� �Է� �Ǿ��� ���
		{
			cin.clear(); // cin�� ����ش�.
			menu = NULL; // menu���� NULL�� �ʱ�ȭ �Ѵ�.
		}

		cin.ignore(); // ���۸� �����.
		switch (menu)
		{
		case 1:
			resetInComplain(); // ī���� ���� ���÷��� �ʱ�ȭ
			break;
		case 2:
			resetOutComplain(); // �ֹ� ���� ���÷��� �ʱ�ȭ
			break;
		case 3:
			return; // ����
		default:
			break;
		}
	}
}
void resetInComplain() // ī���� ���� ���÷��� �ʱ�ȭ
{
	string fileName;
	fileName = "C:\\inComplain.txt";
	sameWriteComplain(fileName);
}

void resetOutComplain() // �ֹ� ���� ���÷��� �ʱ�ȭ
{
	string fileName;
	fileName = "C:\\outComplain.txt";
	sameWriteComplain(fileName);
}

void resetSameComplain(string fileName) // �Ű������� ���ϸ� ���� ī���� , �ֹ� ���� ���÷��� �ʱ�ȭ �۾�
{
	system("cls");
	ofstream complain(fileName, ios::trunc); // �б� �������� ���� ���� (ios::trunc = ������ ������ ��� ���� ������ �����.(�����))
	complain.close(); // ������ �ݴ´�.
	cout << "���÷��� ���� �ʱ�ȭ �Ϸ�";
	Sleep(1000);
}
