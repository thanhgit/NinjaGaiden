#include"SwordManGraphics.h"

SwordManGraphics::SwordManGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->swordMan = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/swordman.png", 6, 6, 25, 41);
}

SwordManGraphics::~SwordManGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void SwordManGraphics::runLeft(float fX, float fY)
{
	int index = this->swordMan->GetIndex();
	if (index > 1) {
		this->swordMan->SetIndex(0);
	}

	this->swordMan->Draw(fX, fY);
	this->swordMan->Next();
}

void SwordManGraphics::runRight(float fX, float fY)
{
	int index = this->swordMan->GetIndex();
	if (index > 4) {
		this->swordMan->SetIndex(3);
	}

	this->swordMan->Draw(fX, fY);
	this->swordMan->Next();
}



// stand actack
void SwordManGraphics::actackLeft(float fX, float fY)
{
	int index = this->swordMan->GetIndex();
	if (index > 2 ) {
		this->swordMan->SetIndex(1);
	}

	this->swordMan->Draw(fX, fY);
	this->swordMan->Next();
}

void SwordManGraphics::actackRight(float fX, float fY)
{
	int index = this->swordMan->GetIndex();
	if (index < 4) {
		this->swordMan->SetIndex(4);
	}

	this->swordMan->Draw(fX, fY);
	this->swordMan->Next();
}

