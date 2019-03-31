#ifndef SWORD_MAN_RUN_RIGHT
#define SWORD_MAN_RUN_RIGHT
#include"SwordManState.h"
#include"SwordManGraphics.h"
class SwordManRunRight : public SwordManState
{
public:
	SwordManRunRight() {}
	SwordManRunRight(SwordManGraphics*);
	~SwordManRunRight();
	void update(Box* swordMan);
private:
	SwordManGraphics* graphics;
};



#endif 
