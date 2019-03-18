#include"Ninja.h"
#include"NinjaStandRight.h"
#include"NinjaStandLeft.h"
#include"NinjaRunLeft.h"
#include"NinjaRunRight.h"

// stand actack
#include"NinjaActackLeft.h"
#include"NinjaActackRight.h"

// jump
#include"JumpVerticalLeft.h"
#include"JumpVerticalRight.h"
#include"JumpParabolLeft.h"
#include"JumpParabolRight.h"

Ninja::Ninja(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Object(_fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	this->log = new Log();
	this->camera = camera;
	this->delta = 0;

	this->m_heart = 10;
	this->m_life = 10;
	this->m_hp = 16;
	this->m_point = 0;

	this->graphics = new NinjaGraphics(_lpD3ddv, camera, this->GetBody());
	this->control = new NinjaControl(this->graphics, new NinjaStandRight(this->graphics), this->GetBody());

	this->isRun = true;

	x_save = 0;
	x_save = 0;
}

Ninja::~Ninja()
{
}

void Ninja::Update(DWORD _dt)
{
	// GRAVITY = 0.3F
	UpdateWeapon();
	this->GetBody()->SetVelocityY(-0.3f *_dt);
	float y = this->GetBody()->GetY() + this->GetBody()->GetVelocityY();
	this->GetBody()->SetY(y);
	UpdateCamera();

	if (this->keyboard->KeyDown(DIK_LEFT) && !IsJump()) {
		if (this->keyboard->KeyDown(DIK_L)) {
			ActionJumpParabolLeft(_dt);
		}
		else {
			ActionRunLeft(_dt);
		}
	}
	else if (this->keyboard->KeyDown(DIK_RIGHT) && !IsJump()) {
		if (this->keyboard->KeyDown(DIK_L)) {
			ActionJumpParabolRight(_dt);
		}
		else {
			ActionRunRight(_dt);
		}
	}
	else if (this->keyboard->KeyDown(DIK_K) && !IsActack()) {
		if (IsLeft()) {
			this->control->changeState(new NinjaActackLeft(this->graphics), this->GetBody());
		}
		else if (IsRight()) {
			this->control->changeState(new NinjaActackRight(this->graphics), this->GetBody());
		}
	}
	else if (this->keyboard->KeyDown(DIK_L) && !IsJump()) {
		if (IsLeft()) {
			ActionJumpVerticalLeft(_dt);
		}
		else if (IsRight()) {
			ActionJumpVerticalRight(_dt);
		}
	}
	else {
		if (IsActack()) {
			if (IsActackLeft()) {
				this->control->changeState(new NinjaActackLeft(this->graphics), this->GetBody());
			}
			else if (IsActackRight()) {
				this->control->changeState(new NinjaActackRight(this->graphics), this->GetBody());
			}
		}
		else if (IsJump()) {
			if (IsJumpVertical()) {
				if (IsLeft()) {
					ActionJumpVerticalLeft(_dt);
				}
				else if (IsRight()) {
					ActionJumpVerticalRight(_dt);
				}
			}
			else if (IsJumpParabol()) {
				if (IsLeft()) {
					ActionJumpParabolLeft(_dt);
				}
				else if (IsRight()) {
					ActionJumpParabolRight(_dt);
				}
			}
		}
		else {
			if (IsLeft()) {
				this->control->changeState(new NinjaStandLeft(this->graphics), this->GetBody());
			}
			else if (IsRight()){
				this->control->changeState(new NinjaStandRight(this->graphics), this->GetBody());
			}
		}
		
	}
}

void Ninja::SetKeyboard(Keyboard * _keyboard)
{
	this->keyboard = _keyboard;
}


void Ninja::normal()
{
	if (IsJump()) {
		if (IsLeft()) {
			ActionStandLeft();
		}
		else if (IsRight()) {
			ActionStandRight();
		}
	}
}

void Ninja::revival()
{
	
}

void Ninja::save()
{
	this->x_save = this->GetBody()->GetX();
	this->y_save = this->GetBody()->GetY();
}

void Ninja::restore()
{
	if (x_save != 0 && y_save != 0) {
		this->GetBody()->SetX(this->x_save);
		this->GetBody()->SetY(this->y_save + 5);
		this->GetBody()->SetVelocityX(0);
		this->GetBody()->SetVelocityY(0);
		normal();
	}
}

void Ninja::Dead()
{
	
}

void Ninja::ActionRunLeft(DWORD _dt)
{
	this->isRun = true;
	this->body->SetVelocityX(-0.2);
	float x = this->body->GetX() + this->body->GetVelocityX()*_dt;
	this->body->SetX(x);
	this->control->changeState(new NinjaRunLeft(this->graphics), this->GetBody());
}

void Ninja::ActionRunRight(DWORD _dt)
{
	this->isRun = true;
	this->body->SetVelocityX(0.2);
	float x = this->body->GetX() + this->body->GetVelocityX()*_dt;
	this->body->SetX(x);
	this->control->changeState(new NinjaRunRight(this->graphics), this->GetBody());
}

void Ninja::ActionStand()
{
	if (IsLeft()) {
		ActionStandLeft();
	}
	else if (IsRight()) {
		ActionStandRight();
	}
}

bool Ninja::IsStandLeft()
{
	return (typeid(*this->control->getState()) == typeid(NinjaStandLeft));
}

bool Ninja::IsStandRight()
{
	return (typeid(*this->control->getState()) == typeid(NinjaStandRight));
}

bool Ninja::IsStand()
{
	return (IsStandLeft() || IsStandRight());
}

void Ninja::ActionStandLeft()
{
	this->control->changeState(new NinjaStandLeft(this->graphics), this->GetBody());
}

void Ninja::ActionStandRight()
{
	this->control->changeState(new NinjaStandRight(this->graphics), this->GetBody());
}

bool Ninja::IsRunLeft()
{
	return (typeid(*this->control->getState()) == typeid(NinjaRunLeft));
}

bool Ninja::IsRunRight()
{
	return (typeid(*this->control->getState()) == typeid(NinjaRunRight));
}

bool Ninja::IsRun()
{
	return (IsRunLeft() || IsRunRight());
}


// stand actack

bool Ninja::IsActackLeft()
{
	return (typeid(*this->control->getState()) == typeid(NinjaActackLeft));
}

bool Ninja::IsActackRight()
{
	return (typeid(*this->control->getState()) == typeid(NinjaActackRight));
}

bool Ninja::IsActack()
{
	return (IsActackLeft() || IsActackRight());
}

bool Ninja::IsJump()
{
	return (IsJumpVertical() || IsJumpParabol());
}

bool Ninja::IsJumpVertical()
{
	return (IsJumpVerticalLeft() || IsJumpVerticalRight());
}

bool Ninja::IsJumpVerticalLeft()
{
	return (typeid(*this->control->getState()) == typeid(JumpVerticalLeft));
}

bool Ninja::IsJumpVerticalRight()
{
	return (typeid(*this->control->getState()) == typeid(JumpVerticalRight));
}

void Ninja::ActionJumpVerticalLeft(DWORD _dt)
{
	float x = this->control->indexJumpVertical;
	float y = -((x - 3)*(x - 4)*(x - 4)) + 2;

	this->body->SetY(this->body->GetY() + y);

	this->control->changeState(new JumpVerticalLeft(this->graphics), this->GetBody());
}

void Ninja::ActionJumpVerticalRight(DWORD _dt)
{
	float x = this->control->indexJumpVertical;
	float y = -((x - 3)*(x - 4)*(x - 4)) + 2;

	this->body->SetY(this->body->GetY() + y);
	this->control->changeState(new JumpVerticalRight(this->graphics), this->GetBody());
}


bool Ninja::IsJumpParabol()
{
	return (IsJumpParabolLeft() || IsJumpParabolRight());
}

bool Ninja::IsJumpParabolLeft()
{
	return (typeid(*this->control->getState()) == typeid(JumpParabolLeft));
}

bool Ninja::IsJumpParabolRight()
{
	return (typeid(*this->control->getState()) == typeid(JumpParabolRight));
}

void Ninja::ActionJumpParabolLeft(DWORD _dt)
{
	float x = this->control->indexJumpParabol;
	float y = -((x - 3)*(x - 4)*(x - 4)) + 3;

	this->body->SetY(this->body->GetY() + y);
	this->body->SetX(this->body->GetX() + this->body->GetVelocityX()*(_dt+15));

	this->control->changeState(new JumpParabolLeft(this->graphics), this->GetBody());
}

void Ninja::ActionJumpParabolRight(DWORD _dt)
{
	float x = this->control->indexJumpParabol;
	float y = -((x - 3)*(x - 4)*(x - 4)) + 3;

	this->body->SetY(this->body->GetY() + y);
	this->body->SetX(this->body->GetX() + this->body->GetVelocityX()*(_dt+15));
	this->control->changeState(new JumpParabolRight(this->graphics), this->GetBody());
}


bool Ninja::IsLeft()
{
	return (IsStandLeft() || IsRunLeft() || IsActackLeft() ||
		IsJumpVerticalLeft() || IsJumpParabolLeft());
}

bool Ninja::IsRight()
{
	return (IsStandRight() || IsRunRight() || IsActackRight() ||
		IsJumpVerticalRight() || IsJumpParabolRight());
}

void Ninja::UpdateCamera()
{
	int x_camera = this->body->GetX() - (this->camera->GetWidth() / 2);
	int y_camera = this->camera->GetY();
	int width_camera = this->camera->GetWidth();

	int x_Ninja = this->body->GetX();
	int y_Ninja = this->body->GetY();
	float vx_Ninja = this->body->GetVelocityX();

	if (x_camera <= 0 && x_Ninja <= width_camera) {
		this->camera->SetCamera(0, y_camera);
	}
	else {
		this->camera->SetCamera(x_camera, y_camera);
	}

	if (x_Ninja <= 0) {
		this->body->SetX(1);
	}

}

void Ninja::UpdateWeapon()
{

}