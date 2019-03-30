#ifndef PHYSICAL_INTERACTION_H
#define PHYSICAL_INTERACTION_H
#include"ObjectWithMap.h"
#include"Box.h"
#include"Ninja.h"
#include"Object.h"
#include"Enemy.h"
#include<list>
class PhysicalInteraction
{
public:
	PhysicalInteraction(Ninja* _ninja);
	~PhysicalInteraction();
	void update();
	void SetEnemies(std::list<Enemy*> _enemies);
	void SetRecs(std::list<Box*> _recs) {
		this->ninjaWithMap->SetRecs(_recs);
	}
private:
	ObjectWithMap* ninjaWithMap;



	Ninja* ninja;
	std::list<Enemy*> enemies;
};


#endif // !PHYSICAL_INTERACTION_H
