#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;

typedef deque<int>Deq;
Deq make_deque(int n) {
	Deq d;
	for (int i = 0; i < n; i++) {
		int a = rand() % 100 - 50;
		d.push_back(a);
	}
	return d;
}

void print_deque(Deq d) {
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << endl;
}
int max(Deq d)
{
	int s = 0;
	int m = d[0];
	for (int i = 0; i < d.size(); i++)
	{
		s = d[i];
		if (s > m) {
			m = d[i];
		}
	}
	return m;
}

void add_deque(Deq& d, int el) {
	d.push_back(el);
}


void del_deque(Deq& d, int pos) {
	d.erase(d.begin()+pos);
}

int srednee(Deq d) {
	int s = 0;
	for (int i = 0; i < d.size(); i++)
		s += d[i];
	int n = d.size();
	return s / n;
}

void add_srednee(Deq& d, int sred)
{
	for (int i = 0; i < d.size(); i++) {
		d[i] = d[i] + sred;
	}
}

void main() {
	try {
		deque<int> d;
		deque<int>::iterator di = d.begin();
		int n;
		cout << "N?"; cin >> n;
		d = make_deque(n);
		print_deque(d);
		int el = max(d);
		add_deque(d, el);
		print_deque(d);
		int x;
		cout << "Key del?"; cin >> x;
		if (x < d.size()) {
			del_deque(d, x);
			print_deque(d);
		}
		else {
			cout << "Error! Key > size" << endl;
		}
		int sred = srednee(d);
		add_srednee(d, sred);
		print_deque(d);
	}
	catch (int) {
		cout << "error!";
	}
}