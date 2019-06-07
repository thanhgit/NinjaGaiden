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

#include"ItemContainer4.h"
#include"Bird.h"

#include"QParse.h"
#include"NodeIdLevelParse.h"
#include"ObjectGameParse.h"
#include"RegionParse.h"

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
	virtual void ReadMap(char * _filename)=0;
	virtual void ReadRecs(char * _filename)=0;
	virtual void ReadStatics(char * _filename)=0;
	virtual void ReadEnemies(char * _fileName)=0;
	virtual void ReadQuadtree(char * _fileName)=0;

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

	list<QNode*> GetQuadTree() {
		return this->quadtree;
	}
protected:
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
	list<QNode*> quadtree;
};

#endif // !MAP_H