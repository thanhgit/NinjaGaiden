#ifndef SWORD_MAN_RUN_LEFT
#define SWORD_MAN_RUN_LEFT
#include"SwordManState.h"
#include"SwordManGraphics.h"
class SwordManRunLeft : public SwordManState
{
public:
	SwordManRunLeft() {}
	SwordManRunLeft(SwordManGraphics* _graphics);
	~SwordManRunLeft();
	void update(Box* swordMan);
private:
	SwordManGraphics * graphics;
};



#endif // !SIMON_Run_LEFT
