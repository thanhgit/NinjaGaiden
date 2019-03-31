#ifndef BIRD_BROWN_GRAPHICS_H
#define BIRD_BROWN_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class BirdBrownGraphics
{
public:
	BirdBrownGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~BirdBrownGraphics();

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* birdBrown;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif