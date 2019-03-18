#include"Hurt.h"


Hurt::Hurt(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Object( _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->body = new Sprite(_lpD3ddv, camera, L"data/Resources/other/0.png", 1, 1, 8, 10);

}

Hurt::~Hurt()
{
}


void Hurt::Update()
{
	this->body->Draw(this->GetBody()->GetX(), this->GetBody()->GetY() + 30);
	this->body->Next();
}

void Hurt::Dead()
{
	this->GetBody()->SetX(0);
	this->GetBody()->SetY(0);
}