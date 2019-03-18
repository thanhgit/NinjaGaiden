#include"JumpVerticalLeft.h"

JumpVerticalLeft::JumpVerticalLeft(NinjaGraphics * _graphics)
{
	this->graphics = _graphics;
}

JumpVerticalLeft::~JumpVerticalLeft()
{

}

void JumpVerticalLeft::update(Box* ninja) {
	this->graphics->jumpVerticalLeft(ninja->GetX(), ninja->GetY());
}