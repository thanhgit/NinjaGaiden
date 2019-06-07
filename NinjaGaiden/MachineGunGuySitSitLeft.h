#ifndef MACHINE_GUN_GUY_SIT_SIT_LEFT
#define MACHINE_GUN_GUY_SIT_SIT_LEFT
#include"MachineGunGuySitState.h"
#include"MachineGunGuySitGraphics.h"
class MachineGunGuySitSitLeft : public MachineGunGuySitState
{
public:
	MachineGunGuySitSitLeft() {}
	MachineGunGuySitSitLeft(MachineGunGuySitGraphics* _graphics);
	~MachineGunGuySitSitLeft();
	void update(Box* machineGunGuySit);
private:
	MachineGunGuySitGraphics * graphics;
};



#endif
