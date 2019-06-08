#include"Boss3Graphics.h"

Boss3Graphics::Boss3Graphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->boss3 = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/boss/boss3.png", 4, 4, 39, 54);
}

Boss3Graphics::~Boss3Graphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void Boss3Graphics::standLeft(float fX, float fY)
{
	this->boss3->SetIndex(1);

	this->boss3->Draw(fX, fY);
	//this->boss3->Next();
}

void Boss3Graphics::standRight(float fX, float fY)
{
	this->boss3->SetIndex(3);

	this->boss3->Draw(fX, fY);
	//this->boss3->Next();
}

void Boss3Graphics::jumpLeft(float fX, float fY)
{
	this->boss3->SetIndex(0);

	this->boss3->Draw(fX, fY);
	//this->boss3->Next();
}

void Boss3Graphics::jumpRight(float fX, float fY)
{
	this->boss3->SetIndex(2);

	this->boss3->Draw(fX, fY);
	//this->boss3->Next();
}


