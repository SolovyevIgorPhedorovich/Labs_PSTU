#pragma once
#include "Print.h"
#include "Event.h"
#include <string>
class Book :
	public Print
{
public:
	Book(void);
public:
	~Book(void);
	void Show();
	void Input();
	Book(string, string, int, string);
	Book(const Book&);
	int Get_num_pag() { return num_pag; }
	string Get_pub() { return pub; }
	void Set_num_pag(int);
	void Set_pub(string);
	Book& operator=(const Book&);
	void HandleEvent(const TEvent& event);
protected:
	int num_pag;
	string pub;
};

