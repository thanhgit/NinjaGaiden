#include"BirdFlyLeft.h"

BirdFlyLeft::BirdFlyLeft(BirdGraphics * _graphics)
{
	this->graphics = _graphics;
}

BirdFlyLeft::~BirdFlyLeft()
{

}

void BirdFlyLeft::update(Box* bird) {
	this->graphics->flyLeft(bird->GetX(), bird->GetY());
}