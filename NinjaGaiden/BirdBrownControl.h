#ifndef BIRD_BROWN_CONTROL
#define BIRD_BROWN_CONTROL

#include"BirdBrownState.h"
#include"BirdBrownGraphics.h"
#include"Box.h"
class BirdBrownControl
{
public:
	BirdBrownControl(BirdBrownGraphics* _graphics, BirdBrownState* birdBrownState, Box* birdBrown);
	BirdBrownControl(BirdBrownState* birdBrownState, Box* birdBrown);
	~BirdBrownControl();
	void changeState(BirdBrownState* birdBrownState, Box* birdBrown);
	BirdBrownState* getState();
	bool SameType(BirdBrownState* _state);

	// run
	int indexRun;

private:
	BirdBrownState* state;
	Box* birdBrown;

	BirdBrownGraphics* graphics;

};

#endif
