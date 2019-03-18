#include"Object.h"
#include"Utils.h"


Object::Object(float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY)
{
	this->body = new Box(_fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY);
	this->m_hp = 0;
}

Object::~Object()
{
}

void Object::Dead()
{
}

void Object::Update(DWORD _dt)
{
}

void Object::normal()
{
}

