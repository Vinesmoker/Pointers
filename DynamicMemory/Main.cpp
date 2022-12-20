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
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = PushBack(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = PushFront(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс добавляемого значения в массиве: "; cin >> id;
	arr = Insert(arr, n, value, id);
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//Обращение через арифметику указателей и оператор разыменования:
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; i++)
	{
		//Через оператор индексирования
		//[] - оператор индксирования (subscrip operator)
		cout << arr[i] << tab;
	}
	cout << endl;
}
int* PushBack(int* arr, int& n, int value)
{
	//1.Создаем новый массив нужного размера.
	int* buffer = new int[n + 1];
	//2.Копируем все содержимое массива в буфферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3.Удаляем исходный массив.
	delete[] arr;
	//4.Подменяем адрес в указателе адресом нового массива.
	arr = buffer;
	//5. Только после этого в конец массива 'arr' можно добавить значение.
	arr[n] = value;
	//6.Добавляем значение в конец массива
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