#ifndef BIRD_H
#define BIRD_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Static.h"
#include"BirdControl.h"
#include"BirdGraphics.h"

class Bird : public Static
{
public:
	Bird(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Bird();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();
private:
	BirdControl * control;
	BirdGraphics* graphics;
	Box* obj;
};

#endif