#include"NinjaAttackRight.h"

NinjaAttackRight::NinjaAttackRight(NinjaGraphics* _graphics)
{
	this->graphics = _graphics;
}

NinjaAttackRight::~NinjaAttackRight()
{
}

void NinjaAttackRight::update(Box* ninja) {
	this->graphics->actackRight(ninja->GetX(), ninja->GetY());

}