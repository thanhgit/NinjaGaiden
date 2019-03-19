#ifndef SWORD_MAN_GRAPHICS_H
#define SWORD_MAN_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class SwordManGraphics
{
public:
	SwordManGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~SwordManGraphics();

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

	// stand actack
	void actackLeft(float fX, float fY);
	void actackRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* swordMan;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif // !SIMON_GRAPHICS_H