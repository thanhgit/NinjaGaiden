#ifndef MACHINE_GUN_GUY_H
#define MACHINE_GUN_GUY_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"MachineGunGuyControl.h"
#include"MachineGunGuyGraphics.h"

class MachineGunGuy : public Enemy
{
public:
	MachineGunGuy(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~MachineGunGuy();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();
private:
	MachineGunGuyControl * control;
	MachineGunGuyGraphics* graphics;
	Box* obj;
};

#endif