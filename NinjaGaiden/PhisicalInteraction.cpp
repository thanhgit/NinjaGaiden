#include"PhysicalInteraction.h"

PhysicalInteraction::PhysicalInteraction(Ninja * _ninja)
{
	this->ninja = _ninja;
	this->objWithMap = new ObjectWithMap(this->ninja);
	this->ninjaWithEnemy = new NinjaWithEnemy(this->ninja);
}

PhysicalInteraction::~PhysicalInteraction()
{
}

void PhysicalInteraction::update()
{
	this->objWithMap->interact();
	this->ninjaWithEnemy->interact();
}

void PhysicalInteraction::SetEnemies(std::list<Enemy*> _enemies)
{
	this->enemies = _enemies;
	this->objWithMap->SetEnemies(_enemies);
	this->ninjaWithEnemy->SetEnemies(_enemies);
}

