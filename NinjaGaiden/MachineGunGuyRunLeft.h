#ifndef MACHINE_GUN_GUY_RUN_LEFT
#define MACHINE_GUN_GUY_RUN_LEFT
#include"MachineGunGuyState.h"
#include"MachineGunGuyGraphics.h"
class MachineGunGuyRunLeft : public MachineGunGuyState
{
public:
	MachineGunGuyRunLeft() {}
	MachineGunGuyRunLeft(MachineGunGuyGraphics* _graphics);
	~MachineGunGuyRunLeft();
	void update(Box* machineGunGuy);
private:
	MachineGunGuyGraphics * graphics;
};



#endif
