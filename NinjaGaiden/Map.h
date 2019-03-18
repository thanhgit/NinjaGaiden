#ifndef MAP_H
#define MAP_H
#include <stdio.h>
#include "Sprite.h"
#include"Camera.h"
#include"Box.h"
#include"Collision.h"

#include"Rec.h"
#include"Ninja.h"
#include"Static.h"
#include"Enemy.h"

#include<fstream>
#include<sstream>
#include<list>
class Map
{
private:
	
public:
	Map();
	~Map();
	Map(LPDIRECT3DDEVICE9 _d3ddv, Camera * camera, LPWSTR _spriteSheet, LPWSTR _spriteSheet2, char * _fileName);
	void Update(DWORD delta);
	void Draw(float vpx, float vpy);
	void ReadMap(char * _filename);
	void ReadRecs(char * _filename);
	void ReadStatics(char * _filename);
	void ReadEnemies(char * _fileName);

	list<Box*> GetRecs() {
		return this->recs;
	}

	list<Static*> GetStatics() {
		return this->statics;
	}

	list<Enemy*> GetEnemies() {
		return this->enemies;
	}

	list<Item*> GetItems() {
		return this->items;
	}
private:
	int nTileCount;
	int nTileTotal;
	int nTileWidth;
	int nTileHeight;
	int nTileCountWidth;
	int nTileCountHeight;
	int arr[100][500];
	Sprite* imgmap;
	Sprite** map;
	Camera* camera;
	LPDIRECT3DDEVICE9 d3ddv;	

	list<Box*> recs;
	list<Static*> statics;
	list<Object*> recsObj;
	list<Enemy*> enemies;
	list<Item*> items;

	Collision* collition;
};

#endif // !MAP_H