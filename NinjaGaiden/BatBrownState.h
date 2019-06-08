#ifndef BAT_BROWN_STATE_H
#define BAT_BROWN_STATE_H
#include"EnemyState.h"
#include"Box.h"
class BatBrownState: public EnemyState
{
public:
	BatBrownState();
	~BatBrownState();
	virtual void update(Box*) = 0;
};

#endif
