#include <C:\\Users\Acer\Desktop\Учеба\Контрольные работы\Информатика 2 семестр\Лабораторная работа №11\Zadacha 2\Time.h>
#include <iostream>
#include "Vector.h"
using namespace std;

void main() {
	int n;
	cout << "N?"; cin >> n;
	Vector<Time>m(n);
	m.print();
	m.add(n);
	m.print();
	m.del();
	m.print();
	int x = m.srednee();
	m.add_element(x);
	m.print();
}