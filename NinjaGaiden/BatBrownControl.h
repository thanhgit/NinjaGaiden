#ifndef BAT_BROWN_CONTROL
#define BAT_BROWN_CONTROL

#include"BatBrownState.h"
#include"BatBrownGraphics.h"
#include"Box.h"
class BatBrownControl
{
public:
	BatBrownControl(BatBrownGraphics* _graphics, BatBrownState* batBrownState, Box* batBrown);
	BatBrownControl(BatBrownState* batBrownState, Box* batBrown);
	~BatBrownControl();
	void changeState(BatBrownState* batBrownState, Box* batBrown);
	BatBrownState* getState();
	bool SameType(BatBrownState* _state);

	// run
	int indexRun;

private:
	BatBrownState* state;
	Box* batBrown;

	BatBrownGraphics* graphics;

};

#endif
