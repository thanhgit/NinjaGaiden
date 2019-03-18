#ifndef NINJA_ACTACK_LEFT
#define NINJA_ACTACK_LEFT
#include"NinjaState.h"
#include"NinjaGraphics.h"
class NinjaActackLeft : public NinjaState
{
public:
	NinjaActackLeft() {}
	NinjaActackLeft(NinjaGraphics* _graphics);
	~NinjaActackLeft();
	void update(Box* ninja);
private:
	NinjaGraphics * graphics;
};



#endif // !NINJA_Actack_LEFT
