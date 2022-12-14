#include<iostream>
using namespace std;

void main ()
{
	setlocale(LC_ALL, "");
	int a = 2; // Dereferance operator - Оператор разыменования (pointer to 'a')
	int* pa = &a; // & - Оператор взятия адреса /Adress-of operator/
	cout << a << endl; // Значение переменной 'a'
	cout << &a << endl; // Взятие адреса переменной 'a' прямо при выводе
	cout << pa << endl; // Вывод адреса переменно 'a', хранящегося в указателе 'pa'
	cout << *pa << endl; // Разыменование указателя 'pa' и вывод на экран значение переменной 'a' (значение по адресу)

	int* pb; // Просто объявление указателя (без инициализации)
	int b = 3;
	pb = &b; // Инициализируем указатель после объявления
	// int - int
	// int* - указатель на int
	
}