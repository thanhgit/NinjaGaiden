#ifndef BOSS3_GRAPHICS_H
#define BOSS3_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class Boss3Graphics
{
public:
	Boss3Graphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~Boss3Graphics();

	// run
	void standLeft(float fX, float fY);
	void standRight(float fX, float fY);

	// jump
	void jumpLeft(float fX, float fY);
	void jumpRight(float fX, float fY);
private:
	Box* body;

	// basic
	Sprite* boss3;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif