#ifndef BOSS3_H
#define BOSS3_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Boss.h"
#include"Boss3Control.h"
#include"Boss3Graphics.h"

#include<typeinfo.h>

class Boss3 : public Boss
{
public:
	Boss3(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Boss3();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();

	BossState* getState();
	void setState(BossState* _state);

	// stand
	void ActionStandLeft();
	void ActionStandRight();

	// jump
	void ActionJumpLeft(DWORD _dt);
	void ActionJumpRight(DWORD _dt);

	bool IsJump();
	bool IsJumpLeft();
	bool IsJumpRight();

	bool IsStand();
	bool IsStandLeft();
	bool IsStandRight();
private:
	Boss3Control * control;
	Boss3Graphics* graphics;
	Box* obj;
};

#endif