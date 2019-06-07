#ifndef DOG_STATE_H
#define DOG_STATE_H

#include"Box.h"
class DogState
{
public:
	DogState();
	~DogState();
	virtual void update(Box*) = 0;
};

#endif
