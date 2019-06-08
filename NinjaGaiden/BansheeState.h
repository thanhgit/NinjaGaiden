#ifndef BANSHEE_STATE_H
#define BANSHEE_STATE_H
#include"EnemyState.h"
#include"Box.h"
class BansheeState: public EnemyState
{
public:
	BansheeState();
	~BansheeState();
	virtual void update(Box*) = 0;
};

#endif
