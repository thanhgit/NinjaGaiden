#include"Rec.h"

Rec::Rec(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Object(_fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->rec = new Sprite(_lpD3ddv, camera, L"data/Resources/blackboardpause.png", 1, 1, _nWidth, _nHeight);

}

Rec::~Rec()
{
}

void Rec::Update()
{
	this->rec->Draw(this->GetBody()->GetX(), this->GetBody()->GetY());
	this->rec->Next();
}
