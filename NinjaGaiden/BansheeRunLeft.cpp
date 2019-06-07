#include"BansheeRunLeft.h"

BansheeRunLeft::BansheeRunLeft(BansheeGraphics * _graphics)
{
	this->graphics = _graphics;
}

BansheeRunLeft::~BansheeRunLeft()
{

}

void BansheeRunLeft::update(Box* banshee) {
	this->graphics->runLeft(banshee->GetX(), banshee->GetY());
}