#include"BirdBrownGraphics.h"

BirdBrownGraphics::BirdBrownGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->birdBrown = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/birdbrown.png", 4, 4, 17, 25);
}

BirdBrownGraphics::~BirdBrownGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void BirdBrownGraphics::runLeft(float fX, float fY)
{
	int index = this->birdBrown->GetIndex();
	if (index > 1) {
		this->birdBrown->SetIndex(0);
	}

	this->birdBrown->Draw(fX, fY);
	this->birdBrown->Next();
}

void BirdBrownGraphics::runRight(float fX, float fY)
{
	int index = this->birdBrown->GetIndex();
	if (index <2) {
		this->birdBrown->SetIndex(2);
	}

	this->birdBrown->Draw(fX, fY);
	this->birdBrown->Next();
}


