#include<iostream>
using namespace std;

#define tab "\t";

void FillRand(int arr[], int n);
void Print(int* arr, int n);
int* PushBack(int* arr, int& n, int value);
int* PushFront(int* arr, int& n, int value);
int* Insert(int* arr, int& n, int value, int id);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Enter the number of elements: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n); Print(arr, n);

	int value; int id;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = PushBack(arr, n, value);
	Print(arr, n);
	cout << "������� ����������� ��������: "; cin >> value;
	arr = PushFront(arr, n, value);
	Print(arr, n);
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ������������ �������� � �������: "; cin >> id;
	arr = Insert(arr, n, value, id);
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//��������� ����� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//����� �������� ��������������
		//[] - �������� ������������� (subscrip operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* PushBack(int* arr, int& n, int value)
{
	//1.������� ����� ������ ������� �������.
	int* buffer = new int[n + 1];
	//2.�������� ��� ���������� ������� � ���������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3.������� �������� ������.
	delete[] arr;
	//4.��������� ����� � ��������� ������� ������ �������.
	arr = buffer;
	//5. ������ ����� ����� � ����� ������� 'arr' ����� �������� ��������.
	arr[n] = value;
	//6.��������� �������� � ����� �������
	n++;
	return arr;
}
int* PushFront(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value; n++;
	return arr;
}
int* Insert(int* arr, int& n, int value, int id)
{
	int* buffer = new int[n + 1];
	buffer[id] = value;
	for (int i = 0; i < id; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = id; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[id] = value; n++;
	return arr;
}