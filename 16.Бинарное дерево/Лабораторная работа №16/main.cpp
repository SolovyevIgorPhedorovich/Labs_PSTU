#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <time.h>
#include <vector>
#include "Tree.h"

using namespace std;
typedef vector<double> vec;
int window_width = 800;
int window_height = 600;
int shift = 10;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Ru");
	srand(time(0));

	TREE A;
	int n;
	cout << "¬ведите колличество эллементов: "; cin >> n;
	A.balanceTree(n,A.GetParent());
	A.drawTree(argc, argv, window_width, window_height, shift, 3, A.GetData());
}