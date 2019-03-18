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
		this->objWithMap->SetRecs(_recs);
	}
private:
	ObjectWithMap* objWithMap;

	Ninja* ninja;
};


#endif // !PHYSICAL_INTERACTION_H
