#ifndef FLAG_H
#define FLAG_H
#include"Box.h"
#include"Collision.h"
#include"Camera.h"
#include"Object.h"
#include"Sprite.h"
#include<d3d9.h>
class Flag:public Object
{
public:
	Flag(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Flag();

	void Update();


private:
	Sprite* shape;
};


#endif // !FLAG_H
