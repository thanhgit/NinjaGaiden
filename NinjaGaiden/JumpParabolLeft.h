#ifndef JUMP_PARABOL_LEFT
#define JUMP_PARABOL_LEFT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class JumpParabolLeft : public NinjaState
{
public:
	JumpParabolLeft() {}
	JumpParabolLeft(NinjaGraphics* _graphics);
	~JumpParabolLeft();
	void update(Box* ninja);
private:
	NinjaGraphics * graphics;
};



#endif // !SIMON_Run_LEFT
