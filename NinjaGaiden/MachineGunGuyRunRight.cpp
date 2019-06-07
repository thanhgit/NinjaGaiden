#include"MachineGunGuyRunRight.h"

MachineGunGuyRunRight::MachineGunGuyRunRight(MachineGunGuyGraphics* _graphics)
{
	this->graphics = _graphics;
}

MachineGunGuyRunRight::~MachineGunGuyRunRight()
{
}

void MachineGunGuyRunRight::update(Box* machineGunGuy) {
	this->graphics->runRight(machineGunGuy->GetX(), machineGunGuy->GetY());

}