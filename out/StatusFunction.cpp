#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
#include "MakeFx.h"
#include "StatusFunction.h"


void orderStatus() { // �ֹ� Ȯ�� 
	int menu;
	while (1)
	{
		system("cls");
		gotoxy(20, 0); cout << "=============================" << endl;
		gotoxy(20, 1); cout << "|"; gotoxy(25, 1); cout << "1 : ���� �ֹ� Ȯ��";		gotoxy(48, 1); cout << "|" << endl;
		gotoxy(20, 2); cout << "|"; gotoxy(25, 2); cout << "2 : ��� �ֹ� Ȯ��"; gotoxy(48, 2); cout << "|" << endl;
		gotoxy(20, 3); cout << "|"; gotoxy(25, 3); cout << "3 : ����"; gotoxy(48, 4); cout << "|" << endl;
		gotoxy(20, 4); cout << "=============================" << endl;
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
			inOrderStatus(); // ���� �ֹ� Ȯ��
			break;
		case 2:
			outOrderStatus(); // ��� �ֹ� Ȯ��
			break;
		case 3:
			return; // ����
		default:
			break;
		}

	}
}

void inOrderStatus() // ���� �ֹ� Ȯ��
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-inOrder.txt";
	sameOrderStatus(fileName);
}

void outOrderStatus() // ��� �ֹ� Ȯ��
{
	string fileName = "C:\\";
	fileName += currentDate();
	fileName += "-outOrder.txt";
	sameOrderStatus(fileName);
}

void sameOrderStatus(string fileName) // ���Ͽ� ���� ���� Ȥ�� ��� �ֹ� Ȯ��
{
	system("cls");
	int size = 0;
	int ye;
	string buffer[100];
	string *tokName; // ��ū������ �Լ��� ����ϱ� ���� ������ ����
	char want[] = "�䱸 ���� : ";
	ifstream Menus(fileName);
	if (!Menus)
	{
		cout << "���� �ֹ��� �޴��� �����ϴ�.";
		Sleep(2000);
		return;
	}
	while (!Menus.eof()) {
		getline(Menus, buffer[size]);
		if (buffer[size] != "") {
			cout << "�ֹ� " << size + 1 << " : ";
			tokName = StringSplit(buffer[size], "\t");
			for (int i = 0; !tokName[i].empty(); i++) { // tokName[]���� ��� ������ ���� �ݺ�
				if (strncmp(tokName[i].c_str(), want, 7) != 0) { // tokName[i]���� 7�ڸ��� ������ �� want�� ���� �Ǿ� �ִ� ���� ��ġ�ϴ� ��� 0�� ��ȯ
					cout << tokName[i] << "\t"; // �ƴ� ��쿡�� tokName[i]���� ȭ�鿡 ���
				}
				else // 0�� ��� (���� ���)
				{
					cout << endl << tokName[i]; // �� �ٲ��� ���� �� ȭ�鿡 ���
				}
			}
			size++; // size�� ++
			cout << endl << "===============================================================================" << endl;
		}
	}
	while (1) {
		cout << "����� ������ Ȯ���ϼ̽��ϱ�? (1 : ����) >>>";
		cin >> ye;
		if (cin.fail()) // ���ڰ� �ƴ� ���� �Էµ� ���
		{
			cin.clear(); // cin�� ����ش�.
			ye = NULL; //ye���� NULL�� �ʱ�ȭ
		}
		cin.ignore(); // ���۸� ���ش�.
		if (ye == 1) { // �Է� ���� 1�� ���
			system("cls");
			break; //�ݺ��� ����
		}
	}
	Menus.close();//���� �ݱ�
}

void checkOrderMenu(string fileName) // �䱸 ���� ���� Ȯ�� x
{
	system("cls");
	int size = 0;
	string buffer[100];
	string *tokName;
	ifstream Menus(fileName); // �б� ���� ���� ����
	if (!Menus) // ���� ���� ���н�
	{
		cout << "���� �ֹ��� �޴��� �����ϴ�.";
		Sleep(2000); // 2�ʰ� ����
		return;
	}
	while (!Menus.eof()) { // ���� ������ Ȯ�� 
		getline(Menus, buffer[size]); // ������ �о buffer[size]�� ����
		if (buffer[size] != "") // buffer[size]���� ""�� �ƴ� ���
		{
			cout << "�ֹ� ��ȣ " << size + 1 << " : ";
			tokName = StringSplit(buffer[size], "\t"); // \t ������ ���ڿ��� ������ tokName�� ����
			for (int i = 0; !tokName[i].empty(); i++) { // tokName[]�� ��������� ���� for�� �ݺ�
				if (tokName[i] == "O" || tokName[i] == "X") { // �ش� ���ڿ��� O �̰ų� X�̸�
					cout << tokName[i]; // ���ڿ� ��� ��
					break; // �ݺ��� ����
				}
				else { // �� ���� ���
					cout << tokName[i] << "\t"; // ���ڿ� ���
				}
			}
			size++; // size�� ++
			cout << endl << "===============================================================================" << endl;
		}
	}
}
