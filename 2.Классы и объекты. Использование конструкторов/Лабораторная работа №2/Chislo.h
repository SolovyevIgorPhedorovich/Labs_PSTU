#pragma once
#include <iostream>
#include <string>

using namespace std;

class Chislo
{
	float mantissa;
	int poradok;
	string str_predstaflenie;
public:
	Chislo();
	Chislo(float, int, string);
	Chislo(const Chislo&);
	~Chislo();
	float get_mantissa();
	void set_mantissa(float);
	int get_poradok();
	void set_poradok(int);
	string get_str_predstaflenie();
	void set_str_predstaflenie(string);
	void show();
};