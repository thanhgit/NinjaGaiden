#include"BatBrownControl.h"

#include"BatBrownRunLeft.h"
#include"BatBrownRunRight.h"

#include<typeinfo>

BatBrownControl::BatBrownControl(BatBrownGraphics * _graphics, BatBrownState * batBrownState, Box * batBrown)
{
	this->graphics = _graphics;
	this->batBrown = batBrown;
	this->state = batBrownState;
	this->state->update(this->batBrown);
}

BatBrownControl::BatBrownControl(BatBrownState* _state, Box* _batBrown)
{
	this->batBrown = _batBrown;
	this->state = _state;
	this->state->update(this->batBrown);
}

BatBrownControl::~BatBrownControl()
{
}

void BatBrownControl::changeState(BatBrownState * _state, Box* _batBrown)
{

	this->batBrown = _batBrown;
	this->state = _state;
	if (SameType(new BatBrownRunLeft()) || SameType(new BatBrownRunRight())) {
		if (this->indexRun > 2) {
			this->indexRun = 0;
			if (SameType(new BatBrownRunLeft())) {
				this->state = new BatBrownRunLeft(this->graphics);
			}
			else {
				this->state = new BatBrownRunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(Utils::ANIMATE_TIME);
		}
	}

	this->state->update(this->batBrown);
}

BatBrownState * BatBrownControl::getState()
{
	return this->state;
}

bool BatBrownControl::SameType(BatBrownState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}