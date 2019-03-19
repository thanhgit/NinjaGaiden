#ifndef SWORD_MAN_H
#define SWORD_MAN_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"SwordManControl.h"
#include"SwordManGraphics.h"

class SwordMan : public Enemy
{
public:
	SwordMan(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~SwordMan();
	void Update();
	void ai(Box* box);
private:
	SwordManControl * control;
	SwordManGraphics* graphics;
	Box* obj;
};

#endif