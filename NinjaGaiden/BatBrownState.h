#ifndef BAT_BROWN_STATE_H
#define BAT_BROWN_STATE_H

#include"Box.h"
class BatBrownState
{
public:
	BatBrownState();
	~BatBrownState();
	virtual void update(Box*) = 0;
};

#endif
