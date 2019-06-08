#include"Boss3JumpRight.h"

Boss3JumpRight::Boss3JumpRight(Boss3Graphics* _graphics)
{
	this->graphics = _graphics;
}

Boss3JumpRight::~Boss3JumpRight()
{
	if (this->graphics != nullptr) {
		delete this->graphics;
	}
}

void Boss3JumpRight::update(Box* boss3) {
	this->graphics->jumpRight(boss3->GetX(), boss3->GetY());
}