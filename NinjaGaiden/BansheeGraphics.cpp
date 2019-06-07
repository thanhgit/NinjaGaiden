#include"BansheeGraphics.h"

BansheeGraphics::BansheeGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->banshee = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/banshee.png", 6, 6, 25, 43);
}

BansheeGraphics::~BansheeGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void BansheeGraphics::runLeft(float fX, float fY)
{
	int index = this->banshee->GetIndex();
	//if (index > 2) {
		this->banshee->SetIndex(0);
	//}

	this->banshee->Draw(fX, fY);
	this->banshee->Next();
}

void BansheeGraphics::runRight(float fX, float fY)
{
	int index = this->banshee->GetIndex();
	//if (index <3) {
		this->banshee->SetIndex(3);
	//}

	this->banshee->Draw(fX, fY);
	this->banshee->Next();
}


