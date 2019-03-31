#ifndef BIRD_BROWN_RUN_LEFT
#define BIRD_BROWN_RUN_LEFT
#include"BirdBrownState.h"
#include"BirdBrownGraphics.h"
class BirdBrownRunLeft : public BirdBrownState
{
public:
	BirdBrownRunLeft() {}
	BirdBrownRunLeft(BirdBrownGraphics* _graphics);
	~BirdBrownRunLeft();
	void update(Box* birdBrown);
private:
	BirdBrownGraphics * graphics;
};



#endif
