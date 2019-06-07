#ifndef BIRD_GRAPHICS_H
#define BIRD_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class BirdGraphics
{
public:
	BirdGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~BirdGraphics();

	// fly
	void flyLeft(float fX, float fY);
	void flyRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* bird;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif