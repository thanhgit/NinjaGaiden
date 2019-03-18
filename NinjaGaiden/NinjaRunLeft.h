#ifndef NINJA_RUN_LEFT
#define NINJA_RUN_LEFT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class NinjaRunLeft : public NinjaState
{
public:
	NinjaRunLeft() {}
	NinjaRunLeft(NinjaGraphics* _graphics);
	~NinjaRunLeft();
	void update(Box* ninja);
private:
	NinjaGraphics * graphics;
};



#endif // !SIMON_Run_LEFT
