#include <iostream>
#include <C:\\Users\Acer\Desktop\Учеба\Контрольные работы\Информатика 2 семестр\Лабораторная работа №11\Zadacha 2\Time.h>
#include <deque>
#include <algorithm>

using namespace std;

typedef deque<Time> TDeque;
Time s;
int x;

TDeque make_deque(int n) {
	Time a;
	TDeque d;
	for (int i = 0; i < n; i++) {
		cin >> a;
		d.push_back(a);
	}
	return d;
}


void print_deque(TDeque d) {
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << endl;
	cout << endl;
}

int srednee(TDeque d)
{
	Time s = d[0];
	for (int i = 1; i < d.size(); i++)
		s = s + d[i];
	int n = d.size();
	return s / n;
}

void add(Time& t) {
	t = t + x;
}



void main()
{
	int n;
	cout << "N?";
	cin >> n;
	TDeque d;
	d = make_deque(n);
	print_deque(d);
	TDeque::iterator i;
	i = max_element(d.begin(), d.end());
	cout << "max=" << *(i) << endl;
	Time m = *(i);
	d.push_back(m);
	print_deque(d);
	cout << "Del" << endl;
	cin >> s;
	remove(d.begin(), d.end(), s);
	print_deque(d);
	cout << "Add" << endl;	
	x = srednee(d);
	for_each(d.begin(), d.end(), add);
	print_deque(d);
}