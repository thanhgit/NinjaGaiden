#ifndef SWORD_MAN_STATE_H
#define SWORD_MAN_STATE_H
#include"EnemyState.h"
#include"Box.h"
class SwordManState: public EnemyState
{
public:
	SwordManState();
	~SwordManState();
	virtual void update(Box*) = 0;

};

#endif
