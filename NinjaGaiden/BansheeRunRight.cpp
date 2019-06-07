#include"BansheeRunRight.h"

BansheeRunRight::BansheeRunRight(BansheeGraphics* _graphics)
{
	this->graphics = _graphics;
}

BansheeRunRight::~BansheeRunRight()
{
}

void BansheeRunRight::update(Box* banshee) {
	this->graphics->runRight(banshee->GetX(), banshee->GetY());

}