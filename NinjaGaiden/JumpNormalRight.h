#ifndef JUMP_NORMAL_RIGHT
#define JUMP_NORMAL_RIGHT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class JumpNormalRight : public NinjaState
{
public:
	JumpNormalRight() {}
	JumpNormalRight(NinjaGraphics*);
	~JumpNormalRight();
	void update(Box* ninja);
private:
	NinjaGraphics* graphics;
};



#endif // !SIMON_Run_Right
