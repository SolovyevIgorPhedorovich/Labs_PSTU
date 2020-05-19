#include "Time.h"
#include <iostream>
#include<fstream>
#include"file_work.h"
using namespace std;
void main() {
	Time t,t1,t2, t3;
	int k, c;
	char file_name[30];
	do {
		cout << "\n1.Make_file";
		cout << "\n2. Print file";
		cout << "\n3. Delete record from file";
		cout << "\n4. Add record from file";
		cout << "\n5. Change record in file";
		cout << "\n0.Exit";
		cin >> c;
		switch (c)
		{
		case 1:cout << "file name?"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Cam't make file";
			break;
		case 2: cout << "file name? "; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "Can't read file\n";
			break;
		case 3: cout << "file name?"; cin >> file_name;
			cout << "Time 1?"; cin >> t1;
			cout << "Time 2?"; cin >> t2;
			k = del_file(file_name, t1, t2);
			if (k < 0)cout << "Can't read file";
			break;
		case 4: cout << "file name?";
			cin >> file_name;
			int col;
			cout << "col?"; cin >> col;
			for (int i = 0; i < col; i++) {
				cout << "New time:";
				Time t;
				cin >> t;
				k = add_file(file_name, t);
				if (k < 0) cout << "Can't read file";
			}
			break;
		case 5: cout << "file_name?";
			cin >> file_name;
			cout << "Time?"; cin >> t3;
			k = chang_file(file_name, t3);
			if (k < 0)cout << "\nCan't read file";
			if (k == 0)cout << "\nNot such record";
			break;
		}
		
	} while (c != 0);
}
