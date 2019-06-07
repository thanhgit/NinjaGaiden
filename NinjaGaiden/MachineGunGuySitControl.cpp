#include"MachineGunGuySitControl.h"

#include"MachineGunGuySitSitLeft.h"
#include"MachineGunGuySitSitRight.h"

#include<typeinfo>

MachineGunGuySitControl::MachineGunGuySitControl(MachineGunGuySitGraphics * _graphics, MachineGunGuySitState * machineGunGuySittate, Box * machineGunGuySit)
{
	this->graphics = _graphics;
	this->machineGunGuySit = machineGunGuySit;
	this->state = machineGunGuySittate;
	this->state->update(this->machineGunGuySit);
}

MachineGunGuySitControl::MachineGunGuySitControl(MachineGunGuySitState* _state, Box* _machineGunGuySit)
{
	this->machineGunGuySit = _machineGunGuySit;
	this->state = _state;
	this->state->update(this->machineGunGuySit);
}

MachineGunGuySitControl::~MachineGunGuySitControl()
{
}

void MachineGunGuySitControl::changeState(MachineGunGuySitState * _state, Box* _machineGunGuySit)
{

	this->machineGunGuySit = _machineGunGuySit;
	this->state = _state;
	if (SameType(new MachineGunGuySitSitLeft()) || SameType(new MachineGunGuySitSitRight())) {
		if (this->indexRun > 2) {
			this->indexRun = 0;
			if (SameType(new MachineGunGuySitSitLeft())) {
				this->state = new MachineGunGuySitSitLeft(this->graphics);
			}
			else {
				this->state = new MachineGunGuySitSitRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(Utils::ANIMATE_TIME);
		}
	}

	this->state->update(this->machineGunGuySit);
}

MachineGunGuySitState * MachineGunGuySitControl::getState()
{
	return this->state;
}

bool MachineGunGuySitControl::SameType(MachineGunGuySitState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}