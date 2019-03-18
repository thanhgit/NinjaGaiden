#ifndef JUMP_PARABOL_RIGHT
#define JUMP_PARABOL_RIGHT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class JumpParabolRight : public NinjaState
{
public:
	JumpParabolRight() {}
	JumpParabolRight(NinjaGraphics*);
	~JumpParabolRight();
	void update(Box* ninja);
private:
	NinjaGraphics* graphics;
};



#endif // !SIMON_Run_Right
