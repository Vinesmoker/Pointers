#include<iostream>
using namespace std;

//#define POINTERS

void main ()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS
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
#endif // POINTERS

	const int n = 5;
	int arr[n]{3, 5, 8, 13, 21};
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}
	cout << endl;
}