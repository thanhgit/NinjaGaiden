#include"JumpParabolLeft.h"

JumpParabolLeft::JumpParabolLeft(NinjaGraphics * _graphics)
{
	this->graphics = _graphics;
}

JumpParabolLeft::~JumpParabolLeft()
{

}

void JumpParabolLeft::update(Box* ninja) {
	this->graphics->jumpParabolLeft(ninja->GetX(), ninja->GetY());
}