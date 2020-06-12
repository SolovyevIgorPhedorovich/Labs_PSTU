#include "Tree.h"
#include <vector>

SGlutContextStruct (glutContext);

double generator() {
	double a = 0.1 + (double)(rand() % 100) / 10;
	return a;
}

bool sr(double a, double b) {
	if (fabs(a - b) <= 100*16*DBL_EPSILON * fmax(fabs(a), fabs(b)))
		return true;
	else return false;
}

int qued_x;
int qued_y;
int qued_text_x;
int qued_text_y;
int quad_width = 100;
int quad_height = 20;
bool cur = false;
bool b_find = false;
bool t_tree = false;
double min_tree;
double find_tree = -1;
vector<double> el;
vector<double>::iterator el_pos = el.begin();
vector<string>vec = {"Add","Remove","Find min", "Convert","Find"};
int xOrigin = -1, yOriginal=-1;

TREE* TREE::balanceTree(int n, TREE** p)
{
	TREE* tree;
	int nl, nr;
	double dt = generator();
	tree = *p;
	if (n == 0)* p = NULL;
	else {
		nl = n / 2;
		nr = n - nl - 1;
		tree = new (TREE);
		(*tree).data = dt;
		balanceTree(nl, &((*tree).Left));
		balanceTree(nr, &((*tree).Right));
		*p = tree;
	}
	return *p;
}

void TREE::setCoordsForNode(int window_width, int window_height, int shift, int tree_width, int tree_height, int x, int y, int R) {
	if (tree_width != tree_height) {
		int k_x = (window_width - 2 * (shift + R)) / (tree_width - 1);
		int k_y = (window_height - 2 * (shift + R)) / (tree_height - 1);
		node_x = (window_width - 2 * shift) * abs(2 * x - 1) / pow(2, y + 1) + shift;
		node_y = window_height - k_y * y - shift-R;
	}
	else
	{
		node_x = window_width / 2;
		node_y = window_height / 2;
	}
}

void TREE::setCoordsForText(int k, int R) {
	text_x = node_x - 3 * R / 4;
	text_y = node_y - 3 * R / (4 * k);
}

TREE* get_help(TREE* node, int x, int y, int R) {
	if (pow(x - node->node_x, 2) + pow(y - node->node_y, 2) <= pow(R, 2))
		return node;
	TREE* temp = NULL;
	if (node->Left != NULL)
		temp = get_help(node->Left, x, y, R);
	if (temp != NULL)
		return temp;
	if (node->Right != NULL)
		temp = get_help(node->Right, x, y, R);
	return temp;
}

TREE* TREE::getNodeByCoords(int x, int y, int R) {
	TREE* node = this;
	node = get_help(node, x, y, R);
	return node;
}

static void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutContext.window_width = w;
	glutContext.window_height = h;
	glutPostRedisplay();
}

static void drawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

