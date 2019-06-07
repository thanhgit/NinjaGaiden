#include"MachineGunGuySitGraphics.h"

MachineGunGuySitGraphics::MachineGunGuySitGraphics(LPDIRECT3DDEVICE9 _lpD3ddv, Camera * _camera, Box* _body)
{
	this->lpD3ddv = _lpD3ddv;
	this->camera = _camera;
	this->body = body;
	this->machineGunGuySit = new Sprite(this->lpD3ddv, this->camera, L"data/Resources/enemy/machinegunguysit.png", 6, 6, 33, 30);
}

MachineGunGuySitGraphics::~MachineGunGuySitGraphics()
{
	if (this->lpD3ddv) {
		this->lpD3ddv->Release();
	}
}


void MachineGunGuySitGraphics::sitLeft(float fX, float fY)
{
	this->machineGunGuySit->SetIndex(0);

	this->machineGunGuySit->Draw(fX, fY);
	this->machineGunGuySit->Next();
}

void MachineGunGuySitGraphics::sitRight(float fX, float fY)
{
	this->machineGunGuySit->SetIndex(3);

	this->machineGunGuySit->Draw(fX, fY);
	this->machineGunGuySit->Next();
}


