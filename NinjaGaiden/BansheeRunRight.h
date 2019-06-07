#ifndef BANSHEE_RUN_RIGHT
#define BANSHEE_RUN_RIGHT
#include"BansheeState.h"
#include"BansheeGraphics.h"

class BansheeRunRight : public BansheeState
{
public:
	BansheeRunRight() {}
	BansheeRunRight(BansheeGraphics*);
	~BansheeRunRight();
	void update(Box* banshee);
private:
	BansheeGraphics* graphics;
};



#endif 
