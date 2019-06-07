#ifndef BIRD_STATE_H
#define BIRD_STATE_H

#include"Box.h"
class BirdState
{
public:
	BirdState();
	~BirdState();
	virtual void update(Box*) = 0;
};

#endif
