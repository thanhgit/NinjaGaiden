#include"Banshee.h"
#include"BansheeRunLeft.h"
#include"BansheeRunRight.h"

Banshee::Banshee(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	this->graphics = new BansheeGraphics(_lpD3ddv, camera, this->GetBody());
	this->control = new BansheeControl(this->graphics, new BansheeRunLeft(this->graphics), this->GetBody());
}

Banshee::~Banshee()
{
}

void Banshee::Update(DWORD _dt)
{
	this->GetBody()->SetX(this->GetBody()->GetX() + this->GetBody()->GetVelocityX());

	BansheeState* state = this->control->getState();

	if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new BansheeRunRight())) {
		this->control->changeState(new BansheeRunLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 &&
		this->control->SameType(new BansheeRunLeft())) {
		this->control->changeState(new BansheeRunRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(Utils::SPEED_X);
	}

	this->GetBody()->SetVelocityY(-Utils::SPEED_Y);
	float y = this->GetBody()->GetY() + this->GetBody()->GetVelocityY();
	this->GetBody()->SetY(y);

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new BansheeRunRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new BansheeRunLeft(this->graphics), this->GetBody());
	}
}

void Banshee::ai(Box* box)
{
	this->obj = box;
}

void Banshee::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}
