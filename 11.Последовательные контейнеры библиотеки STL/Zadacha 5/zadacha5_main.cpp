#include <C:\\Users\Acer\Desktop\�����\����������� ������\����������� 2 �������\������������ ������ �11\Zadacha 2\Time.h>
#include <iostream>
#include<queue>
#include <deque>
#include "Vector.h"
using namespace std;

void main() {
	Vector<Time>d(3);
	d.Print();
	Time el = d.max();
	cout << "Add max" << endl;
	d.add_to_stack(el);
	d.Print();
	int t;
	cout << "Key?"; cin >> t;
	cout << "Del element:" << endl;
	d.del_element_ftom_stack(t);
	d.Print();
	cout << "Add srednee znachenie" << endl;
	d.add_element_from_stack();
	d.Print();
}