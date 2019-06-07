#include"BirdControl.h"

#include"BirdFlyLeft.h"
#include"BirdFlyRight.h"

#include<typeinfo>

BirdControl::BirdControl(BirdGraphics * _graphics, BirdState * birdtate, Box * bird)
{
	this->graphics = _graphics;
	this->bird = bird;
	this->state = birdtate;
	this->state->update(this->bird);
}

BirdControl::BirdControl(BirdState* _state, Box* _bird)
{
	this->bird = _bird;
	this->state = _state;
	this->state->update(this->bird);
}

BirdControl::~BirdControl()
{
}

void BirdControl::changeState(BirdState * _state, Box* _bird)
{

	this->bird = _bird;
	this->state = _state;
	if (SameType(new BirdFlyLeft()) || SameType(new BirdFlyRight())) {
		if (this->indexFly > 2) {
			this->indexFly = 0;
			if (SameType(new BirdFlyLeft())) {
				this->state = new BirdFlyLeft(this->graphics);
			}
			else {
				this->state = new BirdFlyRight(this->graphics);
			}
		}
		else {
			this->indexFly++;
			Sleep(Utils::ANIMATE_TIME);
		}
	}

	this->state->update(this->bird);
}

BirdState * BirdControl::getState()
{
	return this->state;
}

bool BirdControl::SameType(BirdState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}