#include"MachineGunGuySitSitLeft.h"

MachineGunGuySitSitLeft::MachineGunGuySitSitLeft(MachineGunGuySitGraphics * _graphics)
{
	this->graphics = _graphics;
}

MachineGunGuySitSitLeft::~MachineGunGuySitSitLeft()
{

}

void MachineGunGuySitSitLeft::update(Box* machineGunGuySit) {
	this->graphics->sitLeft(machineGunGuySit->GetX(), machineGunGuySit->GetY());
}