#include <iostream>
#include <map>
using namespace std;

typedef map<int, int> TMap;
typedef TMap::iterator it;

TMap make_map(int n)
{
	TMap m;
	int a;
	for (int i = 0; i < n; i++) {
		cout << "?";
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << " : " << m[i] << " " << endl;
}

int max(TMap v) {
	it i = v.begin(); int nom = 0, k = 0;
	int m = (*i).second;
	while (i != v.end()) {
		if (m < (*i).second) {
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return nom;
}

int key(TMap v, int x) {
	it i = v.begin();
	int k = 0;
	int nom = 0;
	while (i!=v.end())
	{
		if ((*i).second == x) nom = k;
		i++;
		k++;
	}
	return nom;

}

int srednee(TMap v)
{
	int s = 0;
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();
	return s / n;
}

void add_element(TMap& v, int sred) {
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + sred;
}

void main() {
	int n;
	cout << "N?"; cin >> n;
	TMap m = make_map(n);
	print_map(m);
	int el = max(m);
	cout << "Max=" << el << endl;
	m.insert(make_pair(n, el));
	print_map(m);
	int x;
	cout << "X?"; cin >> x;
	int pos = key(m, x);
	cout << "nom = " << pos << endl;
	m.erase(pos);
	print_map(m);
	int sred = srednee(m);
	cout << "srednee = " << sred << endl;
	add_element(m, sred);
	print_map(m);
}