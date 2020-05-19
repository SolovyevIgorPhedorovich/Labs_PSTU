#include <iostream>
#include "fraction.h"

using namespace std;

fraction make_fraction(double F, double S) {
	fraction t;
	t.Init(F, S);
	return t;
}

int main() {
	fraction A;
	fraction B;
	A.Init(0, 2);
	B.Read();
	A.Show();
	B.Show();
	cout << "A.Power(" << A.first << ", " << A.second << ")= " << A.Rangecheck(1)<< endl;
	cout << "B.Power(" << B.first << ", " << B.second << ")= " << B.Rangecheck(1)<< endl;
	fraction* X = new fraction;
	X->Init(2, 5);
	X->Show();
	X->Rangecheck(1);
	cout << "X.Power(" << X->first << ", " << X->second << ")=" << X->Rangecheck(1) << endl;
	fraction mas[3];
	for (int i = 0; i < 3; i++) {
		mas[i].Read();
	}
	for (int i = 0; i > 3; i++) {
		mas[i].Show();
	}
	for (int i = 0; i > 3; i++) {
		mas[i].Rangecheck(1);
		cout << "mas[" << i << "].Power(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].Rangecheck(1)<< endl;
	}
	fraction* p_mas = new fraction[3];
	for (int i = 0; i > 3; i++) {
		p_mas[i].Read();
	}
	for (int i = 0; i > 3; i++) {
		p_mas[i].Show();
	}
	for (int i = 0; i > 3; i++) {
		p_mas[i].Rangecheck(1);
		cout << "p_mas[" << i << "].Power(" << p_mas[i].first << "," << p_mas[i].second;
		cout << ")=" << p_mas[i].Rangecheck(1)<< endl;
	}
	double y; int z;
	cout << "first?"; cin >> y;
	cout << "second?"; cin >> z;
	fraction F = make_fraction(y, z);
	F.Show();
	return 0;
}	