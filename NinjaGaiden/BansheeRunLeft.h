#ifndef BANSHEE_RUN_LEFT
#define BANSHEE_RUN_LEFT
#include"BansheeState.h"
#include"BansheeGraphics.h"
class BansheeRunLeft : public BansheeState
{
public:
	BansheeRunLeft() {}
	BansheeRunLeft(BansheeGraphics* _graphics);
	~BansheeRunLeft();
	void update(Box* banshee);
private:
	BansheeGraphics * graphics;
};



#endif
