#ifndef BANSHEE_GRAPHICS_H
#define BANSHEE_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class BansheeGraphics
{
public:
	BansheeGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~BansheeGraphics();

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* banshee;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif