#include"BirdBrownRunLeft.h"

BirdBrownRunLeft::BirdBrownRunLeft(BirdBrownGraphics * _graphics)
{
	this->graphics = _graphics;
}

BirdBrownRunLeft::~BirdBrownRunLeft()
{

}

void BirdBrownRunLeft::update(Box* birdBrown) {
	this->graphics->runLeft(birdBrown->GetX(), birdBrown->GetY());
}