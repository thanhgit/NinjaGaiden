#ifndef MACHINE_GUN_GUY_STATE_H
#define MACHINE_GUN_GUY_STATE_H
#include"EnemyState.h"
#include"Box.h"
class MachineGunGuyState: public EnemyState
{
public:
	MachineGunGuyState();
	~MachineGunGuyState();
	virtual void update(Box*) = 0;
};

#endif
