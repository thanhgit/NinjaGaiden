#include"NinjaActackRight.h"

NinjaActackRight::NinjaActackRight(NinjaGraphics* _graphics)
{
	this->graphics = _graphics;
}

NinjaActackRight::~NinjaActackRight()
{
}

void NinjaActackRight::update(Box* ninja) {
	this->graphics->actackRight(ninja->GetX(), ninja->GetY());

}