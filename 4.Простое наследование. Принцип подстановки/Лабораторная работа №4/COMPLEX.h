#pragma once
#include "PAIR.h"
class COMPLEX :
	public PAIR
{
public:
	COMPLEX(void);
public:
	~COMPLEX(void);
	COMPLEX(int, int);
	COMPLEX(const COMPLEX&);
	int Get_m_real() { return m_real; }
	int Get_m_imag() { return m_imag; }
	void Set_m_real(int);
	void Set_m_imag(int);
	COMPLEX& operator=(const COMPLEX&);
	COMPLEX operator *(const COMPLEX&);
	COMPLEX operator -(const COMPLEX&);
	friend istream& operator>>(istream& in, COMPLEX&C);
	friend ostream& operator<<(ostream& out, const COMPLEX&C);
protected:
	int m_real;
	int m_imag;
};

