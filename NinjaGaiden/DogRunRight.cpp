#include"DogRunRight.h"

DogRunRight::DogRunRight(DogGraphics* _graphics)
{
	this->graphics = _graphics;
}

DogRunRight::~DogRunRight()
{
}

void DogRunRight::update(Box* dog) {
	this->graphics->runRight(dog->GetX(), dog->GetY());

}