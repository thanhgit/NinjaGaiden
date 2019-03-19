#ifndef SWORD_MAN_STATE_H
#define SWORD_MAN_STATE_H

#include"Box.h"
class SwordManState
{
public:
	SwordManState();
	~SwordManState();
	virtual void update(Box*) = 0;

};

#endif
