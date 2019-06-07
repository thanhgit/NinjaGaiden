#include"RegionParse.h"

RegionParse::RegionParse(string line, QNode * node): QParse(node)
{
	vector<string> strs = split(line);
	this->node->getRegion()->setX(std::atoi(strs.at(0).c_str()));
	this->node->getRegion()->setY(std::atoi(strs.at(1).c_str()));
	this->node->getRegion()->setWidth(std::atoi(strs.at(2).c_str()));
	this->node->getRegion()->setHeight(std::atoi(strs.at(3).c_str()));
}

RegionParse::~RegionParse()
{
}
