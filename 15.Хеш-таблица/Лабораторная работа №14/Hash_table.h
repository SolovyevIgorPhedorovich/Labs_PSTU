#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
#define DEFAULT 100

using namespace std;

class Node {
	friend class Hash_Table;
	Node* next;
	string name;
	string pasport;
	string adres;
public:
	Node() { }
	Node(string d, string na, string a, Node* n)
	{
		name = na;
		pasport = d;
		adres = a;
		next = n;
	}
	~Node() {};
};

class Hash_Table
{
	static int hash(string key, int tableSize)
	{
		int k = 0;
		for (int i = 0; i < key.length(); i++) {
			k += key[i];
		}
		int h = tableSize * (fmod(k * 0.618033, 1));
		return h;
	}
private: vector<Node*>* Nodes;
public:
	int size;
	Hash_Table(int tableSize) {
		size = tableSize;
		Nodes = new vector<Node*> (size);
	}

	Hash_Table() {
		size = DEFAULT;
		Nodes = new vector<Node*>(size);
	}

	~Hash_Table()
	{
		delete[] Nodes;
	}

	int collisions_count() const
	{
		int result = 0;

		for (int i = 0; i < size; ++i)
			if (Nodes[i].size() > 1)
				++result;

		return result;
	}
	void insert(string key, string n, string a)
	{
		int index = hash(key, getSize());
		if (Nodes->at(index) == NULL) {
			Nodes->at(index) = new Node(key, n, a, NULL);
			return;
		}
		Node* p = Nodes->at(hash(key, getSize()));
		while (p != NULL) {
			if (p->next == NULL) {
				p->next = new Node(key, n, a, NULL);
				break;
			}
			p = p->next;
		}
	}


	int getSize()
	{
		return size;
	}
	

	void del(string pasport) {
		int index = hash(pasport, getSize());
		for (Node** pos = &Nodes->at(hash(pasport, getSize())); pos; pos = &(*pos)->next)
		{
			if ((*pos)->pasport == pasport)
			{
				*pos = (*pos)->next;
				return;
			}
			else {
				cout << "Element not found" << endl;
			}
		}
	}

	void find(string pasport)
	{
		for (Node* pos = Nodes->at(hash(pasport, getSize())); pos; pos = pos->next)
		{
			if (pos->pasport == pasport) {
				cout << pos->name << endl;
				cout << pos->pasport << endl;
				cout << pos->adres << endl;
			}
			else
			{
				cout << "Elemen not found." << endl;

			}
		}
	}
	
	void print(int start)
	{
		int lineCount = 0;
		for (int i = start; i < Nodes->size(); i++) {
			cout << i << "\t";
			Node* p = Nodes->at(i);
			while (p != NULL) {
				cout <<"\n"<< p->name << endl;
				cout << p->pasport << endl;
				cout << p->adres << " "<<endl;
				p = p->next;
			}
			cout << endl;
		}
		cout <<"Колличество колизий = "<< collisions_count();
	}
};