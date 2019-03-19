#ifndef SWORD_MAN_ACTACK_LEFT
#define SWORD_MAN_ACTACK_LEFT
#include"SwordManState.h"
#include"SwordManGraphics.h"
class SwordManAttackLeft : public SwordManState
{
public:
	SwordManAttackLeft() {}
	SwordManAttackLeft(SwordManGraphics* _graphics);
	~SwordManAttackLeft();
	void update(Box* swordMan);
private:
	SwordManGraphics * graphics;
};



#endif 
