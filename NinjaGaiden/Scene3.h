#ifndef SCENE1_H
#define SCENE1_H
#include"Scene.h"
#include"Map.h"
#include"Log.h""
#include"Object.h"

#include"Ninja.h""

#include"GameScene.h"

#include"PhysicalInteraction.h"
#include<list>
class Scene3 :public GameScene
{
public:
	Scene3(LPDIRECT3DDEVICE9 _lpD3dDv, Camera * _camera, HWND _hWnd);
	~Scene3();
	void init();
	void update(DWORD delta);
	void processInput();
	void exit();
private:
	int stage;
	PhysicalInteraction* physics;
	list<Box*> recs;

	Ninja * ninja;

	Map* map;
	Log* log;
	DWORD deltaTime;
};
#endif
