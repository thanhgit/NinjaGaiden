#ifndef QPARSE_H
#define QPARSE_H
#include"QNode.h"

#include"SwordMan.h"
#include"Dog.h"
#include"Runner.h"
#include"Bird.h"
#include"MachineGunGuy.h"
#include"MachineGunGuySit.h"
#include"ItemContainer4.h"
#include"BirdBrown.h"
#include"BatBrown.h"
#include"Banshee.h"
#include"Boss3.h"

#include<iostream>
#include<vector>
using namespace std;

class QParse
{
public:
	QParse(QNode* node);
	~QParse();

	QNode* getQNode() {
		return this->node;
	}

	PARSE_TYPE getParseType(string line) {
		vector<string> strs = split(line);
		switch (strs.size())
		{
		case 2:
			return NODEID_LEVEL_PARSE;
		case 4:
			return REGION_PARSE;
		default:
			return OBJECT_GAME_PARSE;
		}
	}
protected:
	QNode* node;

	vector<string> split(string line) {
		size_t pos = 0;
		std::string token;
		string delimiter = " ";
		vector<string> results;
		while ((pos = line.find(" ")) != std::string::npos) {
			token = line.substr(0, pos);
			results.push_back(token);
			line.erase(0, pos + delimiter.length());
		}

		results.push_back(line);

		return results;
	}

	
};

#endif // !QPARSE_H
