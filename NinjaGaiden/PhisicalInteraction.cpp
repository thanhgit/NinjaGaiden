#include"PhysicalInteraction.h"

PhysicalInteraction::PhysicalInteraction(Ninja * _ninja)
{
	this->ninja = _ninja;
	this->objWithMap = new ObjectWithMap(this->ninja);
}

PhysicalInteraction::~PhysicalInteraction()
{
}

void PhysicalInteraction::update()
{
	this->objWithMap->interact();
}

void PhysicalInteraction::SetEnemies(std::list<Enemy*> _enemies)
{
}

