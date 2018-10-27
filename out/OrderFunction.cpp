#include "Myheader.h"
#include "Function.h"
#include "Menu.h"
#include "MakeFx.h"
#include "OrderFunction.h"
#include "StatusFunction.h"

extern Menu *obj;

void orderMenu() { // �޴� �ֹ�
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : ���� �ֹ�";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : ��� �ֹ�"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : �ֹ� ����"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : �ֹ����� ����"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 : ����"; gotoxy(48, 5); cout << "|" << endl;
		gotoxy(20, 6); cout << "=============================" << endl;
		gotoxy(25, 7); cout << "�Է� : ";
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
			inOrder();
			break;
		case 2:
			outOrder();
			break;
		case 3:
			fixOrder();
			break;
		case 4:
			cancelOrderMenu();
			break;
		case 5:
			system("cls");
			return;
		default:
			system("cls");
		}
	}
}

void inOrder() // ���� �ֹ� 
{
	int price = 0;
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	sameOrder(fileName);
}
void outOrder() // ��� �ֹ� 
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-OutOrder.txt";
	sameOrder(fileName);

}

void sameOrder(string fileName) // �Ű������� ���� ���� , ��� �ֹ� 
{
	int price = 0;
	int wanner;
	string want;
	int count;
	int howmany = 0;
	ofstream Menus(fileName, ios::app); // ���� �̾� ����
	while (1) {
		system("cls");
		obj->checkMenu();
		cout << "�ֹ��� �޴��� �����ϼ��� : (0 = ����)(�޴��� ������ ���� 1���� ����)";
		cin >> count;
		if (cin.fail())
		{
			cin.clear();
			count = NULL;
		}
		cin.ignore();
		if (count > obj->getSize())
		{
			cout << "�������� �ʴ� �޴� ��ȣ�� �Է��ϼ̽��ϴ�." << endl;
			Sleep(2000);
		}
		else {
			howmany++;
			if (count == 0) { // 0 Ȥ�� ���� ���� ���� �Էµ� ��� ����
				if (howmany == 1) // 0 ���� ���ڰ� ���� �Էµ��� ���� ��� �Էµ� ���� ���ٴ� ���� �˷��ְ� ����
				{
					cout << "�޴� �Է��� �ϳ��� ���� �ʾҽ��ϴ�." << endl;
					Sleep(1000);
					break;
				}
				Menus << price << "\t"; // ���� ���Ͽ� ����
				Menus << "X" << "\t"; // �ϼ� ���� ���Ͽ� ����
				cout << "���ϴ� �䱸������ �����ʴϱ�? ( 1 : yes ) >> ";
				cin >> wanner;
				if (cin.fail())
				{
					cin.clear();
					wanner = NULL;
				}
				cin.ignore();
				if (wanner == 1) // �䱸������ ���� ��
				{
					cout << "�䱸 ���� : ";
					getline(cin, want);
					Menus << "�䱸 ���� : " << want << endl; // ���Ͽ� �䱸���� ���� ����
				}
				else // ���� ��
				{
					cout << "�䱸 ���� ���� X ";
					Sleep(1000);
				}
				break;
			}
			else { // 0�� �Է��� �Ǳ� �������� �޴��� ������ ���Ͽ� ���� �� ������ �˱� ���ؼ� price������ �޴� ���ݸ�ŭ ����
				price += obj->getMenuPrice(count - 1);
				string MenuN = obj->getMenuName(count - 1);
				Menus << MenuN << "\t";
			}
		}
	}
	Menus << endl; // ���� �ٹٲ�
	Menus.close();//���� �ݱ�
}

void fixOrder() // �ֹ� ����
{
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : ���� �ֹ� ����";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : ��� �ֹ� ����"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : ���� �ֹ� �߰�";		gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : ��� �ֹ� �߰�"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 5); cout << "|"; gotoxy(25, 5); cout << "5 : ����"; gotoxy(48, 5); cout << "|" << endl;
		gotoxy(20, 6); cout << "=============================" << endl;
		gotoxy(25, 7); cout << "�Է� : ";
		int menu;
		cin >> menu;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore();
		switch (menu)
		{
		case 1:
			system("cls");
			inOrderfix();
			break;
		case 2:
			system("cls");
			outOrderfix();
			break;
		case 3:
			system("cls");
			plusInOrder();
			break;
		case 4:
			system("cls");
			plusOutOrder();
			break;
		case 5:
			system("cls");
			return;
		default:
			break;
		}
	}
}
void inOrderfix() { // ���� �ֹ� ����
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	sameOrderFix(fileName);
}

void outOrderfix() { // ��� �ֹ� ����
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	sameOrderFix(fileName);
}

