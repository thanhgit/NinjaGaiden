#include"Runner.h"
#include"RunnerRunLeft.h"
#include"RunnerRunRight.h"

Runner::Runner(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Enemy(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->m_hp = 6;
	this->m_damage = 2;
	this->m_point = 400;
	this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	this->graphics = new RunnerGraphics(_lpD3ddv, camera, this->GetBody());
	this->control = new RunnerControl(this->graphics, new RunnerRunLeft(this->graphics), this->GetBody());
}

Runner::~Runner()
{
}

void Runner::Update(DWORD _dt)
{
	this->GetBody()->SetX(this->GetBody()->GetX() + this->GetBody()->GetVelocityX());

	RunnerState* state = this->control->getState();

	if (this->GetBody()->GetX() - this->camera->GetX() > this->camera->GetWidth() &&
		this->control->SameType(new RunnerRunRight())) {
		this->control->changeState(new RunnerRunLeft(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(-Utils::SPEED_X);
	}
	else if (this->GetBody()->GetX() - this->camera->GetX() < 0 &&
		this->control->SameType(new RunnerRunLeft())) {
		this->control->changeState(new RunnerRunRight(this->graphics), this->GetBody());
		this->GetBody()->SetVelocityX(Utils::SPEED_X);
	}


	this->GetBody()->SetVelocityY(-Utils::SPEED_Y);
	float y = this->GetBody()->GetY() + this->GetBody()->GetVelocityY();
	this->GetBody()->SetY(y);

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new RunnerRunRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new RunnerRunLeft(this->graphics), this->GetBody());
	}
}

void Runner::ai(Box* box)
{
	this->obj = box;
}

void Runner::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}
