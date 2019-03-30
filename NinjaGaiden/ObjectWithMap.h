#ifndef OBJECT_WITH_MAP_H
#define OBJECT_WITH_MAP_H
#include"Interaction.h"
#include"Object.h"
#include"Box.h"
#include"Enemy.h"
#include"Ninja.h"

#include<list>
class ObjectWithMap: public Interaction
{
public:
	ObjectWithMap(Ninja* _Ninja);
	~ObjectWithMap();
	void SetRecs(std::list<Box*> _recs) {
		this->recs = _recs;
	}
	void SetEnemies(std::list<Enemy*> _enemies) {
		this->enemies = _enemies;
	}

	void NinjaInteractMap();
	void EnemiesInteractMap();

	void interact();
private:
	Ninja* ninja;
	std::list<Box*> recs;
	std::list<Enemy*> enemies;
};


#endif // !OBJECT_WITH_MAP_H
