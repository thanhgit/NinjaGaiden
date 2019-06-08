#include"Static.h"

Static::Static(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Object(_fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->camera = camera;
	this->delta = 0;
	this->active = false;
}

Static::~Static()
{
}

void Static::Update()
{
}

void Static::Dead()
{
}

void Static::SetKeyboard(Keyboard * _keyboard)
{
	this->keyboard = _keyboard;
}



void Static::setDelta(DWORD _delta)
{
	this->delta = _delta;
}