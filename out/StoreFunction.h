#include "Myheader.h"

/* ���� ��Ȳ �Լ���*/
void storeStatus(); // ���� ���� Ȯ��
void checkSellMenu(); // �ֹ� �Ϸ� Ȯ��
void inOrderCheckSellMenu(); // ���� �Ϸ� �ֹ� Ȯ��
void outOrderCheckSellMenu(); // ��� �Ϸ� �ֹ� Ȯ��
void sameCheckSellMenu(string fileName); // ���� , ��� �ֹ����� �� �Ű������� ó���ϴ� �Ϸ� �ֹ� Ȯ��
void checkTotalPrice();//���� �����
void MonthSellPrice();//�ش� �� �����

void checkComplain(); // ���÷���
void writeComplain(); // ���÷��� ����� �޴�
void readComplain(); // ���÷��� �б�� �޴�

void inWriteComplain(); // ���� ���÷��� ���� 
void outWriteComplain(); // �ֹ� ���÷��� ����
void sameWriteComplain(string fileName); // ���÷��� ���� ó��

void inReadComplain(); // ���� ���÷��� �б�
void outReadComplain(); // �ֹ� ���÷��� �б�
void sameReadComplain(string fileName); // ���÷��� �б� ó��

void resetComplain(); // ���÷��� ���� �ʱ�ȭ �޴�

void resetInComplain(); //  ���� ���÷��� ���� �ʱ�ȭ
void resetOutComplain(); // �ֹ� ���÷��� ���� �ʱ�ȭ
void resetSameComplain(string fileName); // ���÷��� ���� �ʱ�ȭ ó��
