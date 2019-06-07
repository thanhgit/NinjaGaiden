#include"Boss3StandRight.h"

Boss3StandRight::Boss3StandRight(Boss3Graphics* _graphics)
{
	this->graphics = _graphics;
}

Boss3StandRight::~Boss3StandRight()
{
}

void Boss3StandRight::update(Box* boss3) {
	this->graphics->standRight(boss3->GetX(), boss3->GetY());

}