#ifndef DOG_GRAPHICS_H
#define DOG_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class DogGraphics
{
public:
	DogGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~DogGraphics();

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* dog;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif