#pragma once
#include <iostream>
#include <map>
using namespace std;
template<class T>
class Vector
{
	map<int, T>m;
	int len;
public:
	Vector(void);
	Vector(int n);
	void print();
	~Vector(void);
	T max();
	void add_element(int);
	int key(T x);
	int srednee();
	void del();
	void add(int n);
};

template <class T>
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::~Vector(void) {}

template <class T>
Vector<T>::Vector(int n) {
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m[i] = a;
	}
	len = m.size();
}

template <class T>
void Vector<T>::print() {
	for (int i = 0; i < m.size(); i++)
		cout << i << " : " << m[i] << " " << endl;
	cout << endl;
}

template <class T>
T Vector<T>::max() {
	T t = m[0];
	for(int i=0;i<m.size();i++)
	{
		if (t < m[i])
			t = m[i] ;
	}
	return t;
}

template <class T>
void Vector<T>::add_element(int sred) {
	for (int i = 0; i < m.size(); i++)
		m[i] = m[i] + sred;
}

template <class T>
int Vector<T>::key(T x) {
	int nom = 0, k = 0;
	for(int i=0;i<m.size();i++)
	{
		if (m[i] == x)
			nom = k;
		k++;
	}
	return nom;
}

template <class T>
int Vector<T>::srednee() {
	T s = m[0];
	for (int i = 1; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();
	return s / n;
}

template <class T>
void Vector<T>::del() {
	T x;
	cout << "Time?"; cin >> x;
	int pos = key(x);
	cout << "pos = " << pos << endl;
	m.erase(pos);
}

template <class T>
void Vector<T>::add(int n)
{
	T el = max();
	cout << "Max = " << el << endl;
	m.insert(make_pair(n, el));
}