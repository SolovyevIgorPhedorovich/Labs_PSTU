#include <iostream>
#include "fraction.h"

using namespace std;

void fraction::Init(double F, double S) {
	first = F;
	second = S;
}

void fraction::Read()
{
	cout << "\nfirst?"; cin >> first;
	cout << "\nsecond?"; cin >> second;
}

void fraction::Show() {
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << "\n = ";
}

bool fraction::Rangecheck(double x) {
	if (x > first && x < second) {
		return true;
	}
	else {
		return false;
	}
}