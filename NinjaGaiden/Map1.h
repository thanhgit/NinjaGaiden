#ifndef MAP_1_H
#define MAP_1_H
#include <stdio.h>
#include"Map.h"

class Map1 : public Map
{
private:

public:
	Map1();
	~Map1();
	Map1(LPDIRECT3DDEVICE9 _d3ddv, Camera * camera, LPWSTR _spriteSheet, LPWSTR _spriteSheet2, char * _fileName);
	virtual void ReadMap(char * _filename);
	virtual void ReadRecs(char * _filename);
	virtual void ReadStatics(char * _filename);
	virtual void ReadEnemies(char * _fileName);
};

#endif // !MAP_H