#include"Boss3StandLeft.h"

Boss3StandLeft::Boss3StandLeft(Boss3Graphics * _graphics)
{
	this->graphics = _graphics;
}

Boss3StandLeft::~Boss3StandLeft()
{

}

void Boss3StandLeft::update(Box* boss3) {
	this->graphics->standLeft(boss3->GetX(), boss3->GetY());
}