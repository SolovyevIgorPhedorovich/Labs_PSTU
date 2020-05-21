#include <C:\\Users\Acer\Desktop\Учеба\Контрольные работы\Информатика 2 семестр\Лабораторная работа №11\Zadacha 2\Time.h>
#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

typedef queue<Time>Qu;
typedef deque<Time>TDeque;
Time s;
int x;

TDeque copy_queue_to_deque(Qu q)
{
	TDeque d;
	while (!q.empty())
	{
		d.push_back(q.front());
		q.pop();
	}
	return d;
}

Qu copy_deque_to_queue(TDeque d)
{
	Qu q;
	for (int i = 0; i < d.size(); i++)
		q.push(d[i]);
	return q;
}

void add_element_to_queue(Qu &q, Time el)
{
	q.push(el);
}

Qu make_queue(int n) {
	Qu q;
	Time t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		q.push(t);
	}
	return q;
}

void print_queue(Qu q)
{
	while (!q.empty())
	{
		cout << q.front() << " " << endl;
		q.pop();
	}
}

int srednee(Qu q) {
	TDeque v = copy_queue_to_deque(q);
	Time x = v[0];
	for (int i = 1; i < v.size(); i++) {
		x = x + v[i];
	}
	int n = v.size();
	return x / n;
}

void add(Time& s)
{
	s = s + x;
}

void main() {
	Qu q;
	int n;
	cout << "N?"; cin >> n;
	q = make_queue(n);
	print_queue(q);
	TDeque d = copy_queue_to_deque(q);
	TDeque::iterator i;
	i = max_element(d.begin(),d.end());
	Time m = *(i);
	cout << "add" << endl;
	add_element_to_queue(q,m);
	print_queue(q);
	Time t;
	cout << "Time?"; cin >> t;
	d = copy_queue_to_deque(q);
	cout << "Del" << endl;
	remove(d.begin(), d.end(), t);
	q = copy_deque_to_queue(d);
	print_queue(q);
	cout << "Add element" << endl;
	x = srednee(q);
	for_each(d.begin(), d.end(),add);
	q = copy_deque_to_queue(d);
	print_queue(q);
}