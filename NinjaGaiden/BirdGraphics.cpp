#include"BirdGraphics.h"

BirdGraphics::BirdGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->bird = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/bird.png", 4, 4, 17, 16);
}

BirdGraphics::~BirdGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void BirdGraphics::flyLeft(float fX, float fY)
{
	int index = this->bird->GetIndex();
	if (index > 1) {
		this->bird->SetIndex(0);
	}

	this->bird->Draw(fX, fY);
	this->bird->Next();
}

void BirdGraphics::flyRight(float fX, float fY)
{
	int index = this->bird->GetIndex();
	if (index <2) {
		this->bird->SetIndex(2);
	}

	this->bird->Draw(fX, fY);
	this->bird->Next();
}


