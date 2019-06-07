#ifndef MACHINE_GUN_GUY_STATE_H
#define MACHINE_GUN_GUY_STATE_H

#include"Box.h"
class MachineGunGuyState
{
public:
	MachineGunGuyState();
	~MachineGunGuyState();
	virtual void update(Box*) = 0;
};

#endif
