#include"SwordManAttackRight.h"

SwordManAttackRight::SwordManAttackRight(SwordManGraphics* _graphics)
{
	this->graphics = _graphics;
}

SwordManAttackRight::~SwordManAttackRight()
{
}

void SwordManAttackRight::update(Box* swordMan) {
	this->graphics->actackRight(swordMan->GetX(), swordMan->GetY());

}