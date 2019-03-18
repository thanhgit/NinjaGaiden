#ifndef JUMP_VERTICAL_LEFT
#define JUMP_VERTICAL_LEFT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class JumpVerticalLeft : public NinjaState
{
public:
	JumpVerticalLeft() {}
	JumpVerticalLeft(NinjaGraphics* _graphics);
	~JumpVerticalLeft();
	void update(Box* ninja);
private:
	NinjaGraphics * graphics;
};



#endif // !SIMON_Run_LEFT
