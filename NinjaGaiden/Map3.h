#ifndef MAP_3_H
#define MAP_3_H
#include <stdio.h>
#include"Map.h"

class Map3 : public Map
{
private:

public:
	Map3();
	~Map3();
	Map3(LPDIRECT3DDEVICE9 _d3ddv, Camera * camera, LPWSTR _spriteSheet, LPWSTR _spriteSheet2, char * _fileName);
	void ReadMap(char * _filename);
	void ReadRecs(char * _filename);
	void ReadStatics(char * _filename);
	void ReadEnemies(char * _fileName);
	void ReadQuadtree(char * _fileName);
};

#endif // !MAP_H