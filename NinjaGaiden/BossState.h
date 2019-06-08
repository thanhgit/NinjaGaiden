#ifndef BOSS_STATE_H
#define BOSS_STATE_H

#include"Box.h"
class BossState
{
public:
	BossState();
	~BossState();
	virtual void update(Box*) = 0;
};

#endif
