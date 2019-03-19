#include"SwordManRunLeft.h"

SwordManRunLeft::SwordManRunLeft(SwordManGraphics * _graphics)
{
	this->graphics = _graphics;
}

SwordManRunLeft::~SwordManRunLeft()
{

}

void SwordManRunLeft::update(Box* swordMan) {
	this->graphics->runLeft(swordMan->GetX(), swordMan->GetY());
}