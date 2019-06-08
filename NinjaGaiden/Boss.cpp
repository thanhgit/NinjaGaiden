#include"Boss.h"

Boss::Boss(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Object(_fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->camera = camera;
	this->delta = 0;

	this->m_hp = 1;
	this->m_damage = 0;
	this->m_point = 0;
}

Boss::~Boss()
{
}