#include "Myheader.h"

class Menu {
private:
	int totalPrice; // �� �Ǹž�
	int *menuPrice; // �޴� ����(�����Ҵ�)
	int size; // �޴� ũ��(���� �Ҵ翡 ���� ũ��)
	string *menuName; // �޴� �̸� (�����Ҵ�)
public:
	Menu(); // ������
	~Menu(); // �Ҹ���
			 //Menu(const Menu& copy);//��������� (����)
	void MakeMenu(); // �޴�����
	void setMenuPrice(int index, int menuPrice); // �޴� ����
	void setMenuName(int index, string menuName); // ���� ����
	void addMenu(); // �޴� �߰�
	int getTotalPrice(); // �� �Ǹž� ��ȯ
	int getMenuPrice(int index); // �޴� ���� ��ȯ
	string getMenuName(int index); // �޴� �̸� ��ȯ
	void findMenu(); //�޴� ���� Ȯ�� �� ���
	int getSize(); // Size getter
	void checkMenu(); // �޴� ���� ���� Ȯ�� (��� x) �޴�Ȯ���� ��� �� �ٸ� �۾� ó���� ���
	void setAll(int index, string menuName, int menuPrice); // �޴� ���ݰ� �޴� �̸��� ���ÿ� set
	void setTotalPrice(int totalPrice); // ���Ǹž� setter
	void plusTotalPrice(int price); // ���Ǹž� �Ű����� ����ŭ ����
	int takePrice(string menuName); // �Ű�����(�޴� �̸�)�� ��ġ�ϴ� �޴� ã�� �� �� �޴��� ���� ��ȯ
	void fixMenu();
};
