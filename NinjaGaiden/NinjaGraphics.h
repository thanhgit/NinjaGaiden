#ifndef NINJA_GRAPHICS_H
#define NINJA_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class NinjaGraphics
{
public:
	NinjaGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~NinjaGraphics();
	// stand
	void standLeft(float fX, float fY);
	void standRight(float fX, float fY);

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

	// jump
	void jumpLeft(float fX, float fY);
	void jumpRight(float fX, float fY);

	void jumpVerticalLeft(float fX, float fY);
	void jumpVerticalRight(float fX, float fY);
	
	void jumpParabolLeft(float fX, float fY);
	void jumpParabolRight(float fX, float fY);

	// stand actack
	void actackLeft(float fX, float fY);
	void actackRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* ninja;

	// stand actack
	Sprite* ninjaActack;

	// jump
	Sprite* ninjaJump;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;};


#endif // !SIMON_GRAPHICS_H