#ifndef MACHINE_GUN_GUY_SIT_SIT_RIGHT
#define MACHINE_GUN_GUY_SIT_SIT_RIGHT
#include"MachineGunGuySitState.h"
#include"MachineGunGuySitGraphics.h"

class MachineGunGuySitSitRight : public MachineGunGuySitState
{
public:
	MachineGunGuySitSitRight() {}
	MachineGunGuySitSitRight(MachineGunGuySitGraphics*);
	~MachineGunGuySitSitRight();
	void update(Box* machineGunGuySit);
private:
	MachineGunGuySitGraphics* graphics;
};



#endif 
