#include"NinjaStandLeft.h"

NinjaStandLeft::NinjaStandLeft(NinjaGraphics* _graphics)
{
	this->graphics = _graphics;
}

NinjaStandLeft::~NinjaStandLeft()
{
}

void NinjaStandLeft::update(Box* ninja) {
	this->graphics->standLeft(ninja->GetX(), ninja->GetY());
}