#include "Print.h"

Print::Print(void) {
	title = "";
	author = "";
}
Print::~Print(void){}

Print::Print(string T, string A) {
	title = T;
	author = A;
}
Print::Print(const Print& print) {
	title = print.title;
	author = print.author;
}

void Print::Set_title(string T) {
	title = T;
}
void Print::Set_author(string A) {
	author = A;
}

Print& Print::operator=(const Print& p) {
	if (&p == this)return *this;
	title = p.title;
	author = p.author;
	return *this;
}
void Print::Show() {
	cout << "\nTitle : " << title;
	cout << "\nAuthor : " << author;
	cout << "\n";
}
void Print::Input() {
	cout << "\nTitle:"; cin >> title;
	cout << "\nAuthor:"; cin >> author;
}

void Print::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command)
		{
		case cmGet:cout << "Title = " << Get_title() << endl;
			break;
		}
	}
}