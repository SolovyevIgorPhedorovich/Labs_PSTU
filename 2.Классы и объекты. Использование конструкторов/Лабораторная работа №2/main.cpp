#include "Chislo.h"
#include <iostream>
#include <string>

using namespace std;

Chislo make_chislo()
{
	setlocale(LC_ALL, "Ru");
	float s;
	int i;
	string d;
	cout << "Введите матиссу: "; cin >>s;
	cout << "Введите порядок: "; cin >> i;
	cout << "Введите строковое представление: "; cin >> d;
	Chislo t(s, i, d);
	return t;
}
void print_chislo(Chislo t) {
	t.show();
}

void main() {
	Chislo t1;
	t1.show();
	Chislo t2(0.5,6,"Fdgdfbd");
	t2.show();
	Chislo t3=t2;
	t3.set_mantissa(0.3);
	t3.set_poradok(4);
	t3.set_str_predstaflenie("dssfggdfh");
	print_chislo(t3);
	t1 = make_chislo();
	t1.show();
}