void sameOrderFix(string fileName) // �ֹ� ����
{
	system("cls");
	int size = 0;
	string tempBuffer;
	string buffer[100];
	string name[100];
	int totalPrice;
	string *strTok;
	int count = 0;
	checkOrderMenu(fileName);
	ifstream Menus(fileName); // ���� �б�
	while (!Menus.eof()) { // ���� ������ �б�
		getline(Menus, buffer[size]); // ���� �ٴ����� �б�
		if (buffer[size] != "") {
			size++;
		}
	}
	Menus.close();
	cout << "���� Ȥ�� ��Ҹ� ���ϴ� �ֹ� ��ȣ�� �Է��Ͻÿ� : ";
	int index;
	cin >> index;
	if (cin.fail())
	{
		system("cls");
		cin.clear();
		cin.ignore();
		index = 0;
		cout << "���ڰ� �ƴ� Ű�� �ԷµǾ����ϴ�.";
		Sleep(1000);
	}
	else
	{
		cin.ignore();
		system("cls");
		if (index > size)
		{
			cout << "���ڸ� �ʰ��Ͽ����ϴ�." << endl;
			Sleep(1000);
		}
		if (index == 0)
		{
			cout << "����" << endl;
			Sleep(1000);
			return;
		}
		else {
			while (1) {
				if (index > size)
				{
					break;
				}
				system("cls");
				int tempNumber = 0;
				tempBuffer = ""; // ������ �޴� ������ �����ϱ� ���� ���ڿ� �ʱ�ȭ
				strTok = StringSplit(buffer[index - 1], "\t");
				for (int i = 0; !strTok[i].empty(); i++) {
					if (strTok[i] != "O" && isStringDouble(strTok[i].c_str()) != 1) {
						if (strTok[i] != "X")
						{
							cout << strTok[i] << "\t";
						}
					}
				}
				cout << endl << "�ش� �ֹ����� �����ϱ⸦ ���ϴ� �޴��� �Է��Ͻÿ� .(0 = ����) :";
				string menuName;
				getline(cin, menuName);
				if (menuName == "0") // �޴��� �Ϸ�� �޴��̸� ���� �Ұ�
				{
					break;
				}
				for (int i = 0; !strTok[i].empty(); i++) // �޴� �� ���ݿ� �ش��ϴ� �κ� ã��
				{
					if (strTok[i] == "X")
					{
						tempNumber = i - 1; // ���ݿ� �ش��ϴ� ��ġ
					}
				}
				for (int i = 0; !strTok[i].empty(); i++)
				{
					if (menuName == strTok[i]) // �޴� �̸��� ���� �޴��� ã�� ��
					{
						cout << strTok[i] << endl << "�ش� �޴��� ���(1)�Ͻðڽ��ϱ� ? ����(2)�Ͻðڽ��ϱ� ? (0 = ����) ";
						int number;
						cin >> number;
						if (cin.fail())
						{
							cin.clear();
							number == NULL;
						}
						cin.ignore();
						if (number == 1) // ���
						{
							totalPrice = atoi(strTok[tempNumber].c_str()); // �� ���ݿ� �ش��ϴ� ��ū������ ������ ��ȯ
							totalPrice -= obj->takePrice(strTok[i]); // �� ���ݿ��� ����ϴ� �޴��� ���ݸ�ŭ ����
							strTok[tempNumber] = to_string(totalPrice); // ����� ���� ���ڿ��� ��ȯ �� ���� �ش��ϴ� ��ū�� ����
							strTok[i] = ""; // �ش� �޴� ��ġ�� ��ū�� �������� ����
							for (int j = 0; j <= tempNumber + 1; j++)
							{
								if (j == 0) {
									tempBuffer = strTok[j];
								}
								else if (tempNumber == 1) // �޴��� �Ѱ� �ۿ� ������ ���
								{
									tempBuffer == "";
									break;
								}
								else {
									if (j == 1 && strTok[0] == "") // ù ��° �޴��� ������� ���
									{
										tempBuffer = strTok[j];
									}
									else { // �� ���� ���
										if (strTok[j] != "") {
											tempBuffer += "\t";
											tempBuffer += strTok[j];
										}
									}
								}
							}
							tempNumber -= 1;
							break;
						}
						else if (number == 2) // ����
						{

							obj->checkMenu();
							cout << "������ ���ϴ� �޴� ��ȣ�� �Է��Ͻÿ� : "; // �����۵�
							int menuNumber;
							cin >> menuNumber;
							if (cin.fail())
							{
								cin.clear();
								cin.ignore();
								cout << "���ڰ� �ƴ� Ű�� �ԷµǾ����ϴ�.";
								Sleep(1000);
								break;
							}
							else
							{
								if (menuNumber > obj->getSize()) // ã�� ������ ��
								{
									cout << "�������� �ʴ� �޴��� �Է��ϼ̽��ϴ�." << endl;
									Sleep(1000);
									break;
								}
								cin.ignore();
								totalPrice = atoi(strTok[tempNumber].c_str()); // �޴��� �����Ǿ��� ������ ��Ż���ݵ� ����
								totalPrice -= obj->takePrice(strTok[i]); // ��Ż ���ݿ��� ���� �޴� ���ݸ�ŭ ����
								strTok[i] = obj->getMenuName(menuNumber - 1); // ���� �߰��� �޴� �̸� �߰�
								totalPrice += obj->takePrice(strTok[i]); // ���� �߰��� �޴� �̸��� ���� �޴����� �����ͼ� ��Ż ���ݿ� �߰�
								strTok[tempNumber] = to_string(totalPrice); // ��Ż������ �����̱� ������ ���ڿ��� ��ȯ �� ��ū�� ����
								for (int j = 0; j <= tempNumber + 1; j++)
								{
									if (j == 0) {
										tempBuffer = strTok[j];
									}
									else {
										tempBuffer += "\t";
										tempBuffer += strTok[j];
									}
								}
								break;
							}
						}
						else if (number == 0)
						{
							break;
						}
						else
						{
							cout << "�߸��� ���ڸ� �Է��ϼ̽��ϴ�." << endl;
							break;
						}
					}
				}
				buffer[index - 1] = tempBuffer;
				cout << buffer[index - 1] << endl;
				Sleep(5000);

			}
		}
		system("cls");
		ofstream writeMenus(fileName, ios::trunc);
		for (int i = 0; i < size; i++)
		{
			if (buffer[i] != "")
				writeMenus << buffer[i] << endl;
		}
		writeMenus.close();
	}
}


