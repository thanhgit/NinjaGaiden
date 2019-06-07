#ifndef BANSHEE_STATE_H
#define BANSHEE_STATE_H

#include"Box.h"
class BansheeState
{
public:
	BansheeState();
	~BansheeState();
	virtual void update(Box*) = 0;
};

#endif
