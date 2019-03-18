#ifndef REC_H
#define REC_H

#include"Object.h"
#include"Sprite.h"
#include"Camera.h"
class Rec : public Object
{
public:
	Rec(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Rec();
	void Update();
private:
	Sprite* rec;
};


#endif // !SMALL_FIRE_H
