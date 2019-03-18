#ifndef NINJA_RUN_RIGHT
#define NINJA_RUN_RIGHT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class NinjaRunRight : public NinjaState
{
public:
	NinjaRunRight() {}
	NinjaRunRight(NinjaGraphics*);
	~NinjaRunRight();
	void update(Box* ninja);
private:
	NinjaGraphics* graphics;
};



#endif // !SIMON_Run_Right
