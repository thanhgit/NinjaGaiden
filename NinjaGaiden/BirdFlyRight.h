#ifndef BIRD_FLY_RIGHT
#define BIRD_FLY_RIGHT
#include"BirdState.h"
#include"BirdGraphics.h"

class BirdFlyRight : public BirdState
{
public:
	BirdFlyRight() {}
	BirdFlyRight(BirdGraphics*);
	~BirdFlyRight();
	void update(Box* bird);
private:
	BirdGraphics* graphics;
};



#endif 
