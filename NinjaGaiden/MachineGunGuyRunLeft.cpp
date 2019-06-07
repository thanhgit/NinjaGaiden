#include"MachineGunGuyRunLeft.h"

MachineGunGuyRunLeft::MachineGunGuyRunLeft(MachineGunGuyGraphics * _graphics)
{
	this->graphics = _graphics;
}

MachineGunGuyRunLeft::~MachineGunGuyRunLeft()
{

}

void MachineGunGuyRunLeft::update(Box* machineGunGuy) {
	this->graphics->runLeft(machineGunGuy->GetX(), machineGunGuy->GetY());
}