static void drawFillCircle(int x, int y, int R)
{
	glColor3f(1.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POINTS);
	for (int i = 0; i <= R; i++) {
		for (int t = 0; t <= 360; t++) {
			x1 = i * sin(t) + x;
			y1 = i * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = R - 1; i <= R; i++) {
		for (int t = 0; t <= 360; t++) {
			x1 = R * sin(t) + x;
			y1 = R * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
}

static void drawBlueCircle(int x, int y, int R)
{
	glColor3f(0.0, 0.0, 1.0);
	float x1, y1;
	glBegin(GL_POINTS);
	for (int i = R - 1; i <= R; i++) {
		for (int t = 0; t <= 360; t++) {
			x1 = R * sin(t) + x;
			y1 = R * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
}

static void drawGreenCircle(int x, int y, int R) {
		glColor3f(0.0, 0.5, 0.0);
		float x1, y1;
		glBegin(GL_POINTS);
		for (int i = 0; i <= R; i++) {
			for (int t = 0; t <= 360; t++) {
				x1 = i * sin(t) + x;
				y1 = i * cos(t) + y;
				glVertex2f(x1, y1);
			}
		}
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POINTS);
		for (int i = R - 1; i <= R; i++) {
			for (int t = 0; t <= 360; t++) {
				x1 = R * sin(t) + x;
				y1 = R * cos(t) + y;
				glVertex2f(x1, y1);
			}
		}
		glEnd();
}

static void drawRedCircle(int x, int y, int R) {
	glColor3f(0.8, 0.0, 0.0);
	float x1, y1;
	glBegin(GL_POINTS);
	for (int i = 0; i <= R; i++) {
		for (int t = 0; t <= 360; t++) {
			x1 = i * sin(t) + x;
			y1 = i * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = R - 1; i <= R; i++) {
		for (int t = 0; t <= 360; t++) {
			x1 = R * sin(t) + x;
			y1 = R * cos(t) + y;
			glVertex2f(x1, y1);
		}
	}
	glEnd();
}

static void drawText(double text, void* font, int text_x, int text_y, int R, int k)
{
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(text_x, text_y, 0.0);
	string s = to_string(text);
	char* s1 = new char[s.size() + 1];
	for (int i = 0; i < s.size() - 5; i++)
		s1[i] = s.at(i);
	s1[s.size()] = 0;
	char* c;
	int max_char_width = 0;
	int char_width = 0;
	for (c = s1; *c != '\0'; c++) {
		char_width = glutStrokeWidth(font, *c);
		if(max_char_width < char_width) max_char_width = char_width;
	}
	float expand_x = (float)1.5 * R / (float)(k * max_char_width);
	float expand_y = (float)1.5 * R / (float)(k * 100);
	glScalef(expand_x, expand_y, 1.0);
	for (c = s1; *c != '\0'; c++)
		glutStrokeCharacter(font, *c);
	glPopMatrix();
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_UP) {
			xOrigin = x;
			yOriginal = y;
		}
	}
}

int getHeight(TREE* p) {
	int h1 = 0, h2 = 0;
	if (p == NULL)return 0;
	if (p->Left) { h1 = getHeight(p->Left); }
	if (p->Right) { h2 = getHeight(p->Right); }
	return (max(h1, h2) + 1);
}

TREE* TREE::replaceNULLforEmpty(TREE* temp, int level, int n) {
	if (t_tree == false) {
		TREE* node = temp;
		if (node == NULL) return NULL;
		if (node->Left != NULL && node->Right == NULL) {
			node->Right = new TREE(0);
		}
		if (node->Left == NULL && node->Right != NULL) {
			node->Left = new TREE(0);
		}
		node->Left = replaceNULLforEmpty(node->Left, level, n);
		node->Right = replaceNULLforEmpty(node->Right, level, n);
		return temp = node;
	}
	if (t_tree == true) {
		TREE* node = temp;
		if (node == NULL && n>=level) return NULL;
		if (node->Left != NULL && node->Right == NULL) {
			node->Right = new TREE(0);
		}
		if (node->Left == NULL && node->Right != NULL) {
			node->Left = new TREE(0);
		}
		if (node->Left == NULL && node->Right == NULL && n < level) {
			node->Left = new TREE(0);
			node->Right = new TREE(0);
		}
		node->Left = replaceNULLforEmpty(node->Left, level, ++n);
		node->Right = replaceNULLforEmpty(node->Right, level, ++n);
		return temp = node;
	}
}

TREE* TREE::deleteNULL(TREE* temp){
	TREE* tree = temp;
	if (tree == NULL) return NULL;
	if (tree->data == 0) {
		return NULL;
	}
	else
	{
		tree->Left = deleteNULL(tree->Left);
		tree->Right = deleteNULL(tree->Right);
		return temp = tree;
	}
		
}

TREE* TREE::rotateRight(TREE* p)
{
	TREE* q = p->Left;
	p->Left = q->Right;
	q->Right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

TREE* TREE::rotateLeft(TREE* q)
{
	TREE* p = q->Right;
	q->Right = p->Left;
	p->Left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

TREE* TREE::balance(TREE* p) {
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->Right) < 0)
			p->Right = rotateRight(p->Right);
		return rotateLeft(p);
	}
	if (bfactor(p) == 2)
	{
		if (bfactor(p->Left) > 0)
			p->Left = rotateLeft(p->Left);
		return rotateRight(p);
	}
	return p;
}

TREE* TREE::insertNode(TREE* p, double dt) {
	TREE* node = this;
	TREE* tree = p;
	if (p && tree->data == 0) {
		tree->data = dt;
		return p = tree;
	}
	else if(!p) {
		return node = new TREE(dt);
	}
	int x = rand()%2;
	if (x==1)
		p->Left = insertNode(p->Left, dt);
	else
		p->Right = insertNode(p->Right, dt);
	return balance(p);
}

TREE* TREE::findLeft(TREE* p)
{
	return p->Left ? findLeft(p->Left) : p;
}

TREE* TREE::removeMinLeft(TREE* p)
{
	if (p->Left == NULL)
		return p->Right;
	p->Left = removeMinLeft(p->Left);
	return balance(p);
}

TREE* TREE::delNode(TREE* p, double dt) {
	if (!p) return 0;
	if (sr(p->data,dt)!= true) {
		p->Left = delNode(p->Left, dt);
		p->Right = delNode(p->Right, dt);
	}
	else
	{
		TREE* nl = p->Left;
		TREE* nr = p->Right;
		delete p;
		if (!nr) return nl;
		TREE* m = findLeft(nr);
		m->Right = removeMinLeft(nr);
		m->Left = nl;
		return balance(m);
	}
	return balance(p);
}

TREE* TREE::balance_tree(TREE* p) {
	if (p == NULL) return NULL;
	p->Left = balance_tree(p->Left);
	p->Right = balance_tree(p->Right);
	return balance(p);
}

TREE* TREE::SearchTree(TREE** p, double n) {
	TREE* searchTree = *p;
	if (*p == NULL) {
		searchTree = new (TREE);
		searchTree->data = n;
		searchTree->Left = NULL;
		searchTree->Right = NULL;
		*p = searchTree;
		}
		else {
			if (n < searchTree->data)
				searchTree->Left = SearchTree(&((*searchTree).Left), n);
			else
				searchTree->Right = SearchTree(&((*searchTree).Right), n);
		}
	return *p;
}

TREE* TREE::convertTobalanceTree(TREE** p, int n, int i) {
	
	if (n == 0 ) return NULL;
	TREE* tree = *p;
	double dt = el[i];
	el.erase(el.begin() + i);
	int nr, nl;
	nl = n / 2;
	nr = n - nl - 1;
	tree = new TREE(dt);
	(*tree).Left = convertTobalanceTree(&((*tree).Left), nl, i);
	(*tree).Right = convertTobalanceTree(&((*tree).Right), nr, i);
	*p = tree;
	return *p;
	
}

TREE* TREE::insertNodeSearchTree(TREE* p, double dt) {
	TREE* tree = p;
	if (p == NULL) {
		tree = new TREE(dt);
		p = tree;
	}
	else if (p && tree->data == 0) {
		tree->data = dt;
		p = tree;
	}
	else {
		if (dt < tree->data)
			tree->Left = insertNodeSearchTree(tree->Left, dt);
		else
			tree->Right = insertNodeSearchTree(tree->Right, dt);
	}
	return p;
}

TREE* TREE::delSearchNode(TREE* p, double dt) {
	if (!p) return 0;
	if (dt < p->data)
		p->Left = delNode(p->Left, dt);
	else if (dt > p->data)
		p->Right = delNode(p->Right, dt);
	else {
		TREE* nl = p->Left;
		TREE* nr = p->Right;
		delete p;
		if (!nr) return nl;
		TREE* min = findLeft(nr);
		min->Right = removeMinLeft(nr);
		min->Left = nl;
	}
}

void TREE::findMinSearchTree(TREE*p) {
	TREE* l = p->Left;
	TREE* m = findLeft(l);
	min_tree = m->data;
}

void TREE::convertToSearchTree(TREE* p) {
	if (p == NULL) return;
	else {
		el.push_back(p->data);
		convertToSearchTree(p->Left);
		convertToSearchTree(p->Right);
	}
}

void TREE::findMin()
{
	double d = el[0];
	for (int i = 1; i < el.size(); i++) {
		if (d < el[i])
			min_tree = d;
		else {
			min_tree = el[i];
			d = el[i];
		}
	}
}

int getAmountNode(TREE* t, int n)
{
	if (t == NULL) return 0;
	else {
		n++;
		getAmountNode(t->Left, n);
		getAmountNode(t->Right, n);
		return n;
	}
}

void setCoordsForQuad(int window_width, int window_height, int shift, int quad_width, int quad_height, int y) {
	qued_x = shift+quad_width/2;
	qued_y = window_height - shift - quad_height* y;
	qued_text_x = qued_x;
	qued_text_y = qued_y;
}

string getHelp(string s, int t, int x, int y, int quad_width, int quad_height) {
	++t;
	if (pow(x - qued_x, 2) + pow(y - qued_y, 2) <= pow(quad_width, 2) + pow(quad_width, 2)) return s;
	if (t <= 5) return "";
	getHelp(vec[t], t, x, y, quad_width, quad_height);
}

string getQuadByCoords(int x, int y, int quad_width, int quad_height) {
	int t = 0;
	string str = vec[t];
	str = getHelp(str, t, x, y, quad_width, quad_height);
	return str;
}

void draw_string_bitmap(void* font, const char* string) {
	while (*string)
	{
		glutBitmapCharacter(font, *string++);
	}
}

void drawQuad(int left, int right, int bottom, int top) {
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2i(left, bottom);
	glVertex2i(left, top);
	glVertex2i(right, top);
	glVertex2i(right, bottom);
	glEnd;
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	drawLine(left, bottom, left, top);
	drawLine(left, top, right, top);
	drawLine(right, top, right, bottom);
	drawLine(right, bottom, left, bottom);
	drawLine(left, top, left, bottom);
	glEnd;
}

static void mouseMove(int x, int y) {
	TREE* tree = (TREE*)glutContext.tree;
	int R = glutContext.R;
	TREE* node = tree->getNodeByCoords(x, glutContext.window_height - y, R);
	if (node != NULL) {
		glutContext.x = x;
		glutContext.y = glutContext.window_height - y;
		glutContext.state = 1;
		glutPostRedisplay();
	}
	else {
		glutContext.state = 0;
		glutPostRedisplay();
	}
}

void Buttom_1(int window_width,int window_height,int shift, int quad_width, int quad_height, int k, TREE* tree)
{
	setCoordsForQuad(window_width, window_height,shift,quad_width,quad_height, 1);
	string str = vec[0];
	drawQuad(qued_x - quad_width / 2, qued_x + quad_width / 2, qued_y - quad_height, qued_y + quad_height / 2);
	glRasterPos2d(qued_x - 20, qued_y-12);
	draw_string_bitmap(GLUT_BITMAP_TIMES_ROMAN_24, "Add");
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (t_tree == false) {
			double dt;
			tree->deleteNULL(tree);
			cout << "Введите значение:"; cin >> dt;
			tree->insertNode(tree, dt);
			cout << "Add complet" << endl;
			tree->replaceNULLforEmpty(tree, getHeight(tree),0);
			glutContext.tree = tree;
			if (dt < min_tree) min_tree = dt;
			xOrigin = -1;
			yOriginal = -1;
		}
		if (t_tree == true) {
			double dt;
			cout << "Введите значение:"; cin >> dt;
			tree->deleteNULL(tree);
			tree->insertNodeSearchTree(tree, dt);
			cout << "Add complet" << endl;
			tree->replaceNULLforEmpty(tree, getHeight(tree),0);
			glutContext.tree = tree;
			if (dt < min_tree) min_tree = dt;
			xOrigin = -1;
			yOriginal = -1;
		}
	}
}
void Buttom_2(int window_width, int window_height, int shift, int quad_width, int quad_height, int k, TREE* tree)
{
	setCoordsForQuad(window_width, window_height, shift, quad_width, quad_height, 3);
	string str = vec[1];
	drawQuad(qued_x - quad_width / 2, qued_x + quad_width / 2, qued_y - quad_height, qued_y + quad_height / 2);
	glRasterPos2d(qued_x-40, qued_y-12);
	draw_string_bitmap(GLUT_BITMAP_TIMES_ROMAN_24, "Remove");
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (t_tree == false) {
			double dt;
			cout << "Введите значение:"; cin >> dt;
			tree->delNode(tree, dt);
			tree->replaceNULLforEmpty(tree, getHeight(tree),0);
			el.clear();
			tree->convertToSearchTree(tree);
			tree->findMin();
			cout << "Remove complete" << endl;
			glutContext.tree = tree;
			xOrigin = -1;
			yOriginal = -1;
		}
		if (t_tree == true) {
			double dt;
			cout << "Введите значение:"; cin >> dt;
			tree->deleteNULL(tree);
			tree->delSearchNode(tree, dt);
			tree->replaceNULLforEmpty(tree, getHeight(tree),0);
			el.clear();
			tree->convertToSearchTree(tree);
			tree->findMin();
			cout << "Remove complete" << endl;
			glutContext.tree = tree;
			xOrigin = -1;
			yOriginal = -1;
		}
	}
}
void Buttom_3(int window_width, int window_height, int shift, int quad_width, int quad_height, int k,TREE* tree)
{
	setCoordsForQuad(window_width, window_height, shift, quad_width, quad_height, 5);
	string str = vec[2];
	drawQuad(qued_x - quad_width / 2, qued_x + quad_width / 2, qued_y - quad_height, qued_y + quad_height / 2);
	glRasterPos2d(qued_x-45, qued_y-12);
	draw_string_bitmap(GLUT_BITMAP_TIMES_ROMAN_24, "Find min");
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (t_tree == false && cur == true) {
			cur = false;
			xOrigin = -1;
			yOriginal = -1;
		}
	}
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (t_tree == true && cur == false) {
			cur = true;
			tree->deleteNULL(tree);
			tree->findMinSearchTree(tree);
			tree->replaceNULLforEmpty(tree, getHeight(tree), 0);
			xOrigin = -1;
			yOriginal = -1;
		}
	}
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (t_tree == false && cur == false) {
			cur = true;
			tree->deleteNULL(tree);
			el.clear();
			tree->convertToSearchTree(tree);
			tree->findMin();
			tree->replaceNULLforEmpty(tree, getHeight(tree), 0);
			xOrigin = -1;
			yOriginal = -1;
		}
	}
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (t_tree == true && cur == true) {
			cur = false;
			xOrigin = -1;
			yOriginal = -1;
		}
	}
}
void Buttom_4(int window_width, int window_height, int shift, int quad_width, int quad_height, int k, TREE* tree)
{
	setCoordsForQuad(window_width, window_height, shift, quad_width, quad_height, 7);
	string str = vec[3];
	drawQuad(qued_x - quad_width / 2, qued_x + quad_width / 2, qued_y - quad_height, qued_y + quad_height / 2);
	glRasterPos2d(qued_x-40, qued_y-12);
	draw_string_bitmap(GLUT_BITMAP_TIMES_ROMAN_24, "Convert");
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (t_tree == true) {
			TREE B;
			t_tree = false;
			tree->deleteNULL(tree);
			tree->convertToSearchTree(tree);
			tree = B.convertTobalanceTree(B.GetParent(), el.size(), 0);
			el.clear();
			tree->replaceNULLforEmpty(tree, getHeight(tree),0);
			glutContext.tree = tree;
			cout << "Convert complet" << endl;
			xOrigin = -1;
			yOriginal = -1;
		}
	}
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (t_tree == false) {
			TREE B;
			t_tree = true;
			double n;
			el.clear();
			tree->deleteNULL(tree);
			tree->convertToSearchTree(tree);
			for (int i = 0; i < el.size(); i++)
			{
				n = el[i];
				tree = B.SearchTree(B.GetParent(), n);
			}
			el.clear();
			tree->replaceNULLforEmpty(tree, getHeight(tree), 0);
			glutContext.tree = tree;
			cout << "Convert complet" << endl;
			xOrigin = -1;
			yOriginal = -1;
		}
	}
}
void Buttom_5(int window_width, int window_height, int shift, int quad_width, int quad_height, int k)
{
	setCoordsForQuad(window_width, window_height, shift, quad_width, quad_height, 9);
	string str = vec[4];
	drawQuad(qued_x - quad_width / 2, qued_x + quad_width / 2, qued_y - quad_height, qued_y + quad_height / 2);
	glRasterPos2d(qued_x-23, qued_y-12);
	draw_string_bitmap(GLUT_BITMAP_TIMES_ROMAN_24, "Find");
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height - yOriginal >= qued_y - quad_height && window_height - yOriginal <= qued_y + quad_height / 2) {
		if (b_find == true) {
			b_find = false;
			xOrigin = -1;
			yOriginal = -1; }
	}
	if (xOrigin >= qued_x - quad_width / 2 && xOrigin <= qued_x + quad_width / 2 && window_height-yOriginal >= qued_y - quad_height && window_height-yOriginal <= qued_y + quad_height / 2){
		if (b_find == false) {
			b_find = true;
			cout << "Введите значение элементов:"; cin >> find_tree;
			xOrigin = -1;
			yOriginal = -1;
		}
	}
}

