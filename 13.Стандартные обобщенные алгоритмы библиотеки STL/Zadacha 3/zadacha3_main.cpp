#include <C:\\Users\Acer\Desktop\Учеба\Контрольные работы\Информатика 2 семестр\Лабораторная работа №11\Zadacha 2\Time.h>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef multimap<int, Time>MMap;
typedef MMap::iterator it;
Time t;

MMap make_multimap(int n)
{
	MMap m;
	Time a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void print_multimap(MMap m) {
	for (auto it = m.begin(); it != m.end(); ++it)
		cout << it->first << " - " << it->second << " " << endl;
}

Time max(MMap m)
{
	it i = m.begin();
	Time n = (*i).second;
	while (i!=m.end())
	{
		if (n < (*i).second)
			n = (*i).second;
		i++;
	}
	return n;
}

int srednee(MMap m)
{
	it i = m.begin();
	Time z = (*i).second;
	while (i!=m.end())
	{
		if ((*i).second != z) {
			z = z + (*i).second;
		}
		i++;
	}
	int n = m.size();
	return z / n;
}

void add(MMap& m,int x)
{
	it i = m.begin();
	while (i!=m.end())
	{
		(*i).second = (*i).second + x;
		i++;
	}
}

void main()
{
	int n;
	cout << "N?"; cin >> n;
	multimap<int, Time> m = make_multimap(n);
	print_multimap(m);
	cout << "Add max" << endl;
	t = max(m);
	m.insert(make_pair(n, t));
	print_multimap(m);
	int k;
	cout << "Key?"; cin >> k;
	m.erase(k);
	cout << "Del element" << endl;
	print_multimap(m);
	cout << "Add" << endl;
	int x = srednee(m);
	add(m,x);
	print_multimap(m);
}