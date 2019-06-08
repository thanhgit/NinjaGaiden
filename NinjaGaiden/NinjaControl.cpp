#include"NinjaControl.h"

#include"NinjaStandRight.h"
#include"NinjaStandLeft.h"
#include"NinjaRunLeft.h"
#include"NinjaRunRight.h"
// stand actack
#include"NinjaAttackLeft.h"
#include"NinjaAttackRight.h"

// jump
#include"JumpNormalLeft.h"
#include"JumpNormalRight.h"
#include"JumpVerticalLeft.h"
#include"JumpVerticalRight.h"
#include"JumpParabolLeft.h"
#include"JumpParabolRight.h"

#include<typeinfo>

NinjaControl::NinjaControl(NinjaGraphics * _graphics, NinjaState * ninjaState, Box * ninja)
{
	this->graphics = _graphics;
	this->ninja = ninja;
	this->state = ninjaState;
	this->state->update(this->ninja);
}

NinjaControl::NinjaControl(NinjaState* _state, Box* _ninja)
{
	this->ninja = _ninja;
	this->state = _state;
	this->state->update(this->ninja);
}

NinjaControl::~NinjaControl()
{
}

void NinjaControl::changeState(NinjaState * _state, Box* _ninja)
{
	this->ninja = _ninja;
	this->state = _state;
	
	if (SameType(new NinjaStandLeft()) || SameType(new NinjaStandRight())) {
		this->indexJumpVertical = 0;
		this->indexJumpParabol = 0;
	} 
	else if (SameType(new NinjaRunLeft()) || SameType(new NinjaRunRight())) {
		this->indexJumpVertical = 0;
		this->indexJumpParabol = 0;

		if (this->indexRun > 3) {
			this->indexRun = 0;
			if (SameType(new NinjaRunLeft())) {
				this->state = new NinjaRunLeft(this->graphics);
			}
			else {
				this->state = new NinjaRunRight(this->graphics);
			}
		}
		else {
			this->indexRun++;
			Sleep(Utils::NINJA_ANIMATE_TIME);
		}
	}
	else if (SameType(new NinjaAttackLeft()) || SameType(new NinjaAttackRight())) {
		this->indexJumpVertical = 0;
		this->indexJumpParabol = 0;

		if (this->indexActack > 3) {
			this->indexActack = 0;
			if (SameType(new NinjaAttackLeft())) {
				this->state = new NinjaStandLeft(this->graphics);
			}
			else {
				this->state = new NinjaStandRight(this->graphics);
			}
		}
		else {
			this->indexActack++;
			Sleep(Utils::NINJA_ANIMATE_TIME);
		}
	}
	else if (SameType(new JumpVerticalLeft()) || SameType(new JumpVerticalRight())) {
		if (this->indexJumpVertical > 6) {
			this->indexJumpVertical = 0;
			if (SameType(new JumpVerticalLeft())) {
				this->state = new JumpNormalLeft(this->graphics);
			}
			else {
				this->state = new JumpNormalRight(this->graphics);
			}
		}
		else {
			this->indexJumpVertical++;
			Sleep(Utils::NINJA_ANIMATE_TIME);
		}
	}
	else if (SameType(new JumpParabolLeft()) || SameType(new JumpParabolRight())) {
		if (this->indexJumpParabol > 5) {
			this->indexJumpParabol = 0;
			if (SameType(new JumpParabolLeft())) {
				this->state = new JumpNormalLeft(this->graphics);
			}
			else {
				this->state = new JumpNormalRight(this->graphics);
			}
		}
		else {
			this->indexJumpParabol++;
			Sleep(Utils::NINJA_ANIMATE_TIME);
		}
	}

	this->state->update(this->ninja);
}

NinjaState * NinjaControl::getState()
{
	return this->state;
}

bool NinjaControl::SameType(NinjaState * _state)
{
	return (typeid(*this->state) == typeid(*_state));
}