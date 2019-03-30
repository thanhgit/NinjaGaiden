#include"PhysicalInteraction.h"

PhysicalInteraction::PhysicalInteraction(Ninja * _ninja)
{
	this->ninja = _ninja;
	this->ninjaWithMap = new ObjectWithMap(this->ninja);
}

PhysicalInteraction::~PhysicalInteraction()
{
}

void PhysicalInteraction::update()
{
	this->ninjaWithMap->interact();
}

void PhysicalInteraction::SetEnemies(std::list<Enemy*> _enemies)
{
	this->enemies = _enemies;
	this->ninjaWithMap->SetEnemies(_enemies);
}

