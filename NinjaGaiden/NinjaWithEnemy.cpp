#include"NinjaWithEnemy.h"
#include"Collision.h"

NinjaWithEnemy::NinjaWithEnemy(Ninja * _ninja)
{
	this->ninja = _ninja;
}

NinjaWithEnemy::~NinjaWithEnemy()
{
}

void NinjaWithEnemy::NinjaInteractEnemy()
{
	if (this->ninja->GetHurt()->GetBody()->GetX() == -100) {
		return;
	}

	Collision* collisionHurtEnemy = new Collision(this->ninja->GetHurt()->GetBody());
	std::list<Enemy*>::iterator obj;
	for (obj = this->enemies.begin(); obj != this->enemies.end(); obj++) {
		collisionHurtEnemy->collision((*obj)->GetBody());
		float time = collisionHurtEnemy->GetCollisonTime();

		if (collisionHurtEnemy->GetDirection() != NONE) {
			(*obj)->Dead();
		}
	}
}

void NinjaWithEnemy::EnemyInteractNinja()
{
	std::list<Enemy*>::iterator obj;
	for (obj = this->enemies.begin(); obj != this->enemies.end(); obj++) {
		Collision* collisionEnemy = new Collision((*obj)->GetBody());
		collisionEnemy->collision(this->ninja->GetBody());
		float time = collisionEnemy->GetCollisonTime();

		if (collisionEnemy->GetDirection() != NONE) {
			ninja->Dead();
		}
	}
}

void NinjaWithEnemy::interact()
{
	NinjaInteractEnemy();
	EnemyInteractNinja();
}
