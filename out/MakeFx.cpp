#include "Myheader.h"
#include "Menu.h"
#include "Function.h"

string* StringSplit(string strOrigin, string strTok) // ���ڿ� ��ū���� ������ �Լ�
{
	int cutAt;
	int index = 0;
	string *strResult = new string[1000]; // �����Ҵ� (�ִ�ġ�� �ϴ� 100���� ����) 100�� �̻��� �޴��� ��Ű�� ��찡 ������ ũ�⸦ �� ũ�� ����

	while ((cutAt = strOrigin.find_first_of(strTok)) != strOrigin.npos) // cutAt�� ��ū���� ������ ��ŭ�� ���ڿ��� ���̸� �����Ѵ�. ( ���� ���ڿ��� ������ �ݺ� (���������� "\0"�� ������) 
	{
		if (cutAt > 0)
		{
			strResult[index++] = strOrigin.substr(0, cutAt); //strResult[index++]���� strOrigin�� ��ū������ �и��� ���ڿ��� �����Ѵ�.
		}
		strOrigin = strOrigin.substr(cutAt + 1); // strOrigin�� ���� ���ڿ��� ����Ų��. ( ��ū���� �и��� )
	}

	if (strOrigin.length() > 0)
	{
		strResult[index++] = strOrigin.substr(0, cutAt);
	}
	return strResult; // ��ū���� ������ ���ڿ��� ��ȯ
}

int isStringDouble(const char *s) { // ���ڿ��� ���ڷθ� �̷���� �ִ��� Ȯ���ϴ� �Լ�
	size_t size = strlen(s);
	if (size == 0) return 0; // 0����Ʈ ���ڿ��� ���ڰ� �ƴ�

	for (int i = 0; i < (int)size; i++) {
		if (s[i] == '.' || s[i] == '-' || s[i] == '+') continue;
		if (s[i] < '0' || s[i] > '9') return 0; // ���ĺ� ���� ������ ���� �ƴ�
	}

	return 1; // �׹��� ���� ����
}


string currentDate() // ���� ��-��-���� ���ڿ� ���·� ��ȯ�ϴ� �Լ� (�ֹ� ������ ��¥ ���� ������ ���ؼ� ����ϴ� �Լ�)
{
	time_t now = time(0); // ���� �ð��� ���� ������ ������ now ����
	struct tm tstruct; // ����ü ���� 
	char buf[80];
	tstruct = *localtime(&now); // ���� �ð��� ���� ������ tstruct�� ����.
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct); // %Y = �⵵ %m = �� %d = �� �� ���� ������ ������.

	return buf; // ��-��-���� ������ ���� ���ڿ��� ��ȯ
}


string currentMonth() // ��-�� ���ڿ� ���� ��ȯ�ϴ� �Լ�
{
	time_t now = time(0); // ���� �ð��� ���� ������ ������ now ����
	struct tm tstruct; // ����ü ���� 
	char buf[80];
	tstruct = *localtime(&now); // ���� �ð��� ���� ������ tstruct�� ����.
	strftime(buf, sizeof(buf), "%Y-%m", &tstruct);// %Y = �⵵ %m = �� �� ���� ������ ������.

	return buf; // ��-���� ������ ���� ���ڿ��� ��ȯ
}

void gotoxy(int x, int y) { // �ܼ� ������ ��ġ�� �����ϱ� ���� �Լ�
	COORD pos;
	pos.X = x; // x ��
	pos.Y = y; // y ��
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); // �Ű������� ���� x , y�� ��ŭ �̵� ( 0 , 0 ) ���ؿ���
}
