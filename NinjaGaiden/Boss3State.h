#ifndef BOSS3_STATE_H
#define BOSS3_STATE_H
#include"BossState.h"
#include"Box.h"
class Boss3State: public BossState
{
public:
	Boss3State();
	~Boss3State();
	virtual void update(Box*) = 0;
};

#endif
