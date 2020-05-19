#include "Chislo.h"
#include <string>

Chislo::Chislo()
{
	mantissa=0.0;
	poradok=0;
	str_predstaflenie="";
	cout << "Constructor bez parametrov dlia objecta: " << this << endl;
}

Chislo::Chislo(float N, int K, string S)
{
	mantissa = N;
	poradok = K;
	str_predstaflenie = S;
	cout << "Constructor s parametrov dlia objecta: " << this << endl;
}

Chislo::Chislo(const Chislo &t)
{
	mantissa = t.mantissa;
	poradok = t.poradok;
	str_predstaflenie = t.str_predstaflenie;
	cout << "Constructor copirovania dlia objecta:" << this << endl;
}

Chislo::~Chislo()
{
	cout << "Destructor dlia objecta: " << this << endl;
}

float Chislo::get_mantissa()
{
	return mantissa;
}
int Chislo::get_poradok()
{
	return poradok;
}
string Chislo::get_str_predstaflenie()
{
	return str_predstaflenie;
}

void Chislo::set_mantissa(float N)
{
	mantissa = N;
}
void Chislo::set_poradok(int K)
{
	poradok = K;
}
void Chislo::set_str_predstaflenie(string S)
{
	str_predstaflenie = S;
}

void Chislo::show()
{
	cout << "mantissa : " << mantissa << endl;
	cout << "poradok : " << poradok << endl;
	cout << "str_predstaflenie : " << str_predstaflenie << endl;
}