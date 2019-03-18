#include"Item.h"

Item::Item(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Object(_fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->camera = camera;
	this->delta = 0;
	this->active = false;
}

Item::~Item()
{
}

void Item::Update()
{
}

void Item::Dead()
{
	this->GetBody()->SetY(0);
}


void Item::SetKeyboard(Keyboard * _keyboard)
{
	this->keyboard = _keyboard;
}



void Item::setDelta(DWORD _delta)
{
	this->delta = _delta;
}