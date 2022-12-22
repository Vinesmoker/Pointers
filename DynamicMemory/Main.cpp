#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t";
#define delimiter "________________________________________________________________";

void FillRand(int arr[], int n);
void Print(int* arr, int n);
int* PushBack(int* arr, int& n, int value);
int* PushFront(int* arr, int& n, int value);
int* Insert(int* arr, int& n, int value, int id);
int* PopFront(int* arr, int& n);
int* PopBack(int* arr, int& n);
int* Erase(int* arr, int& n, int id);

void FillRand(int** arr, const int rows, const int cols);
void Print(int** arr, const int rows, const int cols);
int** PushRowsBack(int** arr, int& rows, const int cols);
int** PushRowsFront(int** arr, int& rows, const int cols);
int** InsertRows(int** arr, int& rows, const int cols, int id);
int** PopRowsBack(int** arr, int& rows, const int cols);
int** PopRowsFront(int** arr, int& rows, const int cols);
int** Erase(int** arr, int& rows, const int cols, int id);

//#define dynamicMemory1
#define dynamicMemory2

void main()
{
	setlocale(LC_ALL, "");

#ifdef dynamicMemory1
	int n;
	cout << "Enter the number of elements: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n); Print(arr, n);

	int value; int id;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = PushBack(arr, n, value); Print(arr, n);
	cout << "������� ����������� ��������: "; cin >> value;
	arr = PushFront(arr, n, value); Print(arr, n);
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ������������ �������� � �������: "; cin >> id; id = id - 1;
	arr = Insert(arr, n, value, id); Print(arr, n);
	cout << "�������� ������� ��������: " << endl;
	arr = PopFront(arr, n); Print(arr, n);
	cout << "�������� ���������� ��������: " << endl;
	arr = PopBack(arr, n); Print(arr, n);
	cout << "������� ������ ���������� �������� � �������: "; cin >> id; id = id - 1;
	arr = Erase(arr, n, id); Print(arr, n);
	delete[] arr;
#endif // dynamicMemory1

	int rows; // ���������� �����
	int cols; // ���������� ��������� (���������� ��������� ������)
	int id;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	int** arr = new int* [rows]; // ������� ������ ����������;
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]; // ������� ������ ���������� �������;
	}
	FillRand(arr, rows, cols); Print(arr, rows, cols);

	cout << delimiter; cout << endl;

	cout << "���������� ������ � �����: " << endl;
	arr = PushRowsBack(arr, rows, cols); Print(arr, rows, cols);
	cout << "���������� ������ � ������: " << endl;
	arr = PushRowsFront(arr, rows, cols); Print(arr, rows, cols);
	cout << "������� ������ ������ ��� � ����������: "; cin >> id; id = id - 1;
	cout << "���������� ������ �� �������: " << endl;
	arr = InsertRows(arr, rows, cols, id); Print(arr, rows, cols);
	cout << "�������� ��������� ������: " << endl;
	arr = PopRowsBack(arr, rows, cols); Print(arr, rows, cols);
	cout << "�������� ������ ������: " << endl;
	arr = PopRowsFront(arr, rows, cols); Print(arr, rows, cols);
	cout << "������� ������ ������ ��� � ��������: "; cin >> id;
	cout << "��������� �������� ������ " << id << " :" << endl; id = id - 1;
	arr = Erase(arr, rows, cols, id); Print(arr, rows, cols);
	
	for (int i = 0; i < rows; i++) // 1.������� ������ ���������� �������
	{
		delete[] arr[i];  
	}
	delete[] arr; // 2. ������� ������ ����������
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
	//for (int i = 0; i < id; i++)buffer[i] = arr[i]; 
	//for (int i = id; i < n; i++)buffer[i + 1] = arr[i];
	for (int i = 0; i < n; i++)
	{
		//if (i < id)buffer[i] = arr[i]; else buffer[i + 1] = arr[i]; // 1 ������
		//(i < id ? buffer[i] : buffer[i + 1]) = arr[i]; // 2 ������
		buffer[i < id ? i : i + 1] = arr[i]; // 3 ������
	}
	buffer[id] = value;
	delete[] arr; arr = buffer; n++;
	return arr;
	/* ��� ���
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
	*/
}
int* PopFront(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
	/* ��� ���
	int* buffer = new int[n - 1];
	for (int i = n; i > 0; i--)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer; n--;
	return arr;
	*/
}
int* PopBack(int* arr, int& n)
{ 
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr; return buffer;
	/* ��� ���
	int* buffer = new int[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
	*/
}
int* Erase(int* arr, int& n, int id)
{ 
	if (id >= n)return arr;
	int* buffer = new int[n - 1];
	for (int i = 0; i < id; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = id; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

void FillRand(int** arr, const int rows, const int cols)
{
	
	for (int i = 0; i < rows; i++) // i �������� ������
	{
		for (int j = 0; j < cols; j++) // j �������� �������� ������;
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
int** PushRowsBack(int** arr, int& rows, const int cols) 
{
	int** buffer = new int*[rows + 1]; // ������� ��������� ������ ����������
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer[rows] = new int[cols] {};
	rows++;
	return arr;
}
int** PushRowsFront(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = new int [cols] {}; rows++;
	return buffer;
}
int** InsertRows(int** arr, int& rows, const int cols, int id)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < id; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = id; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[id] = new int [cols] {}; rows++;
	return buffer;
}
int** PopRowsBack(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)buffer[i] = arr[i];
	buffer[rows] = new int[cols]{}; rows--;
	delete[] arr;
	return buffer;
}
int** PopRowsFront(int** arr, int& rows, const int cols) 
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	buffer[rows] = new int[cols] {}; rows--;
	return buffer;
}
int** Erase(int** arr, int& rows, const int cols, int id)
{
	int** buffer = new int* [rows - 1];
	if (id >= rows)return arr;
	for (int i = 0; i < id; i++)buffer[i] = arr[i];
	for (int i = id; i < rows - 1; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	buffer[rows] = new int [cols] {}; rows--;
	return buffer;
}