#include "C:\\Users\Acer\Desktop\Учеба\Контрольные работы\Информатика 2 семестр\Лабораторная работа №11\Zadacha 2\Time.h"
#include <iostream>
#include <queue>
#include <deque>

using namespace std;

typedef queue<Time>Qu;
typedef deque<Time> Deq;

Qu make_stack(int n)
{
	Qu q;
	Time t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		q.push(t);
	}
	return q;
}



Deq copy_stack_to_deque(Qu q)
{
	Deq d;
	while (!q.empty()) {
		d.push_back(q.front());
		q.pop();
	}
	return d;
}

Qu copy_deque_to_stack(Deq d) {
	Qu s;
	for (int i = 0; i < d.size(); i++)
		s.push(d[i]);
	return s;
}

void print_stack(Qu s) {
	Deq d = copy_stack_to_deque(s);
	while (!s.empty())
	{
		cout << s.front() << endl;
		s.pop();
	}
	s = copy_deque_to_stack(d);
}



Time max(Qu s) {
	Time m = s.front();
	Deq d = copy_stack_to_deque(s);
	while (!s.empty())
	{
		if (s.front() > m)
		{
			m = s.front();
		}
		s.pop();
	}
	s = copy_deque_to_stack(d);
	return m;
}

void Add_to_stack(Qu& s, Time el) {
	Deq d = copy_stack_to_deque(s);
	d.push_back(el);
	s = copy_deque_to_stack(d);
}


void del_element_from_stack(Qu& s, int pos) {
	Deq d;
	Time t;
	int i = 0;
	while (!s.empty())
	{
		t = s.front();
		if (i != pos)d.push_back(t);
		s.pop();
		i++;
	}
	s = copy_deque_to_stack(d);
}

int srednee(Qu s) {
	Deq d = copy_stack_to_deque(s);
	int n = 1;
	Time sum = s.front();
	s.pop();
	while (!s.empty())
	{
		sum = sum + s.front();
		s.pop();
		n++;
	}
	s = copy_deque_to_stack(d);
	return sum / n;
}

void add_element_from_stack(Qu& s) {
	int sred = srednee(s);
	Deq d;
	Time t;
	Time x;
	while (!s.empty())
	{
		t = s.front();
		x = t + sred;
		d.push_back(x);
		s.pop();
	}
	s = copy_deque_to_stack(d);
}
	
void main() {
	Time t;
	Qu s;
	int n;
	cout << "N?";
	cin >> n;
	s = make_stack(n);
	print_stack(s);
	t = max(s);
	Add_to_stack(s, t);
	cout << "Add max:" << endl;
	print_stack(s);
	int x;
	cout << "Key?"; cin >> x;
	cout << "Del element:" << x << endl;
	del_element_from_stack(s, x);
	print_stack(s);
	cout << "Add srednee znacenie:" << endl;
	add_element_from_stack(s);
	print_stack(s);
}