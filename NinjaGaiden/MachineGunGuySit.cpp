#include"MachineGunGuySit.h"
#include"MachineGunGuySitSitLeft.h"
#include"MachineGunGuySitSitRight.h"

MachineGunGuySit::MachineGunGuySit(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	//this->GetBody()->SetVelocityX(-0.1f);
	this->graphics = new MachineGunGuySitGraphics(_lpD3ddv, camera, this->GetBody());
	this->control = new MachineGunGuySitControl(this->graphics, new MachineGunGuySitSitLeft(this->graphics), this->GetBody());
}

MachineGunGuySit::~MachineGunGuySit()
{
}

void MachineGunGuySit::Update(DWORD _dt)
{
	//this->GetBody()->SetX(this->GetBody()->GetX() + _dt*this->GetBody()->GetVelocityX());

	MachineGunGuySitState* state = this->control->getState();

	/*if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new MachineGunGuySitSitRight())) {
		this->control->changeState(new MachineGunGuySitSitLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-0.2f);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 &&
		this->control->SameType(new MachineGunGuySitSitLeft())) {
		this->control->changeState(new MachineGunGuySitSitRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(0.2f);
	}*/


	this->GetBody()->SetVelocityY(-Utils::SPEED_Y);
	float y = this->GetBody()->GetY() + this->GetBody()->GetVelocityY();
	this->GetBody()->SetY(y);

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new MachineGunGuySitSitRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new MachineGunGuySitSitLeft(this->graphics), this->GetBody());
	}
}

void MachineGunGuySit::ai(Box* box)
{
	this->obj = box;
}

void MachineGunGuySit::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}
