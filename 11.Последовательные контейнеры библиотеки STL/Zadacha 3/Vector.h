#pragma once
#include <iostream>
#include <deque>
using namespace std;
template <class T>
class Vector
{
	deque <T> d;
	int len;
public:
	Vector(void);
	Vector(int n);
	void Print();
	~Vector(void);
	T max();
	void add_deque(T el);
	void del_deque(int pos);
	int srednee();
	void add_srednee(int sred);
};

template <class T>
Vector<T>::Vector() {
	len = 0;
}

template <class T>
Vector<T>::~Vector(void) {}

template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		d.push_back(a);
	}
	len = d.size();
}

template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << endl;
}

template <class T>
T Vector<T>::max()
{
	T s;
	T a = d[0];
	for (int i = 0; i < d.size(); i++) {
		s = d[i];
		if (s > a)
			a = d[i];
	}
	return a;
}

template <class T>
void Vector<T>::add_deque(T el) {
	d.push_back(el);
}


template<class T>
void Vector<T>::del_deque(int pos) {
	if (pos < d.size()) {
		d.erase(d.begin() + pos);
	}
	else {
		cout << "Error! Key > size" << endl;
	}
}

template <class T>
int Vector<T>::srednee() {
	T s;
	for (int i = 0; i < d.size(); i++)
		s += d[i];
	int n = d.size();
	return s / n;
}

template <class T>
void Vector<T>::add_srednee(int sred) {
	for (int i = 0; i < d.size(); i++)
		d[i] = d[i] + sred;
}