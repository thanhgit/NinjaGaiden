#ifndef OBJECT_GAME_PARSE_H
#define OBJECT_GAME_PARSE_H
#include"QParse.h"

class ObjectGameParse: public QParse
{
public:
	ObjectGameParse(string line, QNode * node, LPDIRECT3DDEVICE9 d3ddv, Camera* camera);
	~ObjectGameParse();

private:

};

#endif // !OBJECT_GAME_PARSE_H
