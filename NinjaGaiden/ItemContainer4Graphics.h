#ifndef ITEM_CONTAINER_4_GRAPHICS_H
#define ITEM_CONTAINER_4_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class ItemContainer4Graphics
{
public:
	ItemContainer4Graphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~ItemContainer4Graphics();

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* itemContainer4;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif