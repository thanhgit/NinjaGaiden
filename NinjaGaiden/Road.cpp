#include"Road.h"

Road::Road():Object(0,0,0,0,0,0)
{
}

Road::Road(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY):Object(_fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	shape = new Sprite(_lpD3ddv, camera, L"stuck.png",1,1,_nWidth,_nHeight);
}

Road::~Road()
{
}

void Road::Update()
{
	shape->Draw(body->GetX(),body->GetY());
}
