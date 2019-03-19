#include"SwordManAttackLeft.h"

SwordManAttackLeft::SwordManAttackLeft(SwordManGraphics * _graphics)
{
	this->graphics = _graphics;
}

SwordManAttackLeft::~SwordManAttackLeft()
{

}

void SwordManAttackLeft::update(Box* ninja) {
	this->graphics->actackLeft(ninja->GetX(), ninja->GetY());
}