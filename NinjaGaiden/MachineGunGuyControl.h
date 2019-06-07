#ifndef MACHINE_GUN_GUY_CONTROL
#define MACHINE_GUN_GUY_CONTROL

#include"MachineGunGuyState.h"
#include"MachineGunGuyGraphics.h"
#include"Box.h"
class MachineGunGuyControl
{
public:
	MachineGunGuyControl(MachineGunGuyGraphics* _graphics, MachineGunGuyState* machineGunGuyState, Box* machineGunGuy);
	MachineGunGuyControl(MachineGunGuyState* machineGunGuyState, Box* machineGunGuy);
	~MachineGunGuyControl();
	void changeState(MachineGunGuyState* machineGunGuyState, Box* machineGunGuy);
	MachineGunGuyState* getState();
	bool SameType(MachineGunGuyState* _state);

	// run
	int indexRun;

private:
	MachineGunGuyState* state;
	Box* machineGunGuy;

	MachineGunGuyGraphics* graphics;

};

#endif
