#ifndef MACHINE_GUN_GUY_SIT_H
#define MACHINE_GUN_GUY_SIT_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"MachineGunGuySitControl.h"
#include"MachineGunGuySitGraphics.h"
#include<typeinfo.h>
class MachineGunGuySit : public Enemy
{
public:
	MachineGunGuySit(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~MachineGunGuySit();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();

	EnemyState* getState();
	void setState(EnemyState* _state);
private:
	MachineGunGuySitControl * control;
	MachineGunGuySitGraphics* graphics;
	Box* obj;
};

#endif