#ifndef BIRD_BROWN_H
#define BIRD_BROWN_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"BirdBrownControl.h"
#include"BirdBrownGraphics.h"
#include<typeinfo.h>
class BirdBrown : public Enemy
{
public:
	BirdBrown(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~BirdBrown();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();
	EnemyState* getState();
	void setState(EnemyState* _state);
private:
	BirdBrownControl * control;
	BirdBrownGraphics* graphics;
	Box* obj;
};

#endif