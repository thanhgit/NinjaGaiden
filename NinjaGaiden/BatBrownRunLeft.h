#ifndef BAT_BROW_RUN_LEFT
#define BAT_BROW_RUN_LEFT
#include"BatBrownState.h"
#include"BatBrownGraphics.h"
class BatBrownRunLeft : public BatBrownState
{
public:
	BatBrownRunLeft() {}
	BatBrownRunLeft(BatBrownGraphics* _graphics);
	~BatBrownRunLeft();
	void update(Box* batBrown);
private:
	BatBrownGraphics * graphics;
};



#endif
