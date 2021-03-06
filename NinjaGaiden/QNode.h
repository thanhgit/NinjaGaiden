#ifndef QNODE_H
#define QNODE_H
#include<iostream>
#include"QRegion.h"
#include<math.h>
using namespace std;
class QNode
{
public:
	QNode(string nodeId, int level, int x, int y, int width, int heigh, std::list<Object*> objs);
	~QNode();

	void split();

	int getLevelQuadtree()
	{
		int result = this->level;
		if (this->node1 != nullptr)
		{
			int _level = this->node1->getLevelQuadtree();
			if (_level > result)
			{
				result = _level;
			}
		}

		if (this->node2 != nullptr)
		{
			int _level = this->node2->getLevelQuadtree();
			if (_level > result)
			{
				result = _level;
			}
		}

		if (this->node3 != nullptr)
		{
			int _level = this->node3->getLevelQuadtree();
			if (_level > result)
			{
				result = _level;
			}
		}

		if (this->node4 != nullptr)
		{
			int _level = this->node4->getLevelQuadtree();
			if (_level > result)
			{
				result = _level;
			}
		}

		return result;
	}

	bool containCamera(int x, int y, int width, int height) {
		if (abs(x - this->getRegion()->getX()) < width) {
			return true;
		}
		else {
			return false;
		}
	}
#pragma region Get Set
	QNode* getNode1() {
		return this->node1;
	}

	QNode* getNode2() {
		return this->node2;
	}

	QNode* getNode3() {
		return this->node3;
	}

	QNode* getNode4() {
		return this->node4;
	}

	string getNodeId() {
		return this->nodeId;
	}

	void setNodeId(string nodeId) {
		this->nodeId = nodeId;
	}

	int getLevel() {
		return this->level;
	}

	void setLevel(int level) {
		this->level = level;
	}

	QRegion* getRegion() {
		return this->region;
	}

	void setRegion(QRegion* region) {
		this->region = region;
	}
#pragma endregion

private:
	QNode* node1;
	QNode* node2;
	QNode* node3;
	QNode* node4;

	string nodeId;
	int level;

	QRegion* region;
};


#endif // !QNODE_H
