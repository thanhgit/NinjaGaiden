#ifndef NINJA_CONTROL
#define NINJA_CONTROL

#include"NinjaState.h"
#include"NinjaGraphics.h"
#include"Box.h"
class NinjaControl
{
public:
	NinjaControl(NinjaGraphics* _graphics, NinjaState* ninjaState, Box* ninja);
	NinjaControl(NinjaState* ninjaState, Box* ninja);
	~NinjaControl();
	void changeState(NinjaState* ninjaState, Box* ninja);
	NinjaState* getState();

	// run
	int indexRun;

	// actack
	int indexActack;

	// jump
	int indexJumpVertical;
	int indexJumpParabol;

private:
	bool SameType(NinjaState* _state);
	NinjaState* state;
	Box* ninja;

	NinjaGraphics* graphics;
	
};

#endif // !SIMON_CONTROL_H
