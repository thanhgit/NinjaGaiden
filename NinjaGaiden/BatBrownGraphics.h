#ifndef BAT_BROWN_GRAPHICS_H
#define BAT_BROWN_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class BatBrownGraphics
{
public:
	BatBrownGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~BatBrownGraphics();

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* batBrown;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif