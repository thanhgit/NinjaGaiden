#ifndef HURT_H
#define HURT_H
#include"Sprite.h"
#include"Object.h"
class Hurt : public Object
{
public:
	Hurt(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Hurt();
	void Update();
	void Dead();
private:
	Sprite* body;
};


#endif // !SMALL_HEART
