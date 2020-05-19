#include "Vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

void main() {
	Time t;
	cin >> t;
	cout << t;
	Vector<Time>A(5, t);
	cin >> A;
	cout << A << endl;
	Vector<Time>B(10, t);
	cout << B << endl;
	B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << "size = " << A() << endl;
	int x; 
	cin >> x;
	B = A * x;
	cout << B << endl;
}