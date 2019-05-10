#ifndef JUMP_NORMAL_LEFT
#define JUMP_NORMAL_LEFT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class JumpNormalLeft : public NinjaState
{
public:
	JumpNormalLeft() {}
	JumpNormalLeft(NinjaGraphics* _graphics);
	~JumpNormalLeft();
	void update(Box* ninja);
private:
	NinjaGraphics * graphics;
};



#endif // !SIMON_Run_LEFT
