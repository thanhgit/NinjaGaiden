#include"Dog.h"
#include"DogRunLeft.h"
#include"DogRunRight.h"

Dog::Dog(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	if (_lpD3ddv != nullptr) {
		this->m_hp = 6;
		this->m_damage = 2;
		this->m_point = 400;
		this->GetBody()->SetVelocityX(-Utils::SPEED_X);
		this->graphics = new DogGraphics(_lpD3ddv, camera, this->GetBody());
		this->control = new DogControl(this->graphics, new DogRunLeft(this->graphics), this->GetBody());
	}
}

Dog::~Dog()
{
}

void Dog::Update(DWORD _dt)
{
	this->GetBody()->SetX(this->GetBody()->GetX() + this->GetBody()->GetVelocityX());

	DogState* state = this->control->getState();

	if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new DogRunRight())) {
		this->control->changeState(new DogRunLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 &&
		this->control->SameType(new DogRunLeft())) {
		this->control->changeState(new DogRunRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(Utils::SPEED_X);
	}


	this->GetBody()->SetVelocityY(-Utils::SPEED_Y);
	float y = this->GetBody()->GetY() + this->GetBody()->GetVelocityY();
	this->GetBody()->SetY(y);

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new DogRunRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new DogRunLeft(this->graphics), this->GetBody());
	}
}

void Dog::ai(Box* box)
{
	this->obj = box;
}

void Dog::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}
