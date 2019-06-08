#include"Bird.h"
#include"BirdFlyLeft.h"
#include"BirdFlyRight.h"

Bird::Bird(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * camera, float _fX, float _fY, int _nWidth, int _nHeight, float _fVelocityX, float _fVelocityY) :Static(_lpD3ddv, camera, _fX, _fY, _nWidth, _nHeight, _fVelocityX, _fVelocityY)
{
	//this->GetBody()->SetVelocityX(-0.1f);
	this->graphics = new BirdGraphics(_lpD3ddv, camera, this->GetBody());
	this->control = new BirdControl(this->graphics, new BirdFlyLeft(this->graphics), this->GetBody());
}

Bird::~Bird()
{
}

void Bird::Update(DWORD _dt)
{
	BirdState* state = this->control->getState();

	if (this->GetBody()->GetVelocityX() > 0) {
		this->control->changeState(new BirdFlyRight(this->graphics), this->GetBody());
	}
	else {
		this->control->changeState(new BirdFlyLeft(this->graphics), this->GetBody());
	}
}

void Bird::ai(Box* box)
{
	this->obj = box;
}

void Bird::Dead()
{
	this->SetActive(false);
	this->GetBody()->SetX(-100);
	this->GetBody()->SetY(-100);
}
