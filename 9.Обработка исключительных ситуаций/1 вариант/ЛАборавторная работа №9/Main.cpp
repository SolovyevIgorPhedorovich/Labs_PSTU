#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
	try {
		Vector x(10);
		cout << x;
		cout << "Nomer?";
		int i;
		cin >> i;
		cout << x[i] << endl;
		x();
		cout << x;
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
		cout << x;
		x--;
		cout << x;
		
	}
		catch (int)
		{
			cout << "Error!" << endl;
		}
		return 0;

}