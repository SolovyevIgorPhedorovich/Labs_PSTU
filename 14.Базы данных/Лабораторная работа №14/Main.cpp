#include "Function.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int stateMenu;
void Menu() {
	cout << "Выберите действие:" << endl
		<< "(0) Выход из программы." << endl
		<< "(1) Ввод данных." << endl
		<< "(2) Вывод данных." << endl
		<< "(3) Редактирование данных." << endl
		<< "(4) Удаление данных." << endl
		<< "(5) Добавление данных." << endl
		<< "(6) Сохранение данных." << endl;
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

			cout << "Ввод вручную или из файла?:";
			cin >> actions;
			system("cls");
			if (actions == 1) {
				DataEntry();
			}
			else {
				cout << "Введите название файла: ";
				cin >> fileName;
				DataReading(fileName);
			}

			system("pause");
			system("cls");
			Menu();
			break;
		case 2:
			system("cls");
			cout << "Вывести все,вывести по автору, вывести по году издания:";
			cin >> actions;
			if(actions==1)
			{
				Print(); 
			}
			if (actions == 2)
			{
				string aut;
				cout << "Введите автора:"; cin >> aut;
				Print_po_author(aut);
			}
			if(actions == 3) {
				int year;
				cout << "Введите год издания:"; cin >> year;
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
			cout << "Введите название файла:"; cin >> fileName;
			SaveData(fileName);
			system("pause");
			system("cls");
			Menu();
			break;
		default:
			cout << "Неправильно выбран пункт меню!" << endl;
			break;
		}
	}
	system("cls");
	if (DataCleaning())
		cout << "Данные очищены!" << endl;
	else
		cout << "Данные не очищенны!" << endl;
	system("pause");
}