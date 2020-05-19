#pragma once
#include "Event.h"
#include "Book.h"
#include <iostream>
using namespace std;
class Vector
{
public:
	Vector(int);
public:
	~Vector(void);
	void Add();
	void Del();
	void Show();
	int operator()();
	void HandleEvent(const TEvent&);
protected:
	Object** beg;
	int size;
	int cur;
};

