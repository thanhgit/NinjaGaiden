#ifndef JUMP_VERTICAL_RIGHT
#define JUMP_VERTICAL_RIGHT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class JumpVerticalRight : public NinjaState
{
public:
	JumpVerticalRight() {}
	JumpVerticalRight(NinjaGraphics*);
	~JumpVerticalRight();
	void update(Box* ninja);
private:
	NinjaGraphics* graphics;
};



#endif // !SIMON_Run_Right
