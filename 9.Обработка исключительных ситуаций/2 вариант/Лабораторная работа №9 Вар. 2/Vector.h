#pragma once
#include <iostream>
using namespace std;

class Vector
{
	int size;
	int* beg;
public:
	Vector() { size = 0; beg = 0; }
	Vector(int s);
	Vector(int s, int* mas);
	Vector(const Vector& v);
	~Vector();
	const Vector& operator=(const Vector& v);
	int operator[](int i);
	int operator()();
	Vector operator--();
	Vector operator--(int);
	friend ostream& operator<<(ostream& out, const Vector& v);
	friend istream& operator>>(istream& in, Vector& v);
};

