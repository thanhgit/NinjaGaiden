#include"DogControl.h"

#include"DogRunLeft.h"
#include"DogRunRight.h"

#include<typeinfo>

DogControl::DogControl(DogGraphics * _graphics, DogState * dogtate, Box * dog)
{
	this->graphics = _graphics;
	this->dog = dog;
	this->state = dogtate;
	this->state->update(this->dog);
}

DogControl::DogControl(DogState* _state, Box* _dog)
{
	this->dog = _dog;
	this->state = _state;
	this->state->update(this->dog);
}

DogControl::~DogControl()
{
}

void DogControl::changeState(DogState * _state, Box* _dog)
{

	this->dog = _dog;
	this->state = _state;
	if (SameType(new DogRunLeft()) || SameType(new DogRunRight())) {
		if (this->indexRun > 2) {
			this->indexRun = 0;
			if (SameType(new DogRunLeft())) {
				this->state = new DogRunLeft(this->graphics);
			}
			else {
				this->state = new DogRunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(Utils::ANIMATE_TIME);
		}
	}

	this->state->update(this->dog);
}

DogState * DogControl::getState()
{
	return this->state;
}

bool DogControl::SameType(DogState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}