void plusInOrder() // ���� �ֹ� �߰�
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	samePlusOrder(fileName);
}
void plusOutOrder() // ��� �ֹ� �߰�
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	samePlusOrder(fileName);
}
void samePlusOrder(string fileName) // ���� ��޿��� �� �Ű� ������ ó���ϴ� �ֹ� ���� �߰�
{
	int size = 0;
	int number;
	string tempBuffer;
	string buffer[100];
	int tempNumber;
	int totalPrice;
	string *strTok;
	int count = 0;
	checkOrderMenu(fileName);
	ifstream Menus(fileName, ios::in);
	if (!Menus)
	{
		return;
	}
	while (!Menus.eof()) {
		getline(Menus, buffer[size]);
		if (buffer[size] != "") {
			size++;
		}
	}
	Menus.close();
	cout << "�޴��� �߰��� �ֹ� ��ȣ�� �Է��Ͻÿ� : ";
	int index;
	cin >> index;
	if (cin.fail())
	{
		system("cls");
		cin.clear();
		cin.ignore();
		cout << "���ڰ� �ƴ� Ű�� �ԷµǾ����ϴ�.";
		Sleep(1000);
	}
	else
	{
		cin.ignore();
		system("cls");
		if (index > size)
		{
			cout << "�����ϴ� �ֹ��� �ʰ��Ͽ����ϴ�." << endl;
			Sleep(1000);
		}
		else
		{
			strTok = StringSplit(buffer[index - 1], "\t");
			for (int i = 0; !strTok[i].empty(); i++)
			{
				if (strTok[i] != "X" && isStringDouble(strTok[i].c_str()) != 1)
				{
					if (i == 0)
					{
						tempBuffer = strTok[i] + "\t";
					}
					else {
						tempBuffer += strTok[i] + "\t";
					}
				}
				if (strTok[i] == "X")
				{
					tempNumber = i - 1; // �Ѱ��ݿ� �ش��ϴ� ���ڿ��� ��ġ
				}
			}
			totalPrice = atoi(strTok[tempNumber].c_str()); // ���ڿ��� ������ ��ȯ�ؼ� ����
			while (1) {
				system("cls");
				obj->checkMenu();
				cout << "�߰��� �޴� ��ȣ�� �Է��Ͻÿ� : ( 0 : ���� ) ";
				cin >> number;
				if (cin.fail())
				{
					cin.clear();
					number = -1;
				}
				cin.ignore();
				if (number == 0)
				{
					system("cls");
					break;
				}
				else if (number != -1)
				{
					tempBuffer += obj->getMenuName(number - 1) + "\t";
					totalPrice += obj->getMenuPrice(number - 1);
				}
			}
			tempBuffer += to_string(totalPrice); // ���ڿ��� ��ȯ�� ���ڿ��� �����̱�.
			buffer[index - 1] = "";
		}
		system("cls");
		ofstream writeMenus(fileName, ios::trunc);
		for (int i = 0; i < size; i++)
		{
			if (buffer[i] != "") { // ���� ���� ���Ͽ� ����
				writeMenus << buffer[i] << endl;
				cout << buffer[i] << endl;
			}
			else // ������ ���� ���� ��ġ�� ���Ͽ� ����
			{
				writeMenus << tempBuffer << endl;
				cout << tempBuffer << endl;
			}
		}
		Sleep(1000);
		writeMenus.close();//���� �ݱ�
	}
}


