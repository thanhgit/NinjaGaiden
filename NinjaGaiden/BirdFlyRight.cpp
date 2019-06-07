#include"BirdFlyRight.h"

BirdFlyRight::BirdFlyRight(BirdGraphics* _graphics)
{
	this->graphics = _graphics;
}

BirdFlyRight::~BirdFlyRight()
{
}

void BirdFlyRight::update(Box* bird ){
	this->graphics->flyRight(bird->GetX(), bird->GetY());

}