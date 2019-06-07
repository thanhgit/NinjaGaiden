#include"Ninja.h"
#include"NinjaStandRight.h"
#include"NinjaStandLeft.h"
#include"NinjaRunLeft.h"
#include"NinjaRunRight.h"

// stand actack
#include"NinjaAttackLeft.h"
#include"NinjaAttackRight.h"

// jump
#include"JumpNormalLeft.h"
#include"JumpNormalRight.h"
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
	this->allowJump = false;

	x_save = 0;
	x_save = 0;

	this->hurt = new Hurt(_lpD3ddv, camera, -100, -100, 8, 10, 0, 0 );
	this->updateCamera = true;
}

Ninja::~Ninja()
{
}

void Ninja::Update(DWORD _dt)
{
	this->hurt->GetBody()->SetX(this->body->GetX());
	this->hurt->GetBody()->SetY(this->body->GetY());
	// GRAVITY = 0.3F
	//UpdateWeapon(_dt);
	this->GetBody()->SetVelocityY(-0.3f *_dt);
	float y = this->GetBody()->GetY() + this->GetBody()->GetVelocityY();
	this->GetBody()->SetY(y);
	UpdateCamera();

	if (this->keyboard->KeyDown(DIK_LEFT) && (!IsJump() || IsJumpNormalLeft())) {
		if (this->keyboard->KeyDown(DIK_L) && this->allowJump) {
			ActionJumpParabolLeft(_dt);
		}
		else if (IsJumpNormalLeft()) {
			ActionJumpRunNormalLeft(_dt);
		} else {
			ActionRunLeft(_dt);
		}
	}
	else if (this->keyboard->KeyDown(DIK_RIGHT) && (!IsJump() || IsJumpNormalRight())) {
		if (this->keyboard->KeyDown(DIK_L) && this->allowJump) {
			ActionJumpParabolRight(_dt);
		}
		else if (IsJumpNormalRight()) {
			ActionJumpRunNormalRight(_dt);
		}
		else {
			ActionRunRight(_dt);
		}
	}
	else if (this->keyboard->KeyDown(DIK_1)) {
		this->body->SetY(200);
	}
	else if (this->keyboard->KeyDown(DIK_K) && !IsActack()) {
		if (IsLeft()) {
			this->hurt->GetBody()->SetX(this->body->GetX());
			this->hurt->GetBody()->SetY(this->body->GetY()+this->body->GetHeight()/2);
			this->hurt->AttackLeft();
			this->control->changeState(new NinjaAttackLeft(this->graphics), this->GetBody());
		}
		else if (IsRight()) {
			this->hurt->GetBody()->SetX(this->body->GetX());
			this->hurt->GetBody()->SetY(this->body->GetY()+this->body->GetHeight()/2);
			this->hurt->AttackRight();
			this->control->changeState(new NinjaAttackRight(this->graphics), this->GetBody());
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
				this->control->changeState(new NinjaAttackLeft(this->graphics), this->GetBody());
			}
			else if (IsActackRight()) {
				this->control->changeState(new NinjaAttackRight(this->graphics), this->GetBody());
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
			else {
				if (IsLeft()) {
					ActionJumpNormalLeft(_dt);
				}
				else {
					ActionJumpNormalRight(_dt);
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
	this->allowJump = true;
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
	this->GetBody()->SetY(this->GetBody()->GetY() + 100);
}

void Ninja::ActionRunLeft(DWORD _dt)
{
	this->isRun = true;
	this->body->SetVelocityX(-0.2*_dt);
	float x = this->body->GetX() + this->body->GetVelocityX();
	this->body->SetX(x);
	this->control->changeState(new NinjaRunLeft(this->graphics), this->GetBody());
}

void Ninja::ActionRunRight(DWORD _dt)
{
	this->isRun = true;
	this->body->SetVelocityX(0.2*_dt);
	float x = this->body->GetX() + this->body->GetVelocityX();
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
	return (typeid(*this->control->getState()) == typeid(NinjaAttackLeft));
}

bool Ninja::IsActackRight()
{
	return (typeid(*this->control->getState()) == typeid(NinjaAttackRight));
}

bool Ninja::IsActack()
{
	return (IsActackLeft() || IsActackRight());
}

bool Ninja::IsJump()
{
	return (IsJumpVertical() || IsJumpParabol() || IsJumpNormal());
}

bool Ninja::IsJumpNormal()
{
	return (IsJumpNormalLeft() || IsJumpNormalRight());
}

bool Ninja::IsJumpNormalLeft()
{
	return (typeid(*this->control->getState()) == typeid(JumpNormalLeft));
}

bool Ninja::IsJumpNormalRight()
{
	return (typeid(*this->control->getState()) == typeid(JumpNormalRight));;
}

void Ninja::ActionJumpNormalLeft(DWORD _dt)
{
	this->control->changeState(new JumpNormalLeft(this->graphics), this->GetBody());
}

void Ninja::ActionJumpNormalRight(DWORD _dt)
{
	this->control->changeState(new JumpNormalRight(this->graphics), this->GetBody());
}

void Ninja::ActionJumpRunNormalLeft(DWORD _dt)
{
	this->body->SetVelocityX(-0.2);
	float x = this->body->GetX() + this->body->GetVelocityX()*_dt;
	this->body->SetX(x);
	this->control->changeState(new JumpNormalLeft(this->graphics), this->GetBody());
}

void Ninja::ActionJumpRunNormalRight(DWORD _dt)
{
	this->body->SetVelocityX(0.2);
	float x = this->body->GetX() + this->body->GetVelocityX()*_dt;
	this->body->SetX(x);
	this->control->changeState(new JumpNormalRight(this->graphics), this->GetBody());
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
	float y = -((x - 3)*(x - 5)*(x - 5)) - 7;

	this->body->SetY(this->body->GetY() + y);

	this->control->changeState(new JumpVerticalLeft(this->graphics), this->GetBody());
}

void Ninja::ActionJumpVerticalRight(DWORD _dt)
{
	float x = this->control->indexJumpVertical;
	float y = -((x - 3)*(x - 5)*(x - 5)) - 7;

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
	this->allowJump = false;

	float x = this->control->indexJumpParabol;
	float y = -((x - 3)*(x - 5)*(x - 5)) - 5;

	this->body->SetY(this->body->GetY() + y);
	this->body->SetX(this->body->GetX() + this->body->GetVelocityX());

	this->control->changeState(new JumpParabolLeft(this->graphics), this->GetBody());
}

void Ninja::ActionJumpParabolRight(DWORD _dt)
{
	this->allowJump = false;

	float x = this->control->indexJumpParabol;
	float y = -((x - 3)*(x - 5)*(x - 5)) - 5;


	this->body->SetY(this->body->GetY() + y);
	this->body->SetX(this->body->GetX() + this->body->GetVelocityX());
	this->control->changeState(new JumpParabolRight(this->graphics), this->GetBody());
}


bool Ninja::IsLeft()
{
	return (IsStandLeft() || IsRunLeft() || IsActackLeft() ||
		IsJumpVerticalLeft() || IsJumpParabolLeft() || IsJumpNormalLeft());
}

bool Ninja::IsRight()
{
	return (IsStandRight() || IsRunRight() || IsActackRight() ||
		IsJumpVerticalRight() || IsJumpParabolRight() || IsJumpNormalRight());
}

void Ninja::UpdateCamera()
{
	if (!updateCamera) return;

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

void Ninja::UpdateWeapon(DWORD _dt)
{	
	this->hurt->Update(_dt);
}