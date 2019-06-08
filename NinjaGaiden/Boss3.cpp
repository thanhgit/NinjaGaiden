#include"Boss3.h"
#include"Boss3StandLeft.h"
#include"Boss3StandRight.h"
#include"Boss3JumpLeft.h"
#include"Boss3JumpRight.h"

Boss3::Boss3(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Boss(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	this->graphics = new Boss3Graphics(_lpD3ddv, camera, this->GetBody());
	this->control = new Boss3Control(this->graphics, new Boss3StandRight(this->graphics), this->GetBody());
}

Boss3::~Boss3()
{
}

void Boss3::Update(DWORD _dt)
{
	Boss3State* state = this->control->getState();
	
	if (typeid(*state) == typeid(Boss3StandRight)) {
		this->control->changeState(new Boss3JumpLeft(this->graphics), this->GetBody());
		Sleep(Utils::ANIMATE_TIME + 100);
	}
	else if (typeid(*state) == typeid(Boss3StandLeft)) {
		this->control->changeState(new Boss3JumpRight(this->graphics), this->GetBody());
		Sleep(Utils::ANIMATE_TIME + 100);
	}
	else if (typeid(*state) == typeid(Boss3JumpLeft)) {
		ActionJumpLeft(_dt);
	}
	else if (typeid(*state) == typeid(Boss3JumpRight)) {
		ActionJumpRight(_dt);
	}
}

void Boss3::ai(Box* box)
{
	this->obj = box;
}

void Boss3::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}

BossState * Boss3::getState()
{
	return this->control->getState();
}

void Boss3::setState(BossState * _state)
{
	if ((typeid(*_state) == typeid(Boss3StandLeft))) {
		this->control->changeState(new Boss3StandLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	}
	else if ((typeid(*_state) == typeid(Boss3StandRight))) {
		this->control->changeState(new Boss3StandRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(Utils::SPEED_X);
	}
}

void Boss3::ActionStandLeft()
{
}

void Boss3::ActionStandRight()
{
}

void Boss3::ActionJumpLeft(DWORD _dt)
{
	float x = this->control->indexJump;
	float y = -((x - 3)*(x - 5)*(x - 5)) - 3;

	this->GetBody()->SetX(this->GetBody()->GetX() - (_dt + 5));
	this->GetBody()->SetY(this->GetBody()->GetY() + y);

	this->control->changeState(new Boss3JumpLeft(this->graphics), this->GetBody());
}

void Boss3::ActionJumpRight(DWORD _dt)
{
	float x = this->control->indexJump;
	float y = -((x - 3)*(x - 5)*(x - 5)) - 3;

	this->GetBody()->SetX(this->GetBody()->GetX() + (_dt + 5));
	this->GetBody()->SetY(this->GetBody()->GetY() + y);

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
