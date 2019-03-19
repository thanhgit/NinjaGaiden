#include"SwordManControl.h"



#include"JumpParabolRight.h"

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