#include"NinjaStandRight.h"

NinjaStandRight::NinjaStandRight(NinjaGraphics* _graphics)
{
	this->graphics = _graphics;
}

NinjaStandRight::~NinjaStandRight()
{
}

void NinjaStandRight::update(Box* ninja) {
	this->graphics->standRight(ninja->GetX(), ninja->GetY());
}