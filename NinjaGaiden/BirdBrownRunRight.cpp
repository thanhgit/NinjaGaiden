#include"BirdBrownRunRight.h"

BirdBrownRunRight::BirdBrownRunRight(BirdBrownGraphics* _graphics)
{
	this->graphics = _graphics;
}

BirdBrownRunRight::~BirdBrownRunRight()
{
}

void BirdBrownRunRight::update(Box* birdBrown) {
	this->graphics->runRight(birdBrown->GetX(), birdBrown->GetY());

}