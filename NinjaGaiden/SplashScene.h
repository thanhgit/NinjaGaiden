#ifndef SPLASH_SCENE_H
#define SPLASH_SCENE_H
#include"Scene.h"
#include"Map.h"
#include"Log.h""
#include"Object.h"
#include"Ninja.h"
#include<list>
class SplashScene :public Scene
{
public:
	SplashScene(LPDIRECT3DDEVICE9 _lpD3dDv, Camera * _camera, HWND _hWnd);
	~SplashScene();
	void InitScene();
	void UpdateScene(DWORD delta);
	void ProcessInput();
	void ExitScene();
private:
	Ninja * ninja;

	Map* map;
	Log* log;
	DWORD deltaTime;
};
#endif // !SCENE1_H
