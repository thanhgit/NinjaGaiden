#ifndef MACHINE_GUN_GUY_SIT_GRAPHICS_H
#define MACHINE_GUN_GUY_SIT_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class MachineGunGuySitGraphics
{
public:
	MachineGunGuySitGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~MachineGunGuySitGraphics();

	// sit
	void sitLeft(float fX, float fY);
	void sitRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* machineGunGuySit;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif