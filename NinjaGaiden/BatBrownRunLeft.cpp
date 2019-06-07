#include"BatBrownRunLeft.h"

BatBrownRunLeft::BatBrownRunLeft(BatBrownGraphics * _graphics)
{
	this->graphics = _graphics;
}

BatBrownRunLeft::~BatBrownRunLeft()
{

}

void BatBrownRunLeft::update(Box* batBrown) {
	this->graphics->runLeft(batBrown->GetX(), batBrown->GetY());
}