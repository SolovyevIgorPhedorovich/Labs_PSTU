#include "Time.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Ru");
	Time a;
	Time b;
	Time c;
	cin >> a;
	cin >> b;
	++a;
	cout << a << endl;
	if (a == b)
		cout<< "Временные промежутки равны"<<endl;
	else
		cout << "Временные промежутки не равны"<<endl;
	cout << "a=" << a << endl;
	cout << "b=" << b++ << endl;
}