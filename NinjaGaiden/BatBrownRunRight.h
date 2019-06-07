#ifndef BAT_BROWN_RUN_RIGHT
#define BAT_BROWN_RUN_RIGHT
#include"BatBrownState.h"
#include"BatBrownGraphics.h"

class BatBrownRunRight : public BatBrownState
{
public:
	BatBrownRunRight() {}
	BatBrownRunRight(BatBrownGraphics*);
	~BatBrownRunRight();
	void update(Box* banshee);
private:
	BatBrownGraphics* graphics;
};



#endif 
