#ifndef NINJA_ACTACK_LEFT
#define NINJA_ACTACK_LEFT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class NinjaAttackLeft : public NinjaState
{
public:
	NinjaAttackLeft() {}
	NinjaAttackLeft(NinjaGraphics* _graphics);
	~NinjaAttackLeft();
	void update(Box* ninja);
private:
	NinjaGraphics * graphics;
};



#endif 
