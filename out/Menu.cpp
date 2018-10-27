#include "Myheader.h"
#include "Menu.h"
#include "Function.h"
#include "MakeFx.h"


Menu::Menu() : totalPrice(0) { // ������
	int check;
	while (1) {
		while (1) { // ������ �Էµ� �� ���� �ݺ�
			system("cls");
			cout << "�޴��� ���� ���� ���ΰ�? (1 : yes 2 : no ) >>>";
			cin >> check;
			if (cin.fail()) // �����ƴ� ���� �ԷµǾ��� �� ó��
			{
				cin.clear();
				cin.ignore();
			}
			else // ������ ���� ������ ���۸� ����� �ݺ����� �����Ѵ�.
			{
				cin.ignore();
				break;
			}
		}
		system("cls"); // ȭ�� â �����
		switch (check) { //check���� ���� switch��
		case 1:  // 1 �� ���
			int countMenu;
			while (1) { // �޴� �߰�
				system("cls");
				cout << "�߰��� �޴��� ������ ��ΰ� ? : ";
				cin >> countMenu;
				if (cin.fail()) // ���� ���� �ƴ� ��� 
				{
					cin.clear();
					cin.ignore();
				}
				else // �������� ��� �ݺ��� ����
				{
					cin.ignore();
					break;
				}
			}
			this->size = countMenu; // �Է� �� ��ŭ size�� �����Ѵ�.
			menuPrice = new int[size]; // �����Ҵ� menuPrice
			menuName = new string[size]; // �����Ҵ� menuName
			MakeMenu(); // �Լ��� �̵�
			return; // ����
			break;
		case 2: // 2�� ���
			findMenu();
			return;
		default:  // �� ���� ���
			system("cls");
		}
	}
}
Menu::~Menu() // �Ҹ��� 
{
	/* ���� �Ҵ� �� ������ ���� �Ҹ���*/
	delete[] menuPrice;
	delete[] menuName;
}
void Menu::MakeMenu() // �޴� ���� 
{
	string MenuN;
	string MenuPTemp;
	int MenuP;
	int success = 0;
	bool input = true;
	ofstream Menus("C:\\Menu.txt", ios::trunc); // ���� �޴��� ����� ������ ���� ���� ���� �ɼ��� trunc�� ����
	for (int i = 0; i < size; i++) {
		system("cls");
		success = 0; // ���� ���� �Է� �Ǿ����� ������ Ȯ���ϱ� ���� ����
		while (success == 0) {
			input = true;
			cout << "�޴� ����" << endl;
			cout << "�޴� �̸��� �Է��Ͻÿ� :";
			getline(cin, MenuN);
			cout << "�޴��� ������ �Է��Ͻÿ� : ";
			getline(cin, MenuPTemp);
			try { // ����ó��
				MenuP = stoi(MenuPTemp.c_str()); // ���ڿ��� ������ ��ȯ
				success = 1; // ������ success�� 1�� ����
				for (int j = 0; j < size; j++) // �̸� �ߺ� Ȯ���� ���� for��
				{
					if (MenuN == this->menuName[j]) // �ߺ��� ���� ��
					{
						input = false; // input �� false�� ����
					}
				}
				if (input == true) // �ߺ� ���� �� 
				{
					this->menuName[i] = MenuN; // ��ü�� ����
					this->menuPrice[i] = MenuP; // ��ü�� ����
					Menus << MenuN << "\t" << MenuP << endl; // ���Ͽ� ����
				}
				else // �ߺ��� ��
				{
					i--; // i 1 ����
					cout << "�ߺ��Ǵ� �޴� �̸��� �Է��ϼ̽��ϴ�." << endl;
					Sleep(1000);
				}
			}
			catch (invalid_argument&) // ���� �߻���
			{
				cout << "���ݿ� �ش��ϴ� �κп� ���� �� �ٸ� ���� �ԷµǾ����ϴ�" << endl; // ȭ�鿡 ���
				success = 0; // �ٽ� �ݺ���(while) ����
				Sleep(1000);

			}
		}
	}
	Menus.close(); // ���� �ݱ�
	return;

}

