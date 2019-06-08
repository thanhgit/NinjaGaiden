#include"Boss3JumpLeft.h"

Boss3JumpLeft::Boss3JumpLeft(Boss3Graphics* _graphics)
{
	this->graphics = _graphics;
}

Boss3JumpLeft::~Boss3JumpLeft()
{

}

void Boss3JumpLeft::update(Box* boss3) {
	this->graphics->jumpLeft(boss3->GetX(), boss3->GetY());
}