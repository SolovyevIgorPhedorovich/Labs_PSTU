#pragma once
#include <iostream>
#include <ctime>
using namespace std;
template <class T>
class Keys
{
public:
	Keys(int s);
	Keys(const Keys<T>& a);
	~Keys();
	Keys& operator=(const Keys<T>& a);
	T& operator[](int index);
	Keys operator*(int k);
	int operator()();
	friend ostream& operator<< <>(ostream& out, const Keys<T>& a);
	friend istream& operator>> <>(istream& in, Keys<T>& a);
private:
	int size;
	T* data;
};


template <class T>
Keys<T>::Keys(int s) {
	srand(time(NULL));
	size = s;
	const T fill = "0123456789";
	data = new T[size];
	for (int i = 0; i < size; i++) {
		T t;
		for (int k = 0; k < 6; k++) {
			t += fill[rand() % 10];
		}
		data[i] = t;
	}
}
template <class T>
Keys<T>::Keys(const Keys& a) {
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
template <class T>
Keys<T>::~Keys() {
	delete[]data;
	data = 0;
}
template <class T>
Keys<T>& Keys<T>::operator=(const Keys<T>& a) {
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}

template <class T>
T& Keys<T>::operator[](int index) {
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
template <class T>
Keys<T> Keys<T>::operator*(int k) {
	for (int i = 0; i < size; ++i)
		data[i] = data[i] * k;
	return *this;
}
template <class T>
int Keys<T>::operator()() {
	return size;
}
template <class T>
ostream& operator<<(ostream& out, const Keys<T>& a) {
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>>(istream& in, Keys<T>& a) {
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}