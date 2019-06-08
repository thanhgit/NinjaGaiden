#include<stdio.h>
#include<iostream>
#include"Object.h"
#include"QNode.h"
#include"Collision.h"

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

void AABBCheckTest() {
	Box* box = new Box(0, 0, 10, 10, 5, 0);
	Box* box1 = new Box(20, 0, 10, 10, 0, 0);

	bool check = box->AABBCheck(*box1);

	if (check) {
		cout << "Available" << endl;
	}
	else {
		cout << "Not available" << endl;
	}
}

void SweptAABBTest() {
	Box* box = new Box(0, 0, 10, 10, 0, 0);
	Box* box1 = new Box(0, 20, 10, 10,0, -30);
	float normalx = 0.0f;
	float normaly = 0.0f;
	float check = box1->SweptAABB(*box, normalx, normaly);

	
	if (check != 1.0f) {
		cout << "Available" << endl;

		if (normalx == 0.0f && normaly == 1.0f) {
			cout << "down" << endl;
		}
		else if (normalx == 0.0f && normaly == -1.0f) {
			cout << "up" << endl;
		}
		else if (normaly == 0.0f && normalx == 1.0f) {
			cout << "left" << endl;
		}
		else if (normaly == 0.0f && normalx == -1.0f) {
			cout << "right" << endl;
		}


		Collision* collision = new Collision(box1);
		collision->collision(box);

		switch (collision->GetDirection())
		{
		case RIGHT:
			cout << "right" << endl;
			break;
		case LEFT:
			cout << "left" << endl;
			break;
		case UP:
			cout << "up" << endl;
			break;
		case DOWN:
			cout << "down" << endl;
			break;
		default:
			cout << "none" << endl;
			break;
		}
	}else {
		cout << "Not available" << endl;
	}
}
int main() {
	cout << "----------------Tester quadtree ------------------\n";

	//quadtreetest();
	//AABBCheckTest();
	SweptAABBTest();
	cout << "\n-----------" << endl;
	system("pause");
	return 0;
}