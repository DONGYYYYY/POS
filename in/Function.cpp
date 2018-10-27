
/*	Function.cpp	*/

#include "Myheader.h"
#include "Function.h"



void mainPrint()
{
	int menu;
	while (1)
	{
		string fileName1 = "C:\\";
		fileName1 += currentDate();
		fileName1 += "-inOrder.txt";
		string fileName2 = "C:\\";
		fileName2 += currentDate();
		fileName2 += "-outOrder.txt";
		menu = sameOrder(fileName1, fileName2);
		if (menu == 0)
		{
			break;
		}
	}
	cout << "���α׷� ����";

}

void gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int sameOrder(string fileName1, string fileName2) // �ֹ濡 ���õ� �۾��� �ϴ� �Լ�.
{
	int size1 = 0;
	int size2 = 0;
	int index;
	int number;
	string buffer1[100];
	string buffer2[100];
	string *tokName;
	char want[] = "�䱸 ���� : ";
	int i = 0;
	string temp;
	bool complete = false;
	while (!_kbhit()) // Ű���尡 �Է��� �� �� ���� �ݺ��� �Ѵ�.
	{
		system("cls");
		size1 = 0;
		ifstream Menus(fileName1); // ���� �ֹ� ��Ȳ

		if (Menus)  //������ ���� ������ ��.
		{
			while (!Menus.eof()) { // ���� ������ �б�
				getline(Menus, buffer1[size1]); // �ٴ����� buffer1�� ����.
				if (buffer1[size1] != "") { // ���� ���ڿ��� ""�� �ƴ� ���
					cout << "���� �ֹ� " << size1 + 1 << " : ";
					tokName = StringSplit(buffer1[size1], "\t");
					for (int i = 0; !tokName[i].empty(); i++) {
						if (strncmp(tokName[i].c_str(), want, 7) != 0) {
							cout << tokName[i] << "\t";
						}
						else
						{
							cout << endl << tokName[i];
						}
					}
					size1++; // �迭 ��ġ�� ����
					cout << endl << "===============================================================================" << endl;
				}
			}

			Menus.close(); // ���� �ݱ�
		}
		if (size1 == 0) // size1�� ũ�Ⱑ 0�� ��� (������ �����޴µ� ������ ���� ��� Ȥ�� ������ �������� ���� ���)
		{
			cout << "���� �ֹ� �޴��� �����ϴ�." << endl;
		}
		size2 = 0;
		ifstream outMenus(fileName2); // ��� �ֹ� ��Ȳ
		if (outMenus) // ������ ���� ������ ��
		{
			while (!outMenus.eof()) {//���� ������ �б�
				getline(outMenus, buffer2[size2]); // �ٴ����� buffer2�� ����
				if (buffer2[size2] != "") { // ���� ���ڿ��� ""�� �ƴ� ���
					cout << "��� �ֹ� " << size2 + 1 << " : ";
					tokName = StringSplit(buffer2[size2], "\t");
					for (int i = 0; !tokName[i].empty(); i++) {
						if (strncmp(tokName[i].c_str(), want, 7) != 0) {
							cout << tokName[i] << "\t";
						}
						else
						{
							cout << endl << tokName[i];
						}
					}
					size2++; // �迭 ��ġ�� ����
					cout << endl << "===============================================================================" << endl;
				}
			}
			outMenus.close(); // ���� �ݱ�
		}
		if (size2 == 0) //size1�� ũ�Ⱑ 0�� ���(������ �����޴µ� ������ ���� ��� Ȥ�� ������ �������� ���� ���)
		{
			cout << "��� �ֹ� �޴��� �����ϴ�." << endl;
		}
		for (int i = 3; i >= 1; i--) // 3�ʰ� ���
		{
			cout << i << endl;
			Sleep(1000); // 
		}
	}
	cout << "�ϼ��� ��ġ�� �����Ͻÿ� : ( 1 : ���� , 2 : ���  3 : ���÷��� Ȯ�� 0 : ����) >>>";
	cin >> index;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		return 1;
	}
	cin.ignore();
	if (index == 1) // ���� �ֹ� ó��
	{
		cout << "���� �ֹ� �Ϸ� ����" << endl;
		cout << "�ϼ��� �޴��� �����Ͻÿ� : >>";
		cin >> number;
		if (cin.fail()) // ���� ó��
		{
			cin.clear();
			number = NULL;
		}
		cin.ignore();
		if (number > size1) // �޴������� ū ���� �Է��� ���
		{
			cout << "�ֹ��� �޴������� ū ���� �Է��ϼ̽��ϴ�." << endl;
			Sleep(1000);
		}
		else // �������� ���
		{
			system("cls");
			tokName = StringSplit(buffer1[number - 1], "\t");
			for (i = 0; !tokName[i].empty(); i++)
			{
				if (tokName[i] == "X") 
				{
					tokName[i] = "O";
					complete = true;
					buffer1[number - 1] = "";
					for (int j = 0; j <= i; j++)
					{
						if (j == 0)
						{
							temp = tokName[j];
						}
						else
						{
							temp += "\t";
							temp += tokName[j];
						}
					}
					break;
				}
			}
			if (complete == false) // �Ϸ� ����
			{
				system("cls");
				cout << "�̹� �ֹ� �Ϸ�� �޴� �Դϴ�." << endl;
			}
			else // �Ϸ� ������
			{
				ofstream writeMenus(fileName1, ios::trunc); // ���� �����
				for (int j = 0; j <= size1; j++)
				{
					if (buffer1[j] != "")
					{
						writeMenus << buffer1[j] << endl; // ���� ���� ����.
					}
				}
				writeMenus << temp << endl; // �ٲ� ������ ���� �������� ����.
				writeMenus.close(); // ���� �ݱ�
			}
		}
	}
	else if (index == 2) // ��� �ֹ� �Ϸ� index�� 1�� ���� ����
	{
		cout << "��� �ֹ� �Ϸ� ����" << endl;
		cout << "�ϼ��� �޴��� �����Ͻÿ� : >>";
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			number = NULL;
		}
		cin.ignore();
		if (number > size2)
		{
			cout << "�ֹ��� �޴������� ū ���� �Է��ϼ̽��ϴ�." << endl;
			Sleep(1000);
		}
		else {
			system("cls");
			tokName = StringSplit(buffer2[number - 1], "\t");
			for (i = 0; !tokName[i].empty(); i++)
			{
				if (tokName[i] == "X")
				{
					tokName[i] = "O";
					complete = true;
					buffer2[number - 1] = "";
					for (int j = 0; j <= i; j++)
					{
						if (j == 0)
						{
							temp = tokName[j];
						}
						else
						{
							temp += "\t";
							temp += tokName[j];
						}
					}
					break;
				}
			}
			if (complete == false)
			{
				system("cls");
				cout << "�̹� �ֹ� �Ϸ�� �޴� �Դϴ�." << endl;
			}
			else
			{
				ofstream writeMenus1(fileName2, ios::trunc);
				for (int j = 0; j <= size2; j++)
				{
					if (buffer2[j] != "")
					{
						writeMenus1 << buffer2[j] << endl;
					}
				}
				writeMenus1 << temp << endl;
				writeMenus1.close();
			}
		}
	}
	else if (index == 3)
	{
		checkComplain();//���÷���
	}
	else if (index == 0)
	{
		return 0;
	}
	return 1;
}
string* StringSplit(string strOrigin, string strTok) // ���ڿ� ��ū���� ������ �Լ�
{
	int cutAt;
	int index = 0;
	string *strResult = new string[1000];

	while ((cutAt = strOrigin.find_first_of(strTok)) != strOrigin.npos)
	{
		if (cutAt > 0)
		{
			strResult[index++] = strOrigin.substr(0, cutAt);
		}
		strOrigin = strOrigin.substr(cutAt + 1);
	}

	if (strOrigin.length() > 0)
	{
		strResult[index++] = strOrigin.substr(0, cutAt);
	}
	return strResult;
}




string currentDate()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

	return buf;
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
		cout << buffer << endl; // ���� ���� ���
		cout << endl << "===============================================================================" << endl;
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