#include "Vector.h"
#include "Error.h"
#include <iostream>

using namespace std;
int main() {
	try {
		Vector x(5);
		cout << x;
		cout << "Nomer?";
		int i;
		cin >> i;
		cout << x[i] << endl;
		--x;
		cout << x;
		--x;
		cout << x;
		x--;
		cout << x;
		x--;
		cout << x;
		x--;
		cout << x;
		x--;
		cout << x;
		x--;
		cout << x;
		x--;
		cout << x;
		x--;
		x--;
		cout << x;
		x--;
		cout << x;
	}
	catch (error e) { e.what(); }
	return 0;
}