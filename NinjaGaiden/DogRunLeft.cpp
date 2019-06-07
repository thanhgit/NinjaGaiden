#include"DogRunLeft.h"

DogRunLeft::DogRunLeft(DogGraphics * _graphics)
{
	this->graphics = _graphics;
}

DogRunLeft::~DogRunLeft()
{

}

void DogRunLeft::update(Box* dog) {
	this->graphics->runLeft(dog->GetX(), dog->GetY());
}