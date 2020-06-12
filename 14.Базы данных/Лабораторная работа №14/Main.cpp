#include "Function.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int stateMenu;
void Menu() {
	cout << "�������� ��������:" << endl
		<< "(0) ����� �� ���������." << endl
		<< "(1) ���� ������." << endl
		<< "(2) ����� ������." << endl
		<< "(3) �������������� ������." << endl
		<< "(4) �������� ������." << endl
		<< "(5) ���������� ������." << endl
		<< "(6) ���������� ������." << endl;
	cin >> stateMenu;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	DataInitialization();

	Menu();

	int actions;
	string fileName;

	while (stateMenu != 0) {
		switch (stateMenu)
		{
		case 1:
			system("cls");

			cout << "���� ������� ��� �� �����?:";
			cin >> actions;
			system("cls");
			if (actions == 1) {
				DataEntry();
			}
			else {
				cout << "������� �������� �����: ";
				cin >> fileName;
				DataReading(fileName);
			}

			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			cout << "������� ���,������� �� ������, ������� �� ���� �������:";
			cin >> actions;
			if(actions==1)
			{
				Print(); 
			}
			if (actions == 2)
			{
				string aut;
				cout << "������� ������:"; cin >> aut;
				Print_po_author(aut);
			}
			if(actions == 3) {
				int year;
				cout << "������� ��� �������:"; cin >> year;
				Print_po_year(year);
			}
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			DataChange();

			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			DeleteData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			AddData();
			system("pause");
			system("cls");
			Menu();
			break;
		case 6:
			system("cls");
			cout << "������� �������� �����:"; cin >> fileName;
			SaveData(fileName);
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "����������� ������ ����� ����!" << endl;
			break;
		}
	}
	system("cls");
	if (DataCleaning())
		cout << "������ �������!" << endl;
	else
		cout << "������ �� ��������!" << endl;
	system("pause");
}