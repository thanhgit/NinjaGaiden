#include"MachineGunGuyGraphics.h"

MachineGunGuyGraphics::MachineGunGuyGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->machineGunGuy = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/machinegunguy.png", 8, 8, 25, 33);
}

MachineGunGuyGraphics::~MachineGunGuyGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void MachineGunGuyGraphics::runLeft(float fX, float fY)
{
	int index = this->machineGunGuy->GetIndex();
	if (index > 1) {
		this->machineGunGuy->SetIndex(0);
	}

	this->machineGunGuy->Draw(fX, fY);
	this->machineGunGuy->Next();
}

void MachineGunGuyGraphics::runRight(float fX, float fY)
{
	int index = this->machineGunGuy->GetIndex();
	if (index < 4 || index > 5) {
		this->machineGunGuy->SetIndex(4);
	}

	this->machineGunGuy->Draw(fX, fY);
	this->machineGunGuy->Next();
}


