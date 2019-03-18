#include"JumpVerticalRight.h"

JumpVerticalRight::JumpVerticalRight(NinjaGraphics* _graphics)
{
	this->graphics = _graphics;
}

JumpVerticalRight::~JumpVerticalRight()
{
}

void JumpVerticalRight::update(Box* ninja) {
	this->graphics->jumpVerticalRight(ninja->GetX(), ninja->GetY());

}