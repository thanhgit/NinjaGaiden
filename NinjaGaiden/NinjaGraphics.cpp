#include"NinjaGraphics.h"

NinjaGraphics::NinjaGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->ninja = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/ninja/run.png", 8, 8, 23, 32);

	// stand actack
	this->ninjaActack = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/ninja/attack.png", 8, 8, 41, 32);

	// jump
	this->ninjaJump = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/ninja/jump.png", 8, 8, 21, 22);
}

NinjaGraphics::~NinjaGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}

void NinjaGraphics::standLeft(float fX, float fY)
{
	this->ninja->SetIndex(0);
	this->ninja->Draw(fX, fY);
}

void NinjaGraphics::standRight(float fX, float fY)
{
	this->ninja->SetIndex(4);
	this->ninja->Draw(fX, fY);
}


void NinjaGraphics::runLeft(float fX, float fY)
{
	int index = this->ninja->GetIndex();
	if (index > 3 || index <1) {
		this->ninja->SetIndex(1);
	}

	this->ninja->Draw(fX, fY);
	this->ninja->Next();
}

void NinjaGraphics::runRight(float fX, float fY)
{
	int index = this->ninja->GetIndex();
	if (index > 7 || index <5) {
		this->ninja->SetIndex(5);
	}

	this->ninja->Draw(fX, fY);
	this->ninja->Next();
}

void NinjaGraphics::jumpVerticalLeft(float fX, float fY)
{
	int index = this->ninjaJump->GetIndex();
	if (index > 3) {
		this->ninjaJump->SetIndex(0);
	}

	this->ninjaJump->Draw(fX, fY);
	this->ninjaJump->Next();
}

void NinjaGraphics::jumpVerticalRight(float fX, float fY)
{
	int index = this->ninjaJump->GetIndex();
	if (index < 4) {
		this->ninjaJump->SetIndex(4);
	}

	this->ninjaJump->Draw(fX, fY);
	this->ninjaJump->Next();
}

void NinjaGraphics::jumpParabolLeft(float fX, float fY)
{
	int index = this->ninjaJump->GetIndex();
	if (index > 3) {
		this->ninjaJump->SetIndex(0);
	}

	this->ninjaJump->Draw(fX, fY);
	this->ninjaJump->Next();
}

void NinjaGraphics::jumpParabolRight(float fX, float fY)
{
	int index = this->ninjaJump->GetIndex();
	if (index < 4) {
		this->ninjaJump->SetIndex(4);
	}

	this->ninjaJump->Draw(fX, fY);
	this->ninjaJump->Next();
}


// stand actack
void NinjaGraphics::actackLeft(float fX, float fY)
{
	int index = this->ninjaActack->GetIndex();

	if (index > 3) {
		this->ninjaActack->SetIndex(0);
	}

	this->ninjaActack->Draw(fX - 20, fY);
	
	this->ninjaActack->Next();
}

void NinjaGraphics::actackRight(float fX, float fY)
{
	int index = this->ninjaActack->GetIndex();

	if (index <4) {
		this->ninjaActack->SetIndex(4);
	}

	this->ninjaActack->Draw(fX, fY);
	this->ninjaActack->Next();
}

