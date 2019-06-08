#ifndef BANSHEE_H
#define BANSHEE_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"BansheeControl.h"
#include"BansheeGraphics.h"
#include<typeinfo.h>

class Banshee : public Enemy
{
public:
	Banshee(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Banshee();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();
	EnemyState* getState();
	void setState(EnemyState* _state);
private:
	BansheeControl * control;
	BansheeGraphics* graphics;
	Box* obj;
};

#endif