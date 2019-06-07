#ifndef BOSS3_CONTROL
#define BOSS3_CONTROL

#include"Boss3State.h"
#include"Boss3Graphics.h"
#include"Box.h"
class Boss3Control
{
public:
	Boss3Control(Boss3Graphics* _graphics, Boss3State* boss3State, Box* boss3);
	Boss3Control(Boss3State* boss3State, Box* boss3);
	~Boss3Control();
	void changeState(Boss3State* boss3State, Box* boss3);
	Boss3State* getState();
	bool SameType(Boss3State* _state);

	// run
	int indexJump;

private:
	Boss3State* state;
	Box* boss3;

	Boss3Graphics* graphics;

};

#endif
