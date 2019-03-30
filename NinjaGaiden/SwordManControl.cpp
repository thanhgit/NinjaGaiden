#include"SwordManControl.h"

#include"SwordManRunLeft.h"
#include"SwordManRunRight.h"
#include"SwordManAttackLeft.h"
#include"SwordManAttackRight.h"

#include<typeinfo>

SwordManControl::SwordManControl(SwordManGraphics * _graphics, SwordManState * swordManState, Box * swordMan)
{
	this->graphics = _graphics;
	this->swordMan = swordMan;
	this->state = swordManState;
	this->state->update(this->swordMan);
}

SwordManControl::SwordManControl(SwordManState* _state, Box* _swordMan)
{
	this->swordMan = _swordMan;
	this->state = _state;
	this->state->update(this->swordMan);
}

SwordManControl::~SwordManControl()
{
}

void SwordManControl::changeState(SwordManState * _state, Box* _swordMan)
{

	this->swordMan = _swordMan;
	this->state = _state;
	if (SameType(new SwordManRunLeft()) || SameType(new SwordManRunRight())) {
		if (this->indexRun > 3) {
			this->indexRun = 0;
			if (SameType(new SwordManRunLeft())) {
				this->state = new SwordManRunLeft(this->graphics);
			}
			else {
				this->state = new SwordManRunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(20);
		}
	}

	this->state->update(this->swordMan);
}

SwordManState * SwordManControl::getState()
{
	return this->state;
}

bool SwordManControl::SameType(SwordManState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}