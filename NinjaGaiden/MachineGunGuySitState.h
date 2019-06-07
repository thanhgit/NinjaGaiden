#ifndef MACHINE_GUN_GUY_SIT_STATE_H
#define MACHINE_GUN_GUY_SIT_STATE_H

#include"Box.h"
class MachineGunGuySitState
{
public:
	MachineGunGuySitState();
	~MachineGunGuySitState();
	virtual void update(Box*) = 0;
};

#endif
