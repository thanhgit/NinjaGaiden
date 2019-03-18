#ifndef NINJA_STAND_RIGHT
#define NINJA_STAND_RIGHT

#include"NinjaState.h"
#include"NinjaGraphics.h"

class NinjaStandRight : public NinjaState
{
public:
	NinjaStandRight() {}
	NinjaStandRight(NinjaGraphics*);
	~NinjaStandRight();
	void update(Box* ninja);
private:
	NinjaGraphics* graphics;
};


#endif // !SIMON_STAND_RIGHT
