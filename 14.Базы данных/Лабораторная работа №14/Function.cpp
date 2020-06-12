#include "Function.h"

void DataInitialization(){
	ofstream buf("Buffer.txt");

	if (!buf)
		cout << "������ �������� �����." << endl;
	buf.close();
}

void DataEntry() {
	string author;
	string name_book;
	int year;
	string izdatel;
	int n;

	cout << "������� ����������� ������: ";
	cin >> n;

	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++) {
			cout << "������� ������ ������: ";
			cin >> author;
			cout << "������� �������� �����: ";
			cin >> name_book;
			cout << "������� ��� �������: ";
			cin >> year;
			cout << "������� ������������: ";
			cin >> izdatel;

			record << author << endl;
			record << name_book << endl;
			record << year << endl;
			if (i < n - 1)
				record << izdatel << endl;
			else
				record << izdatel;
			cout << "___________________________" << endl;
		}
	}
	else
		cout << "������ �������� �����!" << endl;
	record.close();
}

void DataReading(string filename) {
	ifstream reading(filename);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string author;
			string name_book;
			int year;
			string izdatel;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> author;
				reading >> name_book;
				reading >> year;
				reading >> izdatel;

				record << author << endl;
				record << name_book << endl;
				record << year << endl;
				if (i < n - 1)
					record << izdatel << endl;
				else
					record << izdatel;
			}
			cout << "Compleat" << endl;
		}
		else cout << "������ �������� ������!" << endl;
	}
	else cout << "������ �������� �����!" << endl;
	reading.close();
	record.close();
} 

void Print() {
	ifstream reading("Buffer.txt");

	if (reading) {
		string author;
		string name_book;
		int year;
		string izdatel;
		int n;

		reading >> n;
		cout << "����������� ������: " << n << endl << endl;

		for (int i = 0; i < n; i++) {
			cout << "������ �� �" << 1 + i << endl;
			reading >> author;
			cout << "�����: " << author << endl;
			reading >> name_book;
			cout << "�������� �����: " << name_book << endl;
			reading >> year;
			cout << "��� �������: " << year << endl;
			reading >> izdatel;
			cout << "��������: " << izdatel << endl;
			cout << "____________________________________________________" << endl;
		}
	}
	else cout << "������ ������ �����!" << endl;
	reading.close();
}

void Print_po_author(string aut) {
	ifstream reading("Buffer.txt");

	if (reading) {
		string author;
		string name_book;
		int year;
		string izdatel;
		int n;

		reading >> n;

		for (int i = 0; i < n; i++) {
			reading >> author;
			reading >> name_book;
			reading >> year;
			reading >> izdatel;
			if (author == aut) {
				
				cout << "�������� �����: " << name_book << endl;
				
			}
		}
	}
	else cout << "������ ������ �����!" << endl;
	reading.close();
}

void Print_po_year(int y) {
	ifstream reading("Buffer.txt");

	if (reading) {
		string author;
		string name_book;
		int year;
		string izdatel;
		int n;

		reading >> n;

		for (int i = 0; i < n; i++) {
			reading >> author;
			reading >> name_book;
			reading >> year;
			reading >> izdatel;
			if (y == year) {
				cout << "�������� �����: " << name_book << endl;
			}
		}
	}
	else cout << "������ ������ �����!" << endl;
	reading.close();
}

bool DataCleaning() {

	bool clear = false;

	fstream buf("Buffer.txt", ios::out);

	if (!buf)
		cout << "������ �������� ��������� �����!" << endl;

	buf.clear();

	if (buf.peek() == EOF)
		clear = true;
	else
		clear = false;
	buf.close();
	return clear;
}

void DataChange() {

	Copy();

	ifstream reading("Buffer1.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string author;
			string name_book;
			int year;
			string izdatel;
			int n, n1;

			reading >> n;
			cout << "�������� ������ ����������� �������� (�� 1 �� " << n << "): " << endl;
			cin >> n1;
			n1--;

			system("cls");
			record << n << endl;
			if (n1 >= 0 && n1 < n) {
				for (int i = 0; i < n; i++) {
					if (i != n1) {
						reading >> author;
						record << author << endl;
						reading >> name_book;
						record << name_book << endl;
						reading >> year;
						record << year << endl;
						reading >> izdatel;
						if (i < n - 1)
							record << izdatel << endl;
						else
							record << izdatel;
					}
					else {
						cout << "������� ������ ������: ";
						cin >> author;
						cout << "������� �������� �����: ";
						cin >> name_book;
						cout << "������� ��� �������: ";
						cin >> year;
						cout << "������� ������������: ";
						cin >> izdatel;

						record << author << endl;
						record << name_book << endl;
						record << year << endl;
						if (i < n - 1)
							record << izdatel << endl;
						else
							record << izdatel;
						reading >> author;
						reading >> name_book;
						reading >> year;
						reading >> izdatel;
					}
				}
				cout << "������ ���������!" << endl;
			}
			else cout << "����� ������ �� �����." << endl;
		}
		else cout << "������ �������� �����!" << endl;
	}
	else cout << "������ �������� ��������� �����!" << endl;
	record.close();
	reading.close();

	remove("Buffer1.txt");
}

