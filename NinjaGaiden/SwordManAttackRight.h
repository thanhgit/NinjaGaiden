#ifndef SWORD_MAN_ACTACK_RIGHT
#define SWORD_MAN_ACTACK_RIGHT
#include"SwordManState.h"
#include"SwordManGraphics.h"
class SwordManAttackRight : public SwordManState
{
public:
	SwordManAttackRight() {}
	SwordManAttackRight(SwordManGraphics*);
	~SwordManAttackRight();
	void update(Box* swordMan);
private:
	SwordManGraphics* graphics;
};



#endif // !SIMON_Actack_Right
