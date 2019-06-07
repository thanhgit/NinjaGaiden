#include"BatBrown.h"
#include"BatBrownRunLeft.h"
#include"BatBrownRunRight.h"

BatBrown::BatBrown(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	this->graphics = new BatBrownGraphics(_lpD3ddv, camera, this->GetBody());
	this->control = new BatBrownControl(this->graphics, new BatBrownRunLeft(this->graphics), this->GetBody());
}

BatBrown::~BatBrown()
{
}

void BatBrown::Update(DWORD _dt)
{
	this->GetBody()->SetX(this->GetBody()->GetX() + this->GetBody()->GetVelocityX());

	BatBrownState* state = this->control->getState();

	if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new BatBrownRunRight())) {
		this->control->changeState(new BatBrownRunLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 &&
		this->control->SameType(new BatBrownRunLeft())) {
		this->control->changeState(new BatBrownRunRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(Utils::SPEED_X);
	}

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new BatBrownRunRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new BatBrownRunLeft(this->graphics), this->GetBody());
	}
}

void BatBrown::ai(Box* box)
{
	this->obj = box;
}

void BatBrown::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}
