#ifndef OBJECT_WITH_MAP_H
#define OBJECT_WITH_MAP_H
#include"Interaction.h"
#include"Object.h"
#include"Box.h"
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
	void SetObjs(std::list<Object*> _objs) {
		this->objs = _objs;
	}

	void NinjaInteractMap();

	void interact();
private:
	Ninja* ninja;
	std::list<Box*> recs;
	std::list<Object*> objs;
};


#endif // !OBJECT_WITH_MAP_H
