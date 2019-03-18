#ifndef SCENE_H
#define SCENE_H
#include"Camera.h"
#include"Keyboard.h"
#include"Audio.h"
#include<d3d9.h>
class Scene
{
public:
	Scene(LPDIRECT3DDEVICE9 _lpD3dDv,Camera* _camera,HWND _hWnd);
	~Scene();

	virtual void InitScene() = 0;
	virtual void UpdateScene(DWORD delta) = 0;
	virtual void ProcessInput() = 0;
	virtual void ExitScene() = 0;
	LPDIRECT3DDEVICE9 GetDevice();
	Camera* GetCamera();
	Keyboard* GetKeyboard();
	Audio* GetAudio();
private:
	LPDIRECT3DDEVICE9 d3ddv;
	Camera* camera;
	Keyboard* keyboard;

	HWND hWnd;
	Audio* audio;
};


#endif // !SCENE_H
