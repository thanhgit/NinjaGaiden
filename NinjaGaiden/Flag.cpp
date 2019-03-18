#include"Flag.h"

Flag::Flag(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY):Object(_fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	shape = new Sprite(_lpD3ddv, camera, L"flag.png", 1, 1, 10, 10);
}

Flag::~Flag()
{
}

void Flag::Update() {
	this->shape->Draw(this->GetBody()->GetX(),this->GetBody()->GetY());
}