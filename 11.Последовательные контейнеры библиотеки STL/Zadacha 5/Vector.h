#pragma once
#include <iostream>
#include <queue>
#include <deque>
using namespace std;

template <class T>
class Vector
{
	queue<T> s;
	int len;
public:
	Vector();
	Vector(int n);
	Vector(const Vector<T>&);
	~Vector();
	void Print();
	T max();
	void add_to_stack(T el);
	void del_element_ftom_stack(int x);
	int srednee();
	void add_element_from_stack();
};

template <class T>
deque<T> copy_queue_to_deque(queue<T> s) {
	deque<T> d;
	while (!s.empty())
	{
		d.push_back(s.front());
		s.pop();
	}
	return d;
}

template <class T>
queue<T> copy_deque_to_queue(deque<T> d){
	queue<T> s;
	for (int i = 0; i < d.size(); i++)
	{
		s.push(d[i]);
	}
	return s;
}

template <class T>
Vector<T>::Vector() {
	len = 0;
}
template <class T>
Vector<T>::Vector(int n) {
	T a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.push(a);
	}
	len = s.size();
}

template <class T>
Vector<T>::~Vector() {}

template <class T>
Vector<T>::Vector(const Vector<T>& Deq) {
	deque<T> d;
	len = d.size();
	deque<T> d = copy_queue_to_deque(Deq.s);
	s = copy_deque_to_queue(d);
}

template <class T>
void Vector<T>::Print() {
	deque<T> d = copy_queue_to_deque(s);
	
	while (!s.empty())
	{
		cout << s.front() << endl;
		s.pop();
	}
	s = copy_deque_to_queue(d);
}

template <class T>
T Vector<T>::max() {
	T m = s.front();
	deque<T> d = copy_queue_to_deque(s);
	while (!s.empty())
	{
		if (s.front() > m)
		{
			m = s.front();
		}
		s.pop();
	}
	s = copy_deque_to_queue(d);
	return m;
}

template <class T>
void Vector<T>::add_to_stack(T el) {
	deque<T> d = copy_queue_to_deque(s);
	d.push_back(el);
	s = copy_deque_to_queue(d);
}

template <class T>
void Vector<T>::del_element_ftom_stack(int x)
{
	deque<T> d;
	T t;
	int i = 0;
	while (!s.empty())
	{
		t = s.front();
		if (i != x)d.push_back(t);
		s.pop();
		i++;
	}
	s = copy_deque_to_queue(d);
}

template<class T>
int Vector<T>::srednee() {
	deque<T> d = copy_queue_to_deque(s);
	int n = 1;
	Time sum = s.front();
	s.pop();
	while (!s.empty())
	{
		sum = sum + s.front();
		s.pop();
		n++;
	}
	s = copy_deque_to_queue(d);
	return sum / n;
}

template<class T>
void Vector<T>::add_element_from_stack() {
	int sred = srednee();
	deque<T> d;
	T t;
	T x;
	while (!s.empty())
	{
		t = s.front();
		x = t + sred;
		d.push_back(x);
		s.pop();
	}
	s = copy_deque_to_queue(d);
}