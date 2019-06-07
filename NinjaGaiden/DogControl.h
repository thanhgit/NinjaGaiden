#ifndef DOG_CONTROL
#define DOG_CONTROL

#include"DogState.h"
#include"DogGraphics.h"
#include"Box.h"
class DogControl
{
public:
	DogControl(DogGraphics* _graphics, DogState* dogState, Box* dog);
	DogControl(DogState* dogState, Box* dog);
	~DogControl();
	void changeState(DogState* dogState, Box* dog);
	DogState* getState();
	bool SameType(DogState* _state);

	// run
	int indexRun;

private:
	DogState* state;
	Box* dog;

	DogGraphics* graphics;

};

#endif
