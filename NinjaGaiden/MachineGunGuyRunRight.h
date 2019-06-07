#ifndef MACHINE_GUN_GUY_RUN_RIGHT
#define MACHINE_GUN_GUY_RUN_RIGHT
#include"MachineGunGuyState.h"
#include"MachineGunGuyGraphics.h"

class MachineGunGuyRunRight : public MachineGunGuyState
{
public:
	MachineGunGuyRunRight() {}
	MachineGunGuyRunRight(MachineGunGuyGraphics*);
	~MachineGunGuyRunRight();
	void update(Box* machineGunGuy);
private:
	MachineGunGuyGraphics* graphics;
};



#endif 
