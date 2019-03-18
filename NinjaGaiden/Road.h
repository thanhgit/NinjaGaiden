#ifndef ROAD_H
#define ROAD_H
#include"Sprite.h"
#include"Box.h"
#include"Object.h"
class Road:public Object
{
public:
	Road();
	Road(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY);
	~Road();
	void Update();
private:
	Sprite* shape;
};


#endif // !ROAD_H
