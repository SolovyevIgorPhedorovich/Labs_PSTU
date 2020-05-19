#include "Vector.h"
#include <iostream>

using namespace std;

void main() {
	int n = 2;
	Vector a(5,2);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";
	a[2] = 100;
	cout << a << "\n";
	Vector b(10,2);
	cout << b << "\n";
	b = a;
	cout << b << "\n";
	Vector c(10,2);
	c = b * 2;
	cout << c << "\n";
	cout << a() << endl;
	cout << *(a.first()) << endl;
	Iterator i = a.first();
	++i;
	++i;
	cout << *i << endl;
	i -= n;
	cout << *i << endl;
}