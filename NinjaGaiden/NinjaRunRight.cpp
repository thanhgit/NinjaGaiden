#include"NinjaRunRight.h"

NinjaRunRight::NinjaRunRight(NinjaGraphics* _graphics)
{
	this->graphics = _graphics;
}

NinjaRunRight::~NinjaRunRight()
{
}

void NinjaRunRight::update(Box* ninja) {
	this->graphics->runRight(ninja->GetX(), ninja->GetY());

}