#include "PAIR.h"
#include <iostream>
#include <complex>

PAIR::PAIR(void) {
	first = 0;
	second = 0;
}
PAIR::~PAIR(void) {

}
PAIR::PAIR(int first, int second):first(first), second(second) {
	
}
PAIR::PAIR(const PAIR& pair) {
	first = pair.first;
	second = pair.second;
}
void PAIR::Set_first(int F) { 
	first = F;
}
void PAIR::Set_second(int S) {
	second = S;
}

PAIR& PAIR::operator=(const PAIR& P) {
	if (&P == this)return *this;
	first = P.first;
	second = P.second;
	return *this;
}
PAIR PAIR::operator+(const PAIR& t){
	int temp1 = first;
	int temp2 = second;
	int temp3 = t.first;
	int temp4 = t.second;
	PAIR p;
	p.first = temp1 + temp2;
	p.second = temp3 + temp4;
	return p;
}
istream& operator>>(istream& in, PAIR& P) {
	cout << "\nFirst:"; in >> P.first;
	cout << "\nSecond:"; in >> P.second;
	return in;
}
ostream& operator<<(ostream& out,const PAIR& P) {
	out << "(" << P.first<<","<<P.second<<")";
	return out;
}