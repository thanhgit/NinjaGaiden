#include"Boss3Control.h"

#include"Boss3StandLeft.h"
#include"Boss3StandRight.h"
#include"Boss3JumpLeft.h"
#include"Boss3JumpRight.h"

#include<typeinfo>

Boss3Control::Boss3Control(Boss3Graphics * _graphics, Boss3State * boss3State, Box * boss3)
{
	this->graphics = _graphics;
	this->boss3 = boss3;
	this->state = boss3State;
	this->state->update(this->boss3);
}

Boss3Control::Boss3Control(Boss3State* _state, Box* _boss3)
{
	this->boss3 = _boss3;
	this->state = _state;
	this->state->update(this->boss3);
}

Boss3Control::~Boss3Control()
{
}

void Boss3Control::changeState(Boss3State * _state, Box* _boss3)
{

	this->boss3 = _boss3;
	this->state = _state;
	if (SameType(new Boss3StandLeft()) || SameType(new Boss3StandRight())) {
		if (SameType(new Boss3StandLeft())) {
			this->state = new Boss3StandLeft(this->graphics);
		}
		else {
			this->state = new Boss3StandRight(this->graphics);
		}

		Sleep(Utils::ANIMATE_TIME + 50);

	}
	else if (SameType(new Boss3JumpLeft()) || SameType(new Boss3JumpRight())) {
		if (this->indexJump > 6) {
			if (SameType(new Boss3JumpLeft())) {
				this->state = new Boss3StandLeft();
			}
			else {
				this->state = new Boss3StandRight();
			}
		}
		else {
			this->indexJump++;
			Sleep(Utils::ANIMATE_TIME);
		}
		
	}

	this->state->update(this->boss3);
}

Boss3State * Boss3Control::getState()
{
	return this->state;
}

bool Boss3Control::SameType(Boss3State * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}