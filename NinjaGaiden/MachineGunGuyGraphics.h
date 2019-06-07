#ifndef MACHINE_GUN_GUY_GRAPHICS_H
#define MACHINE_GUN_GUY_GRAPHICS_H

#include"Sprite.h"
#include"Box.h"

class MachineGunGuyGraphics
{
public:
	MachineGunGuyGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, Box* _box);
	~MachineGunGuyGraphics();

	// run
	void runLeft(float fX, float fY);
	void runRight(float fX, float fY);

private:
	Box* body;

	// basic
	Sprite* machineGunGuy;

	LPDIRECT3DDEVICE9 lpD3ddv;
	Camera* camera;
};


#endif