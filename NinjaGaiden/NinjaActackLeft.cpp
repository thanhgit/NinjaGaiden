#include"NinjaActackLeft.h"

NinjaActackLeft::NinjaActackLeft(NinjaGraphics * _graphics)
{
	this->graphics = _graphics;
}

NinjaActackLeft::~NinjaActackLeft()
{

}

void NinjaActackLeft::update(Box* ninja) {
	this->graphics->actackLeft(ninja->GetX(), ninja->GetY());
}