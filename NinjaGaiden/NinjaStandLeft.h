#ifndef NINJA_STAND_LEFT
#define NINJA_STAND_LEFT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class NinjaStandLeft : public NinjaState
{
public:
	NinjaStandLeft() {}
	NinjaStandLeft(NinjaGraphics*);
	~NinjaStandLeft();
	void update(Box* ninja);
private:
	NinjaGraphics* graphics;
};


#endif // !SIMON_STAND_LEFT
