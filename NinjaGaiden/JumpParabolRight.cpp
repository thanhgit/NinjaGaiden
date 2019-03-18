#include"JumpParabolRight.h"

JumpParabolRight::JumpParabolRight(NinjaGraphics* _graphics)
{
	this->graphics = _graphics;
}

JumpParabolRight::~JumpParabolRight()
{
}

void JumpParabolRight::update(Box* ninja) {
	this->graphics->jumpParabolRight(ninja->GetX(), ninja->GetY());

}