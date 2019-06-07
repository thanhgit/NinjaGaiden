#include"Hurt.h"


Hurt::Hurt(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Object( _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->body = new Sprite(_lpD3ddv, camera, L"data/Resources/other/0.png", 1, 1, 8, 10);
	this->index = 0;
	this->steps = 15;
	this->action = 0;
}

Hurt::~Hurt()
{
}

void Hurt::AttackLeft()
{
	this->action = 1;
}

void Hurt::AttackRight()
{
	this->action = 2;
}

void Hurt::Update(DWORD _dt)
{
	float x = 0;
	switch (this->action)
	{
		case 1:
			this->GetBody()->SetVelocityX(-0.2);
			x = this->GetBody()->GetX() + -5;
			this->GetBody()->SetX(x);
			index++;

			if (index > steps) {
				Dead();
			}

			break;
		case 2:
			this->GetBody()->SetVelocityX(0.2);
			x = this->GetBody()->GetX() + 5;
			this->GetBody()->SetX(x);
			index++;

			if (index > steps) {
				Dead();
			}
			break;
		default:
			Dead();
			break;
	}

	this->body->Draw(x, this->GetBody()->GetY());
	this->body->Next();
	
}

void Hurt::Dead()
{
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
	this->action = 0;
	this->index = 0;
}