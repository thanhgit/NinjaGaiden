#include"BatBrownGraphics.h"

BatBrownGraphics::BatBrownGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->batBrown = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/batbrown.png", 4, 4, 17, 14);
}

BatBrownGraphics::~BatBrownGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void BatBrownGraphics::runLeft(float fX, float fY)
{
	int index = this->batBrown->GetIndex();
	if (index > 1) {
		this->batBrown->SetIndex(0);
	}

	this->batBrown->Draw(fX, fY);
	this->batBrown->Next();
}

void BatBrownGraphics::runRight(float fX, float fY)
{
	int index = this->batBrown->GetIndex();
	if (index <2) {
		this->batBrown->SetIndex(2);
	}

	this->batBrown->Draw(fX, fY);
	this->batBrown->Next();
}


