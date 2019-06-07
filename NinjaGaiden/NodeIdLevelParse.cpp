#include"NodeIdLevelParse.h"
#include<vector>

NodeIdLevelParse::NodeIdLevelParse(string line, QNode* node):QParse(node)
{
	vector<string> strs = split(line);
	this->node->setNodeId(strs.at(0));
	this->node->setLevel(std::atoi(strs.at(1).c_str()));
}

NodeIdLevelParse::~NodeIdLevelParse()
{
}
