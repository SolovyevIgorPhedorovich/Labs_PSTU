#pragma once
#include <iostream>

using namespace std;
class PAIR
{
public:
	PAIR(void);
public:
	virtual ~PAIR(void);
	PAIR(int, int);
	PAIR(const PAIR&);
	int Get_first() { return first; }
	int Get_second() { return second; }
	void Set_first(int);
	void Set_second(int);
	PAIR& operator=(const PAIR&);
	PAIR operator+(const PAIR&);
	friend istream& operator>>(istream& in, PAIR& P);
	friend ostream& operator <<(ostream& out, const PAIR& P);
protected:
	int first;
	int second;
};

