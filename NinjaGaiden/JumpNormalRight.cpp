#include"JumpNormalRight.h"

JumpNormalRight::JumpNormalRight(NinjaGraphics* _graphics)
{
	this->graphics = _graphics;
}

JumpNormalRight::~JumpNormalRight()
{
}

void JumpNormalRight::update(Box* ninja) {
	this->graphics->jumpRight(ninja->GetX(), ninja->GetY());

}