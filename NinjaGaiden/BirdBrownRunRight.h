#ifndef BIRD_BROWN_RUN_RIGHT
#define BIRD_BROWN_RUN_RIGHT
#include"BirdBrownState.h"
#include"BirdBrownGraphics.h"

class BirdBrownRunRight : public BirdBrownState
{
public:
	BirdBrownRunRight() {}
	BirdBrownRunRight(BirdBrownGraphics*);
	~BirdBrownRunRight();
	void update(Box* swordMan);
private:
	BirdBrownGraphics* graphics;
};



#endif 
