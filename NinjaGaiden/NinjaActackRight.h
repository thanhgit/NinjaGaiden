#ifndef NINJA_ACTACK_RIGHT
#define NINJA_ACTACK_RIGHT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class NinjaActackRight : public NinjaState
{
public:
	NinjaActackRight() {}
	NinjaActackRight(NinjaGraphics*);
	~NinjaActackRight();
	void update(Box* ninja);
private:
	NinjaGraphics* graphics;
};



#endif // !SIMON_Actack_Right
