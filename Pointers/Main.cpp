#include<iostream>
using namespace std;

void main ()
{
	setlocale(LC_ALL, "");
	int a = 2; // Dereferance operator - �������� ������������� (pointer to 'a')
	int* pa = &a; // & - �������� ������ ������ /Adress-of operator/
	cout << a << endl; // �������� ���������� 'a'
	cout << &a << endl; // ������ ������ ���������� 'a' ����� ��� ������
	cout << pa << endl; // ����� ������ ��������� 'a', ����������� � ��������� 'pa'
	cout << *pa << endl; // ������������� ��������� 'pa' � ����� �� ����� �������� ���������� 'a' (�������� �� ������)

	int* pb; // ������ ���������� ��������� (��� �������������)
	int b = 3;
	pb = &b; // �������������� ��������� ����� ����������
	// int - int
	// int* - ��������� �� int
	
}