void Menu::findMenu() // �޴� Ȯ�� (Menu.txt�� ����Ǿ� �ִ� �޴� ������ ���� ���α׷� ��ü�� ���� ����)
{
	size = 0;
	int ye;
	string buffer[100];
	string name[100];
	int price[100];
	ifstream Menus("C:\\Menu.txt"); // �б� �������� ���� ����
	while (!Menus.eof()) { // ���� ������ �б�
		getline(Menus, buffer[size]); // �ٴ����� ���� ���� �޾ƿ���
		string *m_pStrTok = StringSplit(buffer[size], "\t"); // "\t"��ū ������ ���ڿ� ������
		name[size] = m_pStrTok[0]; // �޴� �̸��� �ش��ϴ� ���ڿ� ��ū
		if (name[size] != "") { // ���� �̸��� ""�� �ƴ� ��쿡�� ����
			price[size] = atoi(m_pStrTok[1].c_str()); // ���ݿ� �ش��ϴ� ���ڿ��� ������ ��ȯ
													  // m_pStrTok[1]�� string�̱� ������ atoi�� ���� ���ؼ��� charŸ���̿��� �ؼ� ��ȯ �ϱ� ���� ���
			cout << "�޴� �̸� : " << name[size] << "\t���� : " << price[size] << endl; // ȭ�鿡 ���� ��� 
			size++; // size ����
		}
	}
	//���� �Ҵ��� �ϱ����� size�� ���� �޴����ݰ� �̸��� ���ؼ� �����Ҵ�
	this->size = size;
	menuPrice = new int[size];
	menuName = new string[size];
	for (int i = 0; i < size; i++) { // ���Ͽ��� �о�� ���� ������� �� �ش��ϴ� ���ݰ� �̸��� ����
		menuName[i] = name[i];
		menuPrice[i] = price[i];
	}
	while (1) { // ���� ������ Ȯ���ߴ����� Ȯ���ϱ� ���� �ݺ���
		cout << "����� ������ Ȯ���ϼ̽��ϱ�? (1 : ����) >>>";
		cin >> ye;
		if (cin.fail())
		{
			cin.clear();
		}
		cin.ignore();
		system("cls");
		if (ye == 1)
			break;
	}
	Menus.close();
}
void Menu::setMenuPrice(int index, int menuPrice) // ���� ���� �Ű������� �޴��� ����(index)�� ������ �޴� ���� menuPrice�� �Ű������� �޴´�.
{
	this->menuPrice[index] = menuPrice;
	ofstream Menus("C:\\Menu.txt", ios::trunc); // ���� ���� ��������(�����) ����
	for (int i = 0; i < size; i++) { //���Ͽ� �ٲ� ������ ������ �ִ� ��ü�� ����.
		Menus << this->menuName[i] << "\t" << this->menuPrice[i] << endl;
	}
	Menus.close(); // ���� �ݱ�
}
void Menu::setMenuName(int index, string menuName) // �޴� ���� �޴��� ����(index)�� ������ �޴� ���� menuName�� �Ű������� �޴´�.
{
	this->menuName[index] = menuName;
	ofstream Menus("C:\\Menu.txt", ios::trunc);// ���� ���� ��������(�����) ����
	for (int i = 0; i < size; i++) {//���Ͽ� �ٲ� ������ ������ �ִ� ��ü�� ����.
		Menus << this->menuName[i] << "\t" << this->menuPrice[i] << endl;
	}
	Menus.close();
}
void Menu::addMenu() // �޴� �߰� ( �ߺ��� ���ݸ� ���� �ߺ� �ƴ� �� ���Ͽ� ���� �߰� )
{
	bool possible = false;
	string MenuN;
	string MenuPTemp;
	int MenuP;
	ifstream readMenus("C:\\Menu.txt");
	string buffer;
	string *strTok;
	int count;
	while (1) {
		system("cls");
		cout << "�߰��� �޴��� ������ �Է��Ͻÿ� : ";
		cin >> count;
		if (cin.fail()) // �Է°��� ������ �ƴ� ��
		{
			cin.clear();
			cin.ignore();
		}
		else // ������ �� �ݺ��� Ż��
			break;
	}
	cin.ignore();
	int i = 0;
	int j = 0;
	while (!readMenus.eof()) // ���� ������ �б�
	{
		getline(readMenus, buffer);
		if (buffer != "") {
			strTok = StringSplit(buffer, "\t");
			this->setAll(i++, strTok[0], atoi(strTok[1].c_str())); // ���� ������ ���� ���ڿ�����  �޴� �̸��� ���� �κа� �޴� ���ݿ� ���� �κп� ���� ������ setAll�� ���ؼ� menuName�� menuPrice ����
		}
	}
	readMenus.close(); // ���� �б� �ݱ�
	for (int z = 0; z < count; z++) { // ���� �߰��� ��ŭ�� ���� ��ŭ �ݺ�
		possible = false;
		system("cls");
		checkMenu(); // �޴� ���� ����
		cout << "�޴� ����" << endl;
		cout << "�޴� �̸��� �Է��Ͻÿ� :";
		getline(cin, MenuN); // �̸� �Է� �ޱ�
		cout << "�޴��� ������ �Է��Ͻÿ� : ";
		getline(cin, MenuPTemp); // ���� �Է� �ޱ�
		try {  // ����ó��
			MenuP = stoi(MenuPTemp.c_str()); // atoi�� ���� �۾��� �ϴ� stoi�Լ� ������ ����ó���� ��� �� �� �ִ� �Լ�
		}
		catch (invalid_argument&) // �Է°��� ���� ���� ���� �Էµ� ��� ���� ó���� ���ش�.
		{
			cout << "���ݿ� �ش��ϴ� �κп� ���� �� �ٸ� ���� �ԷµǾ����ϴ�";
			Sleep(1000);
			break;
		}
		for (j = 0; j < i; j++) // ���� �����ϴ� �޴��� �߿� �ߺ��Ǵ� �̸��� �����ϴ����� Ȯ���ϱ� ���� for��
		{
			if (this->getMenuName(j) == MenuN) // �Է¹��� �޴� �̸��� ���� �޴��� �ִ����� Ȯ���ϱ� ���� if��
			{
				possible = false;
				break;
			}
			else // �ߺ��� ���� ��
			{
				possible = true; //possible�� true ����
			}
		}
		if (possible == true) // �ߺ� ������ ���� ���⸦ �ϱ� ���� if��
		{
			ofstream addMenus("C:\\Menu.txt", ios::app);
			addMenus << MenuN << "\t" << MenuP << endl;
			addMenus.close();
			cout << "�޴� �߰� �Ϸ�." << endl;
			Sleep(2000);
		}
		else // �ߺ� �� ��ġ�ϴ� �޴� �̸��� ���� ���ݸ� ����
		{
			cout << "��ġ�ϴ� �̸��� �����մϴ�. ���ݸ� �����մϴ�." << endl;
			Sleep(2000);
			this->setMenuPrice(j, MenuP);
			ofstream fixMenus("C::\\Menu.txt", ios::trunc);
			for (int l = 0; l < size; l++)
			{
				fixMenus << this->getMenuName(l) << "\t" << this->getMenuPrice(l) << endl;
			}
			fixMenus.close();
		}
	}
	system("cls");
	findMenu(); // �ٲ� �޴� ������ �����ֱ� ���� findMenu()

}
int Menu::getTotalPrice() // �� �Ǹž� ��ȯ
{
	return this->totalPrice;
}
int Menu::getMenuPrice(int index) // �޴� ���� ��ȯ
{
	return this->menuPrice[index];
}
string Menu::getMenuName(int index) // �޴� �̸� ��ȯ
{
	return this->menuName[index];
}
int Menu::getSize() // size ��ȯ
{
	return size;
}



void Menu::checkMenu() { // �޴� ���� ���� �� ���� ���� ��ŭ �ٽ� Menu��ü size�� �����Ͽ� �����Ҵ��� ���ش�. findMenu()�� �ٸ����� while���� ���Ͽ� ������ Ȯ�� ������ ������ �ȹ������� �������� ����
	size = 0;
	string buffer[100];
	string name[100];
	int price[100];
	string *m_pStrTok;
	ifstream Menus("C:\\Menu.txt");
	while (!Menus.eof()) {
		getline(Menus, buffer[size]);
		m_pStrTok = StringSplit(buffer[size], "\t");
		name[size] = m_pStrTok[0];
		if (name[size] != "") {
			price[size] = atoi(m_pStrTok[1].c_str());
			// m_pStrTok[1]�� string�̱� ������ atoi�� ���� ���ؼ��� charŸ���̿��� �ؼ� ��ȯ �ϱ� ���� ���
			cout << size + 1 << "\t�޴� �̸� : " << name[size] << "\t���� : " << price[size] << endl;
			size++;
		}
	}
	this->size = size;
	this->menuPrice = new int[size];
	this->menuName = new string[size];
	for (int i = 0; i < size; i++) {
		this->menuName[i] = name[i];
		this->menuPrice[i] = price[i];
	}
	return;
}

void Menu::setAll(int index, string menuName, int menuPrice) // index�� �ش��ϴ� menuName , menuPrice setter �� ���� ����
{

	this->menuName[index] = menuName;
	this->menuPrice[index] = menuPrice;
	ofstream Menus("C:\\Menu.txt", ios::out, ios::trunc);
	for (int i = 0; i < size; i++) {
		if (this->menuName[i] != "" && this->menuPrice != NULL)
			Menus << this->menuName[i] << "\t" << this->menuPrice[i] << endl;
	}
	Menus.close();
}

void Menu::setTotalPrice(int totalPrice) // totalPrice setter
{
	this->totalPrice = totalPrice;
}

void Menu::plusTotalPrice(int price) // totalPrice pirce�� ��ŭ ����
{
	this->totalPrice += price;
}

int Menu::takePrice(string menuName) // �ش� menuName�� �ش��ϴ� menuPrice ���� ��ȯ
{
	int i;
	int price;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		if (menuName == this->menuName[i])
		{
			price = this->menuPrice[i];
			break;
		}
		count++;
	}
	if (count == size) {
		cout << "�ش� �޴� �̸��� ��ġ�ϴ� �޴��� �����ϴ�." << endl;
		Sleep(2000);
		system("cls");
		return NULL;
	}
	return price;
}

void Menu::fixMenu() // ���Ͽ��� ������ �о�� ��ü�� ���� ����. (update���)
{
	ofstream Menus("C:\\Menu.txt", ios::trunc);
	for (int i = 0; i < size; i++) {
		if (this->menuName[i] != "" && this->menuPrice != NULL)
			Menus << this->menuName[i] << "\t" << this->menuPrice[i] << endl;
	}
	Menus.close();
}
