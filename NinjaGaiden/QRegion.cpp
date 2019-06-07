#include"QRegion.h"

QRegion::QRegion(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

QRegion::~QRegion()
{
}

QUADTREE_NODE QRegion::getNumberNodeWhenSplit(Object* obj) {
	if (IsContain(obj, x, y, width / 2, height / 2))
	{
		return NODE1;
	}
	else if (IsContain(obj, x + width / 2, y, width / 2, height / 2))
	{
		return NODE2;
	}
	else if (IsContain(obj, x, y + height / 2, width / 2, height / 2))
	{
		return NODE3;
	}
	else
	{
		return NODE4;
	}
}