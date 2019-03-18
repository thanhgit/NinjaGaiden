#include"NinjaRunLeft.h"

NinjaRunLeft::NinjaRunLeft(NinjaGraphics * _graphics)
{
	this->graphics = _graphics;
}

NinjaRunLeft::~NinjaRunLeft()
{

}

void NinjaRunLeft::update(Box* ninja) {
	this->graphics->runLeft(ninja->GetX(), ninja->GetY());
}