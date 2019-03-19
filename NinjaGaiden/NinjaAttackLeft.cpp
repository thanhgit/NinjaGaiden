#include"NinjaAttackLeft.h"

NinjaAttackLeft::NinjaAttackLeft(NinjaGraphics * _graphics)
{
	this->graphics = _graphics;
}

NinjaAttackLeft::~NinjaAttackLeft()
{

}

void NinjaAttackLeft::update(Box* ninja) {
	this->graphics->actackLeft(ninja->GetX(), ninja->GetY());
}