#ifndef SWORD_MAN_CONTROL
#define SWORD_MAN_CONTROL

#include"SwordManState.h"
#include"SwordManGraphics.h"
#include"Box.h"
class SwordManControl
{
public:
	SwordManControl(SwordManGraphics* _graphics, SwordManState* swordManState, Box* swordMan);
	SwordManControl(SwordManState* swordManState, Box* swordMan);
	~SwordManControl();
	void changeState(SwordManState* swordManState, Box* swordMan);
	SwordManState* getState();
	bool SameType(SwordManState* _state);

	// run
	int indexRun;

	// actack
	int indexActack;

private:
	SwordManState* state;
	Box* swordMan;

	SwordManGraphics* graphics;

};

#endif
