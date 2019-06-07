#ifndef BIRD_CONTROL
#define BIRD_CONTROL

#include"BirdState.h"
#include"BirdGraphics.h"
#include"Box.h"
class BirdControl
{
public:
	BirdControl(BirdGraphics* _graphics, BirdState* birdState, Box* bird);
	BirdControl(BirdState* birdState, Box* bird);
	~BirdControl();
	void changeState(BirdState* birdState, Box* bird);
	BirdState* getState();
	bool SameType(BirdState* _state);

	// run
	int indexFly;

private:
	BirdState* state;
	Box* bird;

	BirdGraphics* graphics;

};

#endif
