#include<stdio.h>
#include<iostream>
#include"Object.h"
#include"QNode.h"

using namespace std;

void quadtreetest() {
	std::list<Object*> objs;
	objs.push_back(new Object(240, 128, 25, 41, 0, 0));
	objs.push_back(new Object(289, 130, 25, 41, 0, 0));
	objs.push_back(new Object(337, 128, 25, 41, 0, 0));
	objs.push_back(new Object(433, 128, 25, 41, 0, 0));
	objs.push_back(new Object(215, 144, 32, 17, 0, 0));
	objs.push_back(new Object(556, 62, 17, 25, 0, 0));
	objs.push_back(new Object(715, 65, 17, 25, 0, 0));
	objs.push_back(new Object(623, 134, 17, 14, 0, 0));
	objs.push_back(new Object(799, 93, 25, 43, 0, 0));
	objs.push_back(new Object(902, 84, 32, 17, 0, 0));
	objs.push_back(new Object(905, 87, 32, 17, 0, 0));

	QNode* root = new QNode("1", 0, 0, 0, 2050, 2050, objs);
	int level = root->getLevelQuadtree();
	cout << "Level of quad tree is " << level << endl;
}

int main() {
	cout << "----------------Tester quadtree ------------------\n";

	quadtreetest();

	cout << "\n-----------" << endl;
	system("pause");
	return 0;
}