#include"BirdBrownControl.h"

#include"BirdBrownRunLeft.h"
#include"BirdBrownRunRight.h"

#include<typeinfo>

BirdBrownControl::BirdBrownControl(BirdBrownGraphics * _graphics, BirdBrownState * birdBrownState, Box * birdBrown)
{
	this->graphics = _graphics;
	this->birdBrown = birdBrown;
	this->state = birdBrownState;
	this->state->update(this->birdBrown);
}

BirdBrownControl::BirdBrownControl(BirdBrownState* _state, Box* _birdBrown)
{
	this->birdBrown = _birdBrown;
	this->state = _state;
	this->state->update(this->birdBrown);
}

BirdBrownControl::~BirdBrownControl()
{
}

void BirdBrownControl::changeState(BirdBrownState * _state, Box* _birdBrown)
{

	this->birdBrown = _birdBrown;
	this->state = _state;
	if (SameType(new BirdBrownRunLeft()) || SameType(new BirdBrownRunRight())) {
		if (this->indexRun > 2) {
			this->indexRun = 0;
			if (SameType(new BirdBrownRunLeft())) {
				this->state = new BirdBrownRunLeft(this->graphics);
			}
			else {
				this->state = new BirdBrownRunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(10);
		}
	}

	this->state->update(this->birdBrown);
}

BirdBrownState * BirdBrownControl::getState()
{
	return this->state;
}

bool BirdBrownControl::SameType(BirdBrownState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}