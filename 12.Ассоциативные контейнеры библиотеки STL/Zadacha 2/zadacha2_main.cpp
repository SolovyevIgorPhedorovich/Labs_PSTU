#include <iostream>
#include <map>
#include<C:\\Users\Acer\Desktop\Учеба\Контрольные работы\Информатика 2 семестр\Лабораторная работа №11\Zadacha 2\Time.h>

using namespace std;

typedef map<int, Time>TMap;
typedef TMap::iterator it;

TMap make_map(int n)
{
	TMap m;
	Time a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void print_map(TMap m) {
	for (int i = 0; i < m.size(); i++)
		cout << i << " - " << m[i] << " " << endl;
}

Time max(TMap v) {
	it i = v.begin();
	int nom = 0;
	Time m = (*i).second;
	while (i!=v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
		}
		i++;
	}
	return m;
}

void add_element(TMap& v, int sred) {
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + sred;
}

int key(TMap v, Time key) {
	it i = v.begin();
	int nom = 0, k = 0;
	Time m = (*i).second;
	while (i != v.end()) {
		if ((*i).second == key)
			nom = k;
		i++;
		k++;
	}
	return nom;
}

int srednee(TMap m)
{
	Time s = m[0];
	for (int i = 1; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();
	return s / n;
}

void main() {
	int n;
	cout << "N?"; cin >> n;
	map<int, Time> m = make_map(n);
	print_map(m);
	Time el = max(m);
	cout << "Max=" << el<<endl;
	m.insert(make_pair(n, el));
	print_map(m);
	Time x;
	cout << "Time?:"; cin >> x;
	int nom = key(m,x);
	cout << "Nom=" << nom<<endl;
	m.erase(nom);
	print_map(m);
	cout << "Srednee" << endl;
	int sred = srednee(m);
	add_element(m, sred);
	print_map(m);

}