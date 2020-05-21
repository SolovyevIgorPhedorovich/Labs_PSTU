#include <C:\Users\Acer\Desktop\Учеба\Контрольные работы\Информатика 2 семестр\Лабораторная работа №11\Zadacha 2\Time.h>
#include "Vector.h"
#include <iostream>

using namespace std;

void main()
{
	Vector<Time>deq(5);
	deq.Print();
	Time el = deq.max();
	cout << "Max = " << el << endl;
	deq.add_deque(el);
	deq.Print();
	int x;
	cout << "Key?"; cin >> x;
	deq.del_deque(x);
	deq.Print();
	cout << "Add srednee:" << endl;
	int sred = deq.srednee();
	deq.add_srednee(sred);
	deq.Print();
}