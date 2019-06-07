#ifndef NODEID_LEVEL_PARSE_H
#define NODEID_LEVEL_PARSE_H
#include"QParse.h"

class NodeIdLevelParse: public QParse
{
public:
	NodeIdLevelParse(string line, QNode* node);
	~NodeIdLevelParse();
private:

};

#endif // !NODEID_LEVEL_PARSE_H
