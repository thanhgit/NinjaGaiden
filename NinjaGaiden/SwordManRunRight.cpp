#include"SwordManRunRight.h"

SwordManRunRight::SwordManRunRight(SwordManGraphics* _graphics)
{
	this->graphics = _graphics;
}

SwordManRunRight::~SwordManRunRight()
{
}

void SwordManRunRight::update(Box* swordMan) {
	this->graphics->runRight(swordMan->GetX(), swordMan->GetY());

}