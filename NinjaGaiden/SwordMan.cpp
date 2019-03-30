#include"SwordMan.h"
#include"SwordManRunLeft.h"
#include"SwordManRunRight.h"
#include"SwordManAttackLeft.h"
#include"SwordManAttackRight.h"

SwordMan::SwordMan(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	this->GetBody()->SetVelocityX(-0.1f);
	this->graphics = new SwordManGraphics(_lpD3ddv, camera, this->GetBody());
	this->control = new SwordManControl(this->graphics, new SwordManRunLeft(this->graphics), this->GetBody());
}

SwordMan::~SwordMan()
{
}

void SwordMan::Update(DWORD _dt)
{
	this->GetBody()->SetVelocityY(-0.3f *_dt);
	float y = this->GetBody()->GetY() + this->GetBody()->GetVelocityY();
	this->GetBody()->SetY(y);

	this->GetBody()->SetX(this->GetBody()->GetX() + _dt*this->GetBody()->GetVelocityX());

	SwordManState* state = this->control->getState();

	if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new SwordManRunRight())) {
		this->control->changeState(new SwordManRunLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-0.2f);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 && 
		this->control->SameType(new SwordManRunLeft())) {
		this->control->changeState(new SwordManRunRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(0.2f);
	}

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new SwordManRunRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new SwordManRunLeft(this->graphics), this->GetBody());
	}
}

void SwordMan::ai(Box* box)
{
	this->obj = box;
}