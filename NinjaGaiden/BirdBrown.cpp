#include"BirdBrown.h"
#include"BirdBrownRunLeft.h"
#include"BirdBrownRunRight.h"

BirdBrown::BirdBrown(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	this->GetBody()->SetVelocityX(-0.1f);
	this->graphics = new BirdBrownGraphics(_lpD3ddv, camera, this->GetBody());
	this->control = new BirdBrownControl(this->graphics, new BirdBrownRunLeft(this->graphics), this->GetBody());
}

BirdBrown::~BirdBrown()
{
}

void BirdBrown::Update(DWORD _dt)
{
	this->GetBody()->SetX(this->GetBody()->GetX() + _dt*this->GetBody()->GetVelocityX());

	BirdBrownState* state = this->control->getState();

	if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new BirdBrownRunRight())) {
		this->control->changeState(new BirdBrownRunLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-0.2f);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 &&
		this->control->SameType(new BirdBrownRunLeft())) {
		this->control->changeState(new BirdBrownRunRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(0.2f);
	}

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new BirdBrownRunRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new BirdBrownRunLeft(this->graphics), this->GetBody());
	}
}

void BirdBrown::ai(Box* box)
{
	this->obj = box;
}