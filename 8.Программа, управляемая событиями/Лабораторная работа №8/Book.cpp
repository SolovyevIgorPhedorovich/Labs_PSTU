#include "Book.h"

Book::Book(void) :Print() {
	num_pag = 0;
	pub = "";
}

Book::~Book(void){}
Book::Book(string T, string A, int N, string P) {
	num_pag = N;
	pub = P;
}
Book::Book(const Book& B) {
	title = B.title;
	author = B.author;
	num_pag = B.num_pag;
	pub = B.pub;
}
void Book::Set_num_pag(int N) {
	num_pag = N;
}
void Book::Set_pub(string P) {
	pub = P;
}
Book& Book::operator=(const Book& b) {
	if (&b == this)return *this;
	title = b.title;
	author = b.author;
	return *this;
}
void Book::Show() {
	cout << "\nTITLE : " << title;
	cout << "\nAUTHOR : " << author;
	cout << "\nNUM_PAG : " << num_pag;
	cout << "\nPUB : " << pub;
	cout << "\n";
}
void Book::Input() {
	cout << "\nTittle:"; cin >> title;
	cout << "\nAuthor:"; cin >> author;
	cout << "\nNUM_PAG:"; cin >> num_pag;
	cout << "\nPUB:"; cin >> pub;
}

void Book::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command)
		{
		case cmGet:
			cout << "Title = " << Get_title() << endl;
			break;
		}
	}
}