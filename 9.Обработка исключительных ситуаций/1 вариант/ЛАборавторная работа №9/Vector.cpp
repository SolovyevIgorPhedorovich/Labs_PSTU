#include "Vector.h"

Vector::Vector(int s) {
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = i;
}
Vector::Vector(const Vector& v) {
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++) {
		beg[i] = v.beg[i];
	}
}

Vector::~Vector() {
	if (beg != 0)delete[]beg;
}

Vector::Vector(int s, int* mas) {
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++) {
		beg[i] = mas[i];
	}
}

const Vector& Vector::operator=(const Vector& v) {
	if (this == &v)return*this;
	if (beg != 0)delete[]beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return *this;
}

ostream& operator<<(ostream& out, const Vector& v) {
	if (v.size == 0)out << "Empty\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << "";
		out << endl;
	}
	return out;
}
istream& operator>>(istream& in, Vector& v) {
	for (int i = 0; i < v.size; i++) {
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}

int Vector::operator[](int i) {
	return beg[i];
}

int Vector::operator()() {
	return size;
}

Vector Vector::operator--() {
	if (size == 0) throw 5;
	if (size == 1) {
		size = 0;
		delete[] beg;
		beg = 0;
		return *this;
	}
	Vector temp(size, beg);
	delete[]beg;
	size--;
	beg = new int[size];
	for (int i = 0, x = 1; i < size, x < temp.size; i++,x++)
		beg[i] = temp.beg[x];
	return*this;
}

Vector Vector::operator--(int v) {
	if (size == 0)throw 5;
	if (size == 1) {
		size = 0;
		delete[]beg;
		beg = 0;
		return *this;
	}
	Vector temp(size, beg);
	delete[]beg;
	size--;
	beg = new int[size];
	for (int i = 0; i < size;i++)
		beg[i] = temp.beg[i];
	return temp;

}