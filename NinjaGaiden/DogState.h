#ifndef DOG_STATE_H
#define DOG_STATE_H
#include"EnemyState.h"
#include"Box.h"
class DogState: public EnemyState
{
public:
	DogState();
	~DogState();
	virtual void update(Box*) = 0;
};

#endif
