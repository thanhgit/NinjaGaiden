#include"MachineGunGuyControl.h"

#include"MachineGunGuyRunLeft.h"
#include"MachineGunGuyRunRight.h"

#include<typeinfo>

MachineGunGuyControl::MachineGunGuyControl(MachineGunGuyGraphics * _graphics, MachineGunGuyState * machineGunGuyState, Box * machineGunGuy)
{
	this->graphics = _graphics;
	this->machineGunGuy = machineGunGuy;
	this->state = machineGunGuyState;
	this->state->update(this->machineGunGuy);
}

MachineGunGuyControl::MachineGunGuyControl(MachineGunGuyState* _state, Box* _machineGunGuy)
{
	this->machineGunGuy = _machineGunGuy;
	this->state = _state;
	this->state->update(this->machineGunGuy);
}

MachineGunGuyControl::~MachineGunGuyControl()
{
}

void MachineGunGuyControl::changeState(MachineGunGuyState * _state, Box* _machineGunGuy)
{

	this->machineGunGuy = _machineGunGuy;
	this->state = _state;
	if (SameType(new MachineGunGuyRunLeft()) || SameType(new MachineGunGuyRunRight())) {
		if (this->indexRun > 2) {
			this->indexRun = 0;
			if (SameType(new MachineGunGuyRunLeft())) {
				this->state = new MachineGunGuyRunLeft(this->graphics);
			}
			else {
				this->state = new MachineGunGuyRunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(Utils::ANIMATE_TIME);
		}
	}

	this->state->update(this->machineGunGuy);
}

MachineGunGuyState * MachineGunGuyControl::getState()
{
	return this->state;
}

bool MachineGunGuyControl::SameType(MachineGunGuyState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}