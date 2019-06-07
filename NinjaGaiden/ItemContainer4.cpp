#include"ItemContainer4.h"
#include"ItemContainer4RunLeft.h"
#include"ItemContainer4RunRight.h"

ItemContainer4::ItemContainer4(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	//this->GetBody()->SetVelocityX(-0.1f);
	this->graphics = new ItemContainer4Graphics(_lpD3ddv, camera, this->GetBody());
	this->control = new ItemContainer4Control(this->graphics, new ItemContainer4RunLeft(this->graphics), this->GetBody());
}

ItemContainer4::~ItemContainer4()
{
}

void ItemContainer4::Update(DWORD _dt)
{
	this->GetBody()->SetX(this->GetBody()->GetX() + _dt*this->GetBody()->GetVelocityX());

	ItemContainer4State* state = this->control->getState();

	/*if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new ItemContainer4RunRight())) {
		this->control->changeState(new ItemContainer4RunLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-0.2f);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 &&
		this->control->SameType(new ItemContainer4RunLeft())) {
		this->control->changeState(new ItemContainer4RunRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(0.2f);
	}*/

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new ItemContainer4RunRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new ItemContainer4RunLeft(this->graphics), this->GetBody());
	}
}

void ItemContainer4::ai(Box* box)
{
	this->obj = box;
}

void ItemContainer4::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}