void cancelOrderMenu() // �ֹ� ��ȣ �ϳ��� ����ų� �ֹ� ��ü ��� ���� �޴�
{
	int menu;
	while (1) {
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : ���� �ֹ� ���";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : ��� �ֹ� ���"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : ���� �ֹ� ��ü ���"; gotoxy(48, 3); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 4); cout << "4 : ��� �ֹ� ��ü ���"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 4); cout << "|"; gotoxy(25, 5); cout << "5 : ����"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 6); cout << "=============================" << endl;
		gotoxy(25, 7); cout << "�Է� : ";
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
			cancelNumberInOrderMenu();
			break;
		case 2:
			cancelNumberOutOrderMenu();
			break;
		case 3:
			cancelNumberInOrderAllMenu();
			break;
		case 4:
			cancelNumberOutOrderAllMenu();
			break;
		case 5:
			return;
		default:
			break;
		}
	}


}
void cancelNumberInOrderMenu() // ���� �ֹ� �޴� ���
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	cancelNumberOrderMenu(fileName);
}
void cancelNumberOutOrderMenu() // ��� �ֹ� �޴� ���
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	sameOrderFix(fileName);
}
void cancelNumberOrderMenu(string fileName) // �����̸��� ���� ����, ��� �ֹ� �޴� ���
{
	system("cls");
	int size = 0;
	int number;
	string buffer[100];
	string name[100];

	ifstream Menus(fileName);
	while (!Menus.eof()) {
		getline(Menus, buffer[size]);
		name[size] = buffer[size];
		if (name[size] == "") {
			break;
		}
		cout << "�ֹ� " << size + 1 << "\t�޴� �̸� : " << buffer[size] << endl;
		size++;
	}
	Menus.close();
	cout << "����� �ֹ� ��ȣ�� �Է��Ͻÿ� : (0 : ����)";
	cin >> number;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "���� ���� �ٸ� Ű�� �ԷµǾ����ϴ�." << endl;
		Sleep(1000);
	}
	else
	{
		cin.ignore();
		if (number != 0) {
			buffer[number - 1] = ""; // ���� �����
		}

		ofstream writeMenus(fileName, ios::trunc);
		for (int i = 0; i <= size; i++)
		{
			if (buffer[i] != "")
			{
				writeMenus << buffer[i] << endl; // ������� ���Ͽ� ����ʰ� ������ ������ ���Ͽ� �ٽ� ����.
			}
		}
		writeMenus.close();
	}
}
void cancelNumberInOrderAllMenu() // �Ϸ���� ���� ���� �ֹ� ��ü ���
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	cancelNumberOrderAllMenu(fileName);
}
void cancelNumberOutOrderAllMenu() // �Ϸ���� ���� ��� �ֹ� ��ü ���
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";;
	cancelNumberOrderAllMenu(fileName);
}
void cancelNumberOrderAllMenu(string fileName) // ���� �̸��� ���� �Ϸ���� ���� ���� , ��� �ֹ� ��ü ���
{
	string buffer[100];
	int size = 0;
	ifstream Menus(fileName);//���� �б���� ����
	while (!Menus.eof())
	{
		getline(Menus, buffer[size]);
		if(buffer[size]!="")
		{
		size++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		string *strTok = StringSplit(buffer[i], "\t");
		for (int j = 0; !strTok[j].empty(); j++)
		{
			if (strTok[j] == "X")
			{
				buffer[i] = ""; // �Ϸ���� �ʴ� ���ڿ��� ���� ""�� ����
			}
		}
	}
	Menus.close(); // ���ϴݱ�
	ofstream writeMenus(fileName, ios::trunc); // ���� ������ ����
	for (int i = 0; i < size; i++)
	{
		if(buffer[i]!="") // �Ϸ�� �ֹ��� ���Ͽ� ����.
			writeMenus << buffer[i] << endl;

	}
	writeMenus.close();//���ϴݱ�
}
