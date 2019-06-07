#ifndef BANSHEE_CONTROL
#define BANSHEE_CONTROL

#include"BansheeState.h"
#include"BansheeGraphics.h"
#include"Box.h"
class BansheeControl
{
public:
	BansheeControl(BansheeGraphics* _graphics, BansheeState* bansheeState, Box* banshee);
	BansheeControl(BansheeState* bansheeState, Box* banshee);
	~BansheeControl();
	void changeState(BansheeState* bansheeState, Box* banshee);
	BansheeState* getState();
	bool SameType(BansheeState* _state);

	// run
	int indexRun;

private:
	BansheeState* state;
	Box* banshee;

	BansheeGraphics* graphics;

};

#endif
