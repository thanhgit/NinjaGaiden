#ifndef QREGION_H
#define QREGION_H
#include<list>
#include"Object.h"
#include"Utils.h"
class QRegion
{
public:
	QRegion(int x, int y, int width, int height);
	~QRegion();

	bool IsContain(Object* _obj, int x, int y, int width, int height) {
		Box* obj = _obj->GetBody();
		bool result = false;

		bool check_x = obj->GetX() >= x && obj->GetX() < (x + width);
		bool check_y = obj->GetY() >= y && obj->GetY() < (y + height);

		if (check_x && check_y)
		{
			result = true;
		}

		return result;
	}
	bool IsSplit() {
		if (this->objs.size() > 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int ObjsSize() {
		return this->objs.size();
	}
	QUADTREE_NODE getNumberNodeWhenSplit(Object* obj);
#pragma region Get Set
	int getX() {
		return this->x;
	}

	void setX(int x) {
		this->x = x;
	}

	int getY() {
		return this->y;
	}

	void setY(int y) {
		this->y = y;
	}

	int getWidth() {
		return this->width;
	}

	void setWidth(int width) {
		this->width = width;
	}

	int getHeight() {
		return this->height;
	}

	void setHeight(int height) {
		this->height = height;
	}

	std::list<Object*> getObjs() {
		return this->objs;
	}

	void setObjes(std::list<Object*> objs) {
		for (auto obj : objs) {
			this->objs.push_back(obj);
		}
	}
#pragma endregion

private:
	int x, y;
	int width, height;
	std::list<Object*> objs;
};


#endif // !QREGION_H
