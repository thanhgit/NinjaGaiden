#include"QNode.h"

QNode::QNode(string nodeId, int level, int x, int y, int width, int height, std::list<Object*> objs)
{
	this->nodeId = nodeId;
	this->level = level;
	this->region = new QRegion(x, y, width, height);
	this->region->setObjes(objs);

	if (this->region->IsSplit()) {
		split();
	}
}

QNode::~QNode()
{
}

void QNode::split() {
	this->node1 = nullptr;
	this->node2 = nullptr;
	this->node3 = nullptr;
	this->node4 = nullptr;

	std::list<Object*> objNode1;
	std::list<Object*> objNode2;
	std::list<Object*> objNode3;
	std::list<Object*> objNode4;
	for (auto obj : this->region->getObjs()) {
		switch (region->getNumberNodeWhenSplit(obj))
		{
		case NODE1:
			objNode1.push_back(obj);
			break;
		case NODE2:
			objNode2.push_back(obj);
			break;
		case NODE3:
			objNode3.push_back(obj);
			break;
		case NODE4:
			objNode4.push_back(obj);
			break;
		}
	}

	if (objNode1.size() > 0)
	{
		this->node1 = new QNode(this->nodeId + "1", this->level + 1, this->region->getX(), this->region->getY(), this->region->getWidth() / 2, this->region->getHeight() / 2, objNode1);
	}

	if (objNode2.size() > 0)
	{
		this->node2 = new QNode(this->nodeId + "2", this->level + 1, this->region->getX() + this->region->getWidth() / 2, this->region->getY(), this->region->getWidth() / 2, this->region->getHeight() / 2, objNode2);
	}

	if (objNode3.size() > 0)
	{
		this->node3 = new QNode(this->nodeId + "3", this->level + 1, this->region->getX(), this->region->getY() + this->region->getHeight() / 2, this->region->getWidth() / 2, this->region->getHeight() / 2, objNode3);

	}

	if (objNode4.size() > 0)
	{
		this->node4 = new QNode(this->nodeId + "4", this->level + 1, this->region->getX() + this->region->getWidth() / 2, this->region->getY() + this->region->getHeight() / 2, this->region->getWidth() / 2, this->region->getHeight() / 2, objNode1);
	}
}