#include"ItemContainer4Graphics.h"

ItemContainer4Graphics::ItemContainer4Graphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->itemContainer4 = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/itemcontainer4.png", 4, 4, 16, 15);
}

ItemContainer4Graphics::~ItemContainer4Graphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void ItemContainer4Graphics::runLeft(float fX, float fY)
{
	int index = this->itemContainer4->GetIndex();
	if (index > 1) {
		this->itemContainer4->SetIndex(0);
	}

	this->itemContainer4->Draw(fX, fY);
	this->itemContainer4->Next();
}

void ItemContainer4Graphics::runRight(float fX, float fY)
{
	int index = this->itemContainer4->GetIndex();
	if (index <2) {
		this->itemContainer4->SetIndex(2);
	}

	this->itemContainer4->Draw(fX, fY);
	this->itemContainer4->Next();
}


