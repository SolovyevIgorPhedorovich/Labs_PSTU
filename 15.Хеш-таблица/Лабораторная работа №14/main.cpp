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
	cout << "Выберите действие:" << endl
		<< "(0) Выход из программы." << endl
		<< "(1) Создание таблицы данных." << endl
		<< "(2) Вывод таблицы." << endl
		<< "(3) Поис в таблице." << endl
		<< "(4) Добавление данных в таблицу." << endl
		<< "(5) Удаление данных из таблицы." << endl;
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
	cout << "Введите размер таблицы:"; cin >> size;
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
			cout << "Вывод:" << endl;
			hash->print(0);
			system("pause");
			system("cls");
			Menu();
			break;
		case 3:
			system("cls");
			cout << "Введите №паспорта:"; cin >> p;
			hash->find(p);
			system("pause");
			system("cls");
			Menu();
			break;
		case 4:
			system("cls");
			cout << "Введите Фамилию:И.О"; cin >> sur;
			cout << "Введите Имя: "; cin >> na;
			cout << "Введите Очество: "; cin >> patr;
			nam = sur + na + patr;
			cout << "Введите Nпаспорта"; cin >> pasport;
			cout << "Введите адоес"; cin >> adr;
			hash->insert(pasport, nam, adr);
			system("pause");
			system("cls");
			Menu();
			break;
		case 5:
			system("cls");
			cout << "Введите № паспорта"; cin >> pasport;
			hash->del(pasport);
			system("pause");
			system("cls");
			Menu();
			break; 
		default:
			cout << "Неправильно выбран пункт меню!" << endl;
			break;

		}
	}
	system("pause");
}