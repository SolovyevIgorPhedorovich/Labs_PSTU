#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include "Adress.h"
#include "Vector.h"
#include "Keys.h"
#include "Hash_table.h"
#include <windows.h>
using namespace std;

int stateMenu;
void Menu() {
	cout << "�������� ��������:" << endl
		<< "(0) ����� �� ���������." << endl
		<< "(1) �������� ������� ������." << endl
		<< "(2) ����� �������." << endl
		<< "(3) ���� � �������." << endl
		<< "(4) ���������� ������ � �������." << endl
		<< "(5) �������� ������ �� �������." << endl;
	cin >> stateMenu;
};

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Fio<string> name(100);
	Adress<string> adres(100);
	Keys <string> pas(100);
	Menu();
	string p;
	string nam;
	string sur;
	string na;
	string patr;
	string pasport;
	string adr;
	int size;
	cout << "������� ������ �������:"; cin >> size;
	Hash_Table* hash = new Hash_Table(size);

	while (stateMenu != 0) {
		
		switch (stateMenu)
		{case 1: system("cls"); 
			for (int i = 0; i < 100; i++) {
				hash->insert(pas[i], name[i], adres[i]);
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			cout << "�����:" << endl;
			hash->print(0);
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			cout << "������� ���������:"; cin >> p;
			hash->find(p);
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			cout << "������� �������:�.�"; cin >> sur;
			cout << "������� ���: "; cin >> na;
			cout << "������� �������: "; cin >> patr;
			nam = sur + na + patr;
			cout << "������� N��������"; cin >> pasport;
			cout << "������� �����"; cin >> adr;
			hash->insert(pasport, nam, adr);
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			cout << "������� � ��������"; cin >> pasport;
			hash->del(pasport);
			system("pause");
			system("cls");
			Menu();
			break; 
		default:
			cout << "����������� ������ ����� ����!" << endl;
			break;

		}
	}
	system("pause");
}