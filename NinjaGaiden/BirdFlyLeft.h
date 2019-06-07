#ifndef BIRD_FLY_LEFT
#define BIRD_FLY_LEFT
#include"BirdState.h"
#include"BirdGraphics.h"
class BirdFlyLeft : public BirdState
{
public:
	BirdFlyLeft() {}
	BirdFlyLeft(BirdGraphics* _graphics);
	~BirdFlyLeft();
	void update(Box* bird);
private:
	BirdGraphics * graphics;
};



#endif
