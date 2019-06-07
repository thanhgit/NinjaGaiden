#include"DogGraphics.h"

DogGraphics::DogGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->dog = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/dog.png", 4, 4, 32, 17);
}

DogGraphics::~DogGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void DogGraphics::runLeft(float fX, float fY)
{
	int index = this->dog->GetIndex();
	if (index > 1) {
		this->dog->SetIndex(0);
	}

	this->dog->Draw(fX, fY);
	this->dog->Next();
}

void DogGraphics::runRight(float fX, float fY)
{
	int index = this->dog->GetIndex();
	if (index <2) {
		this->dog->SetIndex(2);
	}

	this->dog->Draw(fX, fY);
	this->dog->Next();
}


