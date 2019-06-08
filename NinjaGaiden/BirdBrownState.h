#ifndef BIRD_BROWN_STATE_H
#define BIRD_BROWN_STATE_H
#include"EnemyState.h"
#include"Box.h"
class BirdBrownState: public EnemyState
{
public:
	BirdBrownState();
	~BirdBrownState();
	virtual void update(Box*) = 0;
};

#endif
