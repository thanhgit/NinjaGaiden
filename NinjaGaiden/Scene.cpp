#include"Scene.h"


Scene::Scene(LPDIRECT3DDEVICE9 _lpD3dDv, Camera * _camera, HWND _hWnd)
{
	this->d3ddv = _lpD3dDv;
	this->camera = _camera;
	this->hWnd = _hWnd;
	this->keyboard = new Keyboard();
	this->audio = new Audio();
}

Scene::~Scene()
{
}

LPDIRECT3DDEVICE9 Scene::GetDevice()
{
	return this->d3ddv;
}

Camera * Scene::GetCamera()
{
	return this->camera;
}

Keyboard * Scene::GetKeyboard()
{
	return this->keyboard;
}

Audio * Scene::GetAudio()
{
	return this->audio;
}