void Copy() {
	ifstream reading("Buffer.txt");
	ofstream record("Buffer1.txt", ios::out);

	if (reading) {
		if (record) {
			string author;
			string name_book;
			int year;
			string izdatel;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> author;
				record << author << endl;
				reading >> name_book;
				record << name_book << endl;
				reading >> year;
				record << year << endl;
				reading >> izdatel;
				if (i < n - 1)
					record << izdatel << endl;
				else
					record << izdatel;
			}
		}
		else cout << "������ �������� �����!" << endl;
	}
	else cout << "������ �������� ��������� �����!" << endl;
	reading.close();
	record.close();
}

void DeleteData() {
	Copy();

	ifstream reading("Buffer1.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			string author;
			string name_book;
			int year;
			string izdatel;
			int n, n1;

			reading >> n;
			int b = n - 1;
			cout << "������� ����� ���������� ���������(�� 1 �� " << n << "):" << endl;
			cin >> n1;
			--n1;
			system("cls");
			record << b << endl;
			if (n1 >= 0 && n1 < n) {
				for (int i = 0; i < n; i++) {
					if (i != n1) {
						reading >> author;
						record << author << endl;
						reading >> name_book;
						record << name_book << endl;
						reading >> year;
						record << year << endl;
						reading >> izdatel;
						if (i < n - 1)
							record << izdatel << endl;
						else
							record << izdatel;
					}
					else {
						reading >> author;
						reading >> name_book;
						reading >> year;
						reading >> izdatel;
					}
				}cout << "������ ��������!" << endl;
			}
			else cout << "����� ������ �� ������!" << endl;
		}
		else cout << "������ �������� �����!" << endl;
	}
	else cout << "������ �������� ��������� �����!" << endl;
	record.close();
	reading.close();
	remove("Buffer1.txt");
}

int AmountOfData() {
	ifstream buf("Buffer.txt");
	int n;

	if (buf) {
		buf >> n;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;
	buf.close();
	return n;
};

void AddData() {
	string author;
	string name_book;
	int year;
	string izdatel;
	int n = AmountOfData();
	int d;
	int x;
	cout << "������� 1 ����� ��������� ������ � ������ �����, 2 ����� � �����:"; cin >> d;

	if (d == 1) {
		Copy();
		ifstream reading("Buffer1.txt");
		ofstream record1("Buffer.txt", ios::out | ios::in);
		ofstream record("Buffer.txt", ios::out);
		if (record1) {
			record1 << ++n << endl;
		}
		else cout << "������ �������� �����!" << endl;
		
		if (reading) {
			if (record) {
				reading >> x;
				for (int i = 0; i < n; i++) {
					if (i != 0) {

						reading >> author;
						record << author << endl;
						reading >> name_book;
						record << name_book << endl;
						reading >> year;
						record << year << endl;
						reading >> izdatel;
						if (i < n - 1)
							record << izdatel << endl;
						else
							record << izdatel;
					}
					else {
						record << n<<endl;
						cout << "������� ������ ������: ";
						cin >> author; record << author << endl;
						cout << "������� �������� �����: ";
						cin >> name_book; record << name_book << endl;
						cout << "������� ��� �������: ";
						cin >> year; record << year << endl;
						cout << "������� ������������: ";
						cin >> izdatel;	record << izdatel << endl;
					}
				}
			}
		}
		else cout << "��������� ������� ����!" << endl;
		record.close();
		record1.close();
		reading.close();
		remove("Buffer1.txt");
	}
	if (d == 2) {
		ofstream record("Buffer.txt", ios::app);
		ofstream record1("Buffer.txt", ios::out | ios::in);
		if (record1) {
			record1 << ++n << endl;
		}
		else cout << "������ �������� �����!" << endl;

		if (record) {

			record << endl;
			cout << "������� ������ ������: ";
			cin >> author;

			cout << "������� �������� �����: ";
			cin >> name_book;

			cout << "������� ��� �������: ";
			cin >> year;

			cout << "������� ������������: ";
			cin >> izdatel;

			record << author << endl;
			record << name_book << endl;
			record << year << endl;
			record << izdatel << endl;
		}
		else cout << "������ �������� �����!";
		record.close();
		record1.close();
	}
}


void SaveData(string fileName){
	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (record) {
		if (record) {
			string author;
			string name_book;
			int year;
			string izdatel;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> author;
				record << author << endl;
				reading >> name_book;
				record << name_book << endl;
				reading >> year;
				record << year << endl;
				reading >> izdatel;
				if (i < n - 1)
					record << izdatel << endl;
				else
					record << izdatel;
			}
			cout << "������ ���������� � ���� " << fileName << endl;
		}
		else
			cout << "��������� ������� ����!" << endl;
	}
	else cout << "��������� ������� �������� ����!" << endl;
	reading.close();
	record.clear();
	
}