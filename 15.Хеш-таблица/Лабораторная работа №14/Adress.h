#pragma once
#include <ctime>
#include <iostream>
using namespace std;
template <class T>
class Adress
{
public:
	Adress(int s);
	Adress(const Adress<T>& a);
	~Adress();
	Adress& operator=(const Adress<T>& a);
	T& operator[](int index);
	Adress operator*(int k);
	int operator()();
	friend ostream& operator<< <>(ostream& out, const Adress<T>& a);
	friend istream& operator>> <>(istream& in, Adress<T>& a);
private:
	int size;
	T* data;
};


template <class T>
Adress<T>::Adress(int s) {
	srand(time(NULL));
	size = s;
	data = new T[size];
	for (int i = 0, j = 0; i < size; i++) {
		T t;
		j = rand() % 10;
		for (int k = 0; k < j; k++) {
			t += (char)(rand() % 26 + 97);
		}
		data[i] = t;
	}
}
template <class T>
Adress<T>::Adress(const Adress& a) {
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
template <class T>
Adress<T>::~Adress() {
	delete[]data;
	data = 0;
}
template <class T>
Adress<T>& Adress<T>::operator=(const Adress<T>& a) {
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}

template <class T>
T& Adress<T>::operator[](int index) {
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
template <class T>
Adress<T> Adress<T>::operator*(int k) {
	for (int i = 0; i < size; ++i)
		data[i] = data[i] * k;
	return *this;
}
template <class T>
int Adress<T>::operator()() {
	return size;
}
template <class T>
ostream& operator<<(ostream& out, const Adress<T>& a) {
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>>(istream& in, Adress<T>& a) {
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}
