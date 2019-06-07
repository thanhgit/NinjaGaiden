#ifndef RUNNER_GRAPHICS_H
#define RUNNER_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class RunnerGraphics
{
public:
	RunnerGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~RunnerGraphics();

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* runner;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif