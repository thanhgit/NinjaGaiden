#ifndef DOG_H
#define DOG_H
#include"Sprite.h"
#include"Keyboard.h"
#include"Enemy.h"
#include"DogControl.h"
#include"DogGraphics.h"

class Dog : public Enemy
{
public:
	Dog(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Dog();
	void Update(DWORD _dt);
	void ai(Box* box);
	void Dead();
private:
	DogControl * control;
	DogGraphics* graphics;
	Box* obj;
};

#endif