void display(void) {
	TREE* tree = (TREE*)glutContext.tree;
	int k = glutContext.k;
	int window_width = glutContext.window_width;
	int window_height = glutContext.window_height;
	int shift = glutContext.shift;
	int height = getHeight(tree);
	int maxLeafs = pow(2, height - 1);
	int width = 2 * maxLeafs - 1;
	int curLevel = 0;
	int index = 0;
	int quad_width = window_width / 15;
	int quad_height = window_height / 50;
	vector<TREE*> V;
	int R;
	R = (window_width - 4 * shift);
	if (2 * R * height > (window_height - 2 * shift)) R = (window_height - 4 * shift) / (4 * height);
	glutContext.R = R;
	tree->setCoordsForNode(window_width, window_height, shift, width, height, index, curLevel, R);
	V.push_back(tree);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glEnable(GL_POINT_SMOOTH);
	Buttom_1(window_width, window_height, shift, 100, 20, k, tree);
	Buttom_2(window_width, window_height, shift, 100, 20, k, tree);
	Buttom_3(window_width, window_height, shift, 100, 20, k, tree);
	Buttom_4(window_width, window_height, shift, 100, 20, k, tree);
	Buttom_5(window_width, window_height, shift, 100, 20, k);
	for (int i = 0; i < V.size(); i++) {
		if (pow(2, curLevel) <= index + 1) {
			index = 0;
			curLevel++;
		}
		if (V.at(i)->Left != NULL) {
			V.push_back(V.at(i)->Left);
			index++;
			V.at(i)->Left->setCoordsForNode(window_width, window_height, shift, width, height, index, curLevel, R);
			if (V.at(i)->Left->data != NULL) {
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->Left->node_x;
				int y2 = V.at(i)->Left->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}
		if (V.at(i)->Left == NULL && curLevel < height) {
			index++;
		}
		if (V.at(i)->Right != NULL) {
			V.push_back(V.at(i)->Right);
			index++;
			V.at(i)->Right->setCoordsForNode(window_width, window_height, shift, width, height, index, curLevel, R);
			if (V.at(i)->Right->data != NULL) {
				int x1 = V.at(i)->node_x;
				int y1 = V.at(i)->node_y;
				int x2 = V.at(i)->Right->node_x;
				int y2 = V.at(i)->Right->node_y;
				drawLine(x1, y1, x2, y2);
			}
		}
		if (V.at(i)->Right == NULL && curLevel < height) {
			index++;
		}
		if (V.at(i)->data != NULL) {
			if (glutContext.state == 0) {
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				if (b_find == true && cur == true) {
					if (sr(V.at(i)->data,find_tree) == true && sr(V.at(i)->data,min_tree)==true) drawRedCircle(V.at(i)->node_x, V.at(i)->node_y, R);
					else {
						if (sr(V.at(i)->data, min_tree == true)) drawGreenCircle(V.at(i)->node_x, V.at(i)->node_y, R);
						if (sr(V.at(i)->data, find_tree == true)) drawGreenCircle(V.at(i)->node_x, V.at(i)->node_y, R);
					}
				}
				if (cur == true && b_find == false) {
					if (sr(V.at(i)->data, min_tree) ==true) drawGreenCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				}
				if (b_find == true && cur == false) {
					if (sr(V.at(i)->data, find_tree) == true) drawGreenCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				}
			}
			else {
				drawFillCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				if (b_find == true && cur == true) {
					if (V.at(i)->data == find_tree && V.at(i)->data == min_tree) drawRedCircle(V.at(i)->node_x, V.at(i)->node_y, R);
					else {
						if (sr(V.at(i)->data, min_tree) == true) drawGreenCircle(V.at(i)->node_x, V.at(i)->node_y, R);
						if (sr(V.at(i)->data, find_tree) == true) drawGreenCircle(V.at(i)->node_x, V.at(i)->node_y, R);
					}
				}
				if (cur == true && b_find == false) {
					if (sr(V.at(i)->data, min_tree) == true) drawGreenCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				}
				if (b_find == true && cur == false) {
					if (sr(V.at(i)->data, find_tree) == true) drawGreenCircle(V.at(i)->node_x, V.at(i)->node_y, R);
				}
				if ((tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_x == V.at(i)->node_x) & (tree->getNodeByCoords(glutContext.x, glutContext.y, R)->node_y == V.at(i)->node_y)) drawBlueCircle(V.at(i)->node_x, V.at(i)->node_y, R);
			}
			V.at(i)->setCoordsForText(k, R);
			drawText(V.at(i)->data, GLUT_STROKE_ROMAN, V.at(i)->text_x, V.at(i)->text_y, R, k);
		}
	}
	
	glutSwapBuffers();
	glDisable(GL_POINT_SMOOTH);
}

void initWindow(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(glutContext.window_width, glutContext.window_height);
	glutCreateWindow("DrawTree");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseButton);
	glutPassiveMotionFunc(mouseMove);
	glutMainLoop();
}

void TREE::drawTree(int argc, char** argv, int window_width, int window_height, int shift, int k, TREE* root)
{
	TREE* temp = copyTree(root);
	temp->convertToSearchTree(temp);
	temp->findMin();
	glutContext.tree = temp;
	glutContext.window_width = window_width;
	glutContext.window_height = window_height;
	glutContext.shift = shift;
	glutContext.k = k;
	initWindow(argc, argv);
}