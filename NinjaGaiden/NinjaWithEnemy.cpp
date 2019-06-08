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

	std::list<Enemy*>::iterator obj;
	for (obj = this->enemies.begin(); obj != this->enemies.end(); obj++) {
		Collision* collisionEnemy = new Collision((*obj)->GetBody());
		collisionEnemy->collision(this->ninja->GetHurt()->GetBody());
		float time = collisionEnemy->GetCollisonTime();

		if (collisionEnemy->GetDirection() != NONE) {
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
			this->ninja->SetHP(this->ninja->GetHP() - 1);
		}
	}
}

void NinjaWithEnemy::NinjaInteractBoss()
{
}

void NinjaWithEnemy::BossInteractNinja()
{
}

void NinjaWithEnemy::interact()
{
	NinjaInteractEnemy();
	EnemyInteractNinja();
	NinjaInteractBoss();
	BossInteractNinja();
}
