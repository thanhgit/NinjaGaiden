#ifndef NINJA_ACTACK_RIGHT
#define NINJA_ACTACK_RIGHT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class NinjaAttackRight : public NinjaState
{
public:
	NinjaAttackRight() {}
	NinjaAttackRight(NinjaGraphics*);
	~NinjaAttackRight();
	void update(Box* ninja);
private:
	NinjaGraphics* graphics;
};



#endif
