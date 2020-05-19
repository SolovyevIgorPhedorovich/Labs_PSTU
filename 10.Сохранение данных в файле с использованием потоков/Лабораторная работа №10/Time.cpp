#include "Time.h"

Time::Time() {
	min = 0;
	sec = 0;
}

Time::Time(int M, int S) {
	min = M;
	sec = S;
}

Time::Time(const Time& t) {
	min = t.min;
	sec = t.sec;
}

Time Time::operator=(const Time& t) {
	if (&t == this)return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time Time::operator++() {
	int temp = min * 60 + sec;
	temp++;
	min = temp / 60;
	sec = temp % 60;
	return *this;
}

bool Time::operator==(const Time&t) {
	int temp1 = min/60+sec;
	int temp2 = t.min / 60 + t.sec;
	if (temp1 == temp2)
		return true;
	else
		return false;
}

bool Time::operator!=(const Time& t) {
	int temp1 = min / 60 + sec;
	int temp2 = t.min / 60 + t.sec;
	if (temp1 != temp2)
		return true;
	else
		return false;
}
Time::~Time(){}

ostream& operator<<(ostream& out, const Time& t) {
	out << t.min << ":" << t.sec<<"\n";
	return out;
}

istream& operator>>(istream& in, Time& t) {
	cout << "min?"; in >> t.min;
	cout << "sec?"; in >> t.sec;
	return in;
}

fstream& operator>>(fstream& fin, Time& t) {
	fin >> t.min;
	fin >> t.sec;
	return fin;
}

fstream& operator<<(fstream& fout, const Time& t) {
	fout << t.min << "\n" << t.sec << "\n";
	return fout;
}