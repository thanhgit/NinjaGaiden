#include"BatBrownRunRight.h"

BatBrownRunRight::BatBrownRunRight(BatBrownGraphics* _graphics)
{
	this->graphics = _graphics;
}

BatBrownRunRight::~BatBrownRunRight()
{
}

void BatBrownRunRight::update(Box* batBrown) {
	this->graphics->runRight(batBrown->GetX(), batBrown->GetY());

}