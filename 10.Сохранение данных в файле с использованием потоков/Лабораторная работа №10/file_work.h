#pragma once
#include"Time.h"
#include <iostream>
#include <fstream>

using namespace std;
int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)return -1;
	int n;
	Time t;
	cout << "N?"; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		stream << t << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name) {
	fstream stream(f_name, ios::in);
	if (!stream)return-1;
	Time t;
	int i = 0;
	while (stream >> t) {
		cout << t << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, Time k1, Time k2) {
	fstream temp1("temp1", ios::out);
	fstream temp2("temp2", ios::out);
	fstream stream1(f_name, ios::in);
	fstream stream2(f_name, ios::in);
	fstream stream3(f_name, ios::in);
	if (!stream1)return -1;
	int i = 0, n = 0, x = 0;
	int l = 0, a = 0 ;
	Time t, t1 , t2,t3;
	
	while (stream1 >> t) {
		if (stream1.eof())break;
		i++;
		if (t == k1) {
			l = i;
		};
		if (t == k2) {
			a = i;
		}
	}

	while (stream2 >> t1) {
		if (stream2.eof())break;
		n++;
		if (n < l)
			temp1 << t1 << "\n";
	}

	while ( stream3 >> t2)
	{
		if (stream3.eof())break;
		x++;
		if (x > a)
			temp2 << t2 << "\n";
	}

	temp1.close();
	temp2.close();
	fstream temp3("temp1", ios::app);
	fstream temp4("temp2", ios::in);
	if (!temp4)return -1;
	while (temp4 >> t3) {
		if (temp4.eof())break;
		temp3 << t3 << "\n";
	}
	temp3.close();
	temp4.close();
	stream1.close();
	stream2.close();
	stream3.close();
	remove(f_name);
	remove("temp2");
	rename("temp1", f_name);
	return i;
}

int add_file(const char* f_name, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Time t, t1; int i = 0, l = 0;
	while (stream >> t)
	{
		if (stream.eof())break;
		i++;
		if (i == 1)
		{
			temp << tt;
			l++;
		}
		temp << t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}



int chang_file(const char* f_name,  Time tt)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t; int i = 0;
	char x;
	while (stream >> t) {
		if (stream.eof()) break;
		if (t == tt)
		{
			cout << t << " - is changing... Continue [y/n]?\n";
			cin >> x;
			if (x == 'n' || x == 'N')break;
			for (int i = 0; i < 90; i++)
				++t;
			temp << t;
			i++;
		}
		else temp << t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
