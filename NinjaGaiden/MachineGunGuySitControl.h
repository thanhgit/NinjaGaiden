#ifndef MACHINE_GUN_GUY_SIT_CONTROL
#define MACHINE_GUN_GUY_SIT_CONTROL

#include"MachineGunGuySitState.h"
#include"MachineGunGuySitGraphics.h"
#include"Box.h"
class MachineGunGuySitControl
{
public:
	MachineGunGuySitControl(MachineGunGuySitGraphics* _graphics, MachineGunGuySitState* machineGunGuySitState, Box* machineGunGuySit);
	MachineGunGuySitControl(MachineGunGuySitState* machineGunGuySitState, Box* machineGunGuySit);
	~MachineGunGuySitControl();
	void changeState(MachineGunGuySitState* machineGunGuySitState, Box* machineGunGuySit);
	MachineGunGuySitState* getState();
	bool SameType(MachineGunGuySitState* _state);

	// run
	int indexRun;

private:
	MachineGunGuySitState* state;
	Box* machineGunGuySit;

	MachineGunGuySitGraphics* graphics;

};

#endif
