#ifndef NINJA_WITH_ENEMY_H
#define NINJA_WITH_ENEMY_H

#include"Interaction.h"
#include"Object.h"
#include"Box.h"
#include"Enemy.h"
#include"Boss.h"
#include"Ninja.h"

#include<list>
class NinjaWithEnemy: public Interaction
{
public:
	NinjaWithEnemy(Ninja* _ninja);
	~NinjaWithEnemy();
	void SetEnemies(std::list<Enemy*> _enemies) {
		this->enemies = _enemies;
	}
	void SetBosses(std::list<Boss*> _bosses) {
		this->bosses = _bosses;
	}
	void NinjaInteractEnemy();
	void EnemyInteractNinja();

	void NinjaInteractBoss();
	void BossInteractNinja();
	void interact();
private:
	Ninja* ninja;
	std::list<Enemy*> enemies;
	std::list<Boss*> bosses;
};


#endif // !NINJA_WITH_ENEMY_H
