#include "COMPLEX.h"

COMPLEX::COMPLEX(void) :PAIR() {
	m_real = 0;
	m_imag = 0;
}
COMPLEX::~COMPLEX(void) {}

COMPLEX::COMPLEX(int r, int i) {
	m_real = r;
	m_imag = i;
}

COMPLEX::COMPLEX(const COMPLEX& c) {
	m_real = c.m_real;
	m_imag = c.m_imag;
}

void COMPLEX::Set_m_real(int r) {
	m_real = r;
}

void COMPLEX::Set_m_imag(int i) {
	m_imag = i;
}

COMPLEX& COMPLEX::operator=(const COMPLEX& c) {
	if (&c == this)return *this;
	m_real = c.m_real;
	m_imag = c.m_imag;
	return *this;
}

COMPLEX COMPLEX::operator*(const COMPLEX& c) {
	int temp1 = m_real;
	int temp2 = m_imag;
	int temp3 = c.m_real;
	int temp4 = c.m_imag;
	COMPLEX N;
	N.m_real = (temp1 * temp3 - temp2 * temp4);
	N.m_imag = (temp1 * temp4 + temp2 * temp3);
	return N;
}

COMPLEX COMPLEX::operator-(const COMPLEX& c) {
	int temp1 = m_real;
	int temp2 = m_imag;
	int temp3 = c.m_real;
	int temp4 = c.m_imag;
	COMPLEX X;
	X.m_real = temp1 - temp2;
	X.m_real = temp3 - temp4;
	return X;
}

istream& operator>>(istream& in, COMPLEX& C) {
	cout << "\nreal:"; in >> C.m_real;
	cout << "\nimag:"; in >> C.m_imag;
	return in;
}
ostream& operator << (ostream& out, const COMPLEX& C) {
	out << "(" << C.m_real << "," << C.m_imag << ")";
	return out;
}

void COMPLEX::Show() {
	cout << "(" << first << "," << second << ")";
	cout << "\n";
}