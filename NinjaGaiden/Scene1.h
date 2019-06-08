#ifndef SCENE1_H
#define SCENE1_H
#include"Scene.h"
#include"Map.h"
#include"Object.h"
#include"GameScene.h"
#include"SwordMan.h"
#include"BirdBrown.h"
#include"Banshee.h"
#include"BatBrown.h"
#include"Dog.h"
#include"MachineGunGuy.h"
#include"ItemContainer4.h"
#include"Runner.h"
#include"MachineGunGuySit.h"
#include"Bird.h"

#include"PhysicalInteraction.h"
#include<list>
class Scene1:public GameScene
{
public:
	Scene1();
	Scene1(LPDIRECT3DDEVICE9 _lpD3dDv, Camera * _camera, HWND _hWnd);
	~Scene1();
	void init();
	void update(DWORD delta);
	void processInput();
	void exit();
private:
	PhysicalInteraction* physics;
	list<Box*> recs;

	Ninja * ninja;
	std::list<Enemy*> enemies;

	Map* map;
	Log* log;
	DWORD deltaTime;
};
#endif
