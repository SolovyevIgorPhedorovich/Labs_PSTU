#pragma once
#include "Pasport.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;
template <class T>
class Fio
{
public:
	Fio(int s);
	Fio(const Fio<T>& a);
	~Fio();
	Fio& operator=(const Fio<T>& a);
	T& operator[](int index);
	Fio operator*(int k);
	int operator()();
	friend ostream& operator<< <>(ostream& out, const Fio<T>& a);
	friend istream& operator>> <>(istream& in, Fio<T>& a);
private:
	int size;
	T* data;
};

template <class T>
Fio<T>::Fio(int s) {
	srand(time(NULL));
	size = s;
	data = new T[size];
	vector<string> surnames = { "Иванов ","Петров ","Сидоров ","Тесла ","Маск ","Эйнштейн ","Ньютон ","Гук ","Кюри ","Сталин ","Ленин ","Маркс " };
	vector<string> names = { "Иван ","Петр ","Сидор ","Никола ","Илон ","Альберт ","Исаак ","Роберт ","Мария ","Иосиф ","Владимир ","Карл ","Алексей ","Михаил ","Дмитрий " };
	vector<string> patronymics = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович","Владимирович","Карлович","Алексеевич","Михаилович","Дмитриевич" };
	for (int i = 0; i < size; i++) {
		int s = rand() % 12;
		int n = rand() % 15;
		int p = rand() % 15;
		string sur = surnames[s];
		string na = names[n];
		string patr = patronymics[p];
		T fio = sur+na+patr;
		data[i] = fio;
	}
}

template <class T>
Fio<T>::Fio(const Fio& a) {
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
template <class T>
Fio<T>::~Fio() {
	delete[]data;
	data = 0;
}
template <class T>
Fio<T>& Fio<T>::operator=(const Fio<T>& a) {
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}

template <class T>
T& Fio<T>::operator[](int index) {
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
template <class T>
Fio<T> Fio<T>::operator*(int k) {
	for (int i = 0; i < size; ++i)
		data[i] = data[i] * k;
	return *this;
}
template <class T>
int Fio<T>::operator()() {
	return size;
}
template <class T>
ostream& operator<<(ostream& out, const Fio<T>& a) {
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>>(istream& in, Fio<T>& a) {
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}