#include"BansheeControl.h"

#include"BansheeRunLeft.h"
#include"BansheeRunRight.h"

#include<typeinfo>

BansheeControl::BansheeControl(BansheeGraphics * _graphics, BansheeState * bansheeState, Box * banshee)
{
	this->graphics = _graphics;
	this->banshee = banshee;
	this->state = bansheeState;
	this->state->update(this->banshee);
}

BansheeControl::BansheeControl(BansheeState* _state, Box* _banshee)
{
	this->banshee = _banshee;
	this->state = _state;
	this->state->update(this->banshee);
}

BansheeControl::~BansheeControl()
{
}

void BansheeControl::changeState(BansheeState * _state, Box* _banshee)
{
	this->banshee = _banshee;
	this->state = _state;
	if (SameType(new BansheeRunLeft()) || SameType(new BansheeRunRight())) {
		if (this->indexRun > 2) {
			this->indexRun = 0;
			if (SameType(new BansheeRunLeft())) {
				this->state = new BansheeRunLeft(this->graphics);
			}
			else {
				this->state = new BansheeRunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(Utils::ANIMATE_TIME);
		}
	}

	this->state->update(this->banshee);
}

BansheeState * BansheeControl::getState()
{
	return this->state;
}

bool BansheeControl::SameType(BansheeState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}