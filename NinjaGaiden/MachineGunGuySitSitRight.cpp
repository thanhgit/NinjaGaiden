#include"MachineGunGuySitSitRight.h"

MachineGunGuySitSitRight::MachineGunGuySitSitRight(MachineGunGuySitGraphics* _graphics)
{
	this->graphics = _graphics;
}

MachineGunGuySitSitRight::~MachineGunGuySitSitRight()
{
}

void MachineGunGuySitSitRight::update(Box* machineGunGuySit) {
	this->graphics->sitRight(machineGunGuySit->GetX(), machineGunGuySit->GetY());

}