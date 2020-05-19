#include <iostream>
#include "PAIR.h"
#include "COMPLEX.h"

using namespace std;

void main() {
	PAIR a;
	PAIR b;
	COMPLEX c;
	COMPLEX d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cout <<"(a,b) + (c,d) = "<< a + b<<endl;
	cout << "(a,b) * (c,d) = " << c * d<<endl;
	cout << "(a,b) - (c,d) = " << c - d<<endl;
}