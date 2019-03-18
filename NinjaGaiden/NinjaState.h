#ifndef NINJA_STATE_H
#define NINJA_STATE_H

#include"Box.h"
class NinjaState
{
public:
	NinjaState();
	~NinjaState();
	virtual void update(Box*) = 0;

};

#endif // !SIMON_STATE_H
