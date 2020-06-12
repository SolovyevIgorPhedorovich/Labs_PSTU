#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <GL/glut.h>

using namespace std;

struct SGlutContextStruct
{
	void* tree;
	int window_width, window_height, shift, k, R, x, y, state;
};


class TREE
{
public:
	TREE():parent(0), Left(0), Right(0), data(-1) {}
	TREE(double root) : parent(0), Left(0), Right(0), data(root) {}
	~TREE() { DestroyNode(parent); }
	TREE** GetParent() { return &parent; }
	TREE* GetData() { return parent; }
	TREE* balanceTree(int, TREE**);
	TREE* balance(TREE*);
	TREE* balance_tree(TREE*);
	TREE* rotateRight(TREE* p);
	TREE* rotateLeft(TREE* q);
	TREE* findLeft(TREE* p);
	void setData(double dt) { data = dt; }
	TREE* delNode(TREE*, double);
	TREE* delSearchNode(TREE*, double);
	void findMin();
	void findMinSearchTree(TREE*);
	void convertToSearchTree(TREE*);
	TREE* SearchTree(TREE**, double);
	void deleteTree() { delete this; }
	TREE* removeMinLeft(TREE*);
	TREE* insertNode(TREE*,double);
	TREE* insertNodeSearchTree(TREE*, double);
	TREE* copyTree(TREE* p) {
		if (p == NULL) return NULL;
		TREE* node = new TREE(p->data);
		node->Left = copyTree(p->Left);
		node->Right = copyTree(p->Right);
		return node;
	}
	TREE* replaceNULLforEmpty(TREE*, int, int);
	TREE* deleteNULL(TREE*);
	TREE* convertTobalanceTree(TREE**,int , int);
public:
	void setCoordsForNode(int window_width, int window_height, int shift, int tree_width, int tree_height, int x, int y, int R);
	TREE* getNodeByCoords(int x, int y, int R);
	void setCoordsForText(int k, int shift);
	void drawTree(int argc, char** argv, int window_widtht, int window_height, int shift, int k, TREE* root);
public:
	double data;
	TREE* Left = nullptr;
	TREE* Right = nullptr;
	TREE* parent;
	unsigned char height_tree;
	int node_x;
	int node_y;
	int text_x;
	int text_y;
private:
	static void DestroyNode(TREE* node) {
		if (node) {
			DestroyNode(node->Left);
			DestroyNode(node->Right);
		}
	}
	double y;
public:
	/*TREE* replaceNULLforEmpty() {};*/
	unsigned char height(TREE* p) {
		return p ? p->height_tree : 0;
	}
	int bfactor(TREE* p)
	{
		return height(p->Right) - height(p->Left);
	}
	void fixheight(TREE* p)
	{
		unsigned char hl = height(p->Left);
		unsigned char hr = height(p->Right);
		p->height_tree = (hl > hr ? hl : hr) + 1;
	}
};
