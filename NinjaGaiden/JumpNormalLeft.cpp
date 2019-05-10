#include"JumpNormalLeft.h"

JumpNormalLeft::JumpNormalLeft(NinjaGraphics * _graphics)
{
	this->graphics = _graphics;
}

JumpNormalLeft::~JumpNormalLeft()
{

}

void JumpNormalLeft::update(Box* ninja) {
	this->graphics->jumpLeft(ninja->GetX(), ninja->GetY());
}