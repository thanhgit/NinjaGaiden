#include"Boss3.h"
#include"Boss3StandLeft.h"
#include"Boss3StandRight.h"
#include"Boss3JumpLeft.h"
#include"Boss3JumpRight.h"

Boss3::Boss3(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	this->graphics = new Boss3Graphics(_lpD3ddv, camera, this->GetBody());
	this->control = new Boss3Control(this->graphics, new Boss3StandLeft(this->graphics), this->GetBody());
}

Boss3::~Boss3()
{
}

void Boss3::Update(DWORD _dt)
{
	this->GetBody()->SetX(this->GetBody()->GetX() + this->GetBody()->GetVelocityX());

	Boss3State* state = this->control->getState();

	if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new Boss3StandRight())) {
		this->control->changeState(new Boss3StandLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 &&
		this->control->SameType(new Boss3StandLeft())) {
		this->control->changeState(new Boss3StandRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(Utils::SPEED_X);
	}

	this->GetBody()->SetVelocityY(-Utils::SPEED_Y);
	float y = this->GetBody()->GetY() + this->GetBody()->GetVelocityY();
	this->GetBody()->SetY(y);

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new Boss3StandRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new Boss3StandLeft(this->graphics), this->GetBody());
	}
}

void Boss3::ai(Box* box)
{
	this->body = box;
}

void Boss3::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}

void Boss3::ActionStandLeft()
{
}

void Boss3::ActionStandRight()
{
}

void Boss3::ActionJumpLeft()
{
	float x = this->control->indexJump;
	float y = -((x - 3)*(x - 5)*(x - 5)) - 7;

	this->body->SetY(this->body->GetY() + y);

	this->control->changeState(new Boss3JumpLeft(this->graphics), this->GetBody());
}

void Boss3::ActionJumpRight()
{
	float x = this->control->indexJump;
	float y = -((x - 3)*(x - 5)*(x - 5)) - 7;

	this->body->SetY(this->body->GetY() + y);
	this->control->changeState(new Boss3JumpRight(this->graphics), this->GetBody());
}

bool Boss3::IsJump()
{
	return IsJumpLeft() || IsJumpRight();
}

bool Boss3::IsJumpLeft()
{
	return (typeid(*this->control->getState()) == typeid(Boss3JumpLeft));;
}

bool Boss3::IsJumpRight()
{
	return (typeid(*this->control->getState()) == typeid(Boss3JumpRight));;
}

bool Boss3::IsStand()
{
	return IsStandLeft() || IsStandRight();
}

bool Boss3::IsStandLeft()
{
	return (typeid(*this->control->getState()) == typeid(Boss3StandLeft));;
}

bool Boss3::IsStandRight()
{
	return (typeid(*this->control->getState()) == typeid(Boss3StandRight